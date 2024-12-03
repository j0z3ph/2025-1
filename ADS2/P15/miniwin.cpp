/**
 * @file miniwin.c
 * @author Jose Luis Cruz (j0z3ph@gmail.com)
 * @brief Un mini-conjunto de funciones para abrir una ventana, pintar en
 *    ella y detectar la presión de algunas teclas. Básicamente para hacer
 *    juegos sencillos.
 *    Basado en el trabajo de Pau Fernández.
 * @version 0.2.2
 * @date 2023-12-09
 *
 *  MiniWin: Un mini-conjunto de funciones para abrir una ventana, pintar en
 *    ella y detectar la presión de algunas teclas. Básicamente para hacer
 *    juegos sencillos.
 *
 *  (c) Pau Fernández, licencia MIT: http://es.wikipedia.org/wiki/MIT_License
 *
 * Git original: https://github.com/pauek/MiniWin
 * Git: https://github.com/j0z3ph/Miniwin
 */

#if defined(_WIN32)

// Windows ////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <sstream>
#include <queue>
#include <cmath>
#include <process.h>
#include <windows.h>
#include <windowsx.h>

#define MINIWIN_SOURCE
#include "miniwin.hpp"

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

char szClassName[] = "MiniWin";

// Variables globales >~< (ya se, ya se) //////////////////////////////////////////////////////////

HWND hWnd;                 // ventana principal
HBITMAP hBitmap;           // bitmap para pintar off-screen
int iWidth = 400;          // ancho de la ventana
int iHeight = 300;         // alto de la ventana
HDC hDCMem = NULL;         // Device Context en memoria
std::queue<int> _teclas;   // cola de teclas
std::queue<int> _teclasUp; // cola de teclas 2
bool _raton_dentro;        // el raton est� dentro del 'client area'
int _xraton, _yraton;      // posicion del raton
bool _bot_izq, _bot_der;   // botones izquierdo y derecho
WINDOWPLACEMENT g_wpPrev;  // respaldo de la posicion de la ventana antes de ir a fullscreen
int iWidthPrev;            // respaldo del ancho de la ventana antes de ir a fullscreen
int iHeightPrev;           // respaldo del alto de la ventana antes de ir a fullscreen
bool _fullscreen = false;  // modo fullscreen
////////////////////////////////////////////////////////////////////////////////

std::ostream &log()
{
#if defined(DEBUG)
    static std::ofstream _log("log.txt");
#else
    static std::stringstream _log;
    _log.str(""); // lo borra
#endif
    return _log;
}

VOID Thread(PVOID pvoid)
{
    Sleep(50); // FIXME
    _main_();
}

void maybe_call_main()
{
    static bool started = false;
    if (!started)
    {
        _beginthread(Thread, 0, NULL); // Llama a 'main' (realmente  '_main_')
        started = true;
    }
}

void frame_real(int w, int h, int &rw, int &rh)
{
    RECT frame = {0, 0, w, h};
    AdjustWindowRect(&frame, WS_OVERLAPPEDWINDOW, FALSE);
    rw = frame.right - frame.left;
    rh = frame.bottom - frame.top;
}

void newMemDC(int w, int h)
{
    if (hDCMem != NULL)
    {
        DeleteObject(hBitmap);
        DeleteDC(hDCMem);
    }
    log() << "New MemDC\n";
    HDC hDC = GetDC(hWnd);
    hDCMem = CreateCompatibleDC(hDC);
    hBitmap = CreateCompatibleBitmap(hDC, w, h);
    SelectObject(hDCMem, hBitmap);
    SetBkMode(hDCMem, TRANSPARENT);
}

int WINAPI WinMain(HINSTANCE hThisInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpszArgument,
                   int nFunsterStil)
{
    static WNDCLASSEX wincl;
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof(WNDCLASSEX);

    wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

    if (!RegisterClassEx(&wincl))
        return 0;

    int w, h, xPos, yPos;
    frame_real(iWidth, iHeight, w, h);

    // Centra la ventana
    xPos = (GetSystemMetrics(SM_CXSCREEN) - w) / 2;
    yPos = (GetSystemMetrics(SM_CYSCREEN) - h) / 2;

    hWnd = CreateWindowEx(
        0,                                     /* Extended possibilites for variation */
        szClassName,                           /* Classname */
        _MINIWIN_VERSION_,                     /* Title Text */
        WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX, /* no resizable window */
        xPos,                                  /* The window position  */
        yPos,                                  /* in x and y coordinates */
        w,                                     /* The programs width */
        h,                                     /* and height in pixels */
        HWND_DESKTOP,                          /* The window is a child-window to desktop */
        NULL,                                  /* No menu */
        hThisInstance,                         /* Program Instance handler */
        NULL                                   /* No Window Creation data */
    );

    hBitmap = NULL;

    ShowWindow(hWnd, nFunsterStil);

    MSG messages;
    while (GetMessage(&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd,
                                 UINT message,
                                 WPARAM wParam,
                                 LPARAM lParam)
{
    switch (message)
    {
    case WM_SIZE:
    {
        log() << "WM_SIZE\n";
        RECT R;
        GetClientRect(hWnd, &R);
        int w = R.right - R.left;
        int h = R.bottom - R.top;
        log() << w << ' ' << h << ' ' << '\n';
        if (w == 0 && h == 0)
            break; // Al minimizar envia WM_SIZE(0,0)

        if (hDCMem == NULL || w != iWidth || h != iHeight)
        {
            newMemDC(w, h);
            maybe_call_main();
        }
        break;
    }
    case WM_SIZING:
    {
        RECT *pRECT = (RECT *)lParam;
        log() << pRECT->top << ' ' << pRECT->left << ' '
              << pRECT->bottom << ' ' << pRECT->right << '\n';
        log() << iHeight << '\n';
        int w, h;
        frame_real(iWidth, iHeight, w, h);
        switch (wParam)
        {
        case WMSZ_BOTTOM:
            pRECT->bottom = pRECT->top + h;
            break;
        case WMSZ_TOP:
            pRECT->top = pRECT->bottom - h;
            break;
        case WMSZ_RIGHT:
            pRECT->right = pRECT->left + w;
            break;
        case WMSZ_LEFT:
            pRECT->left = pRECT->right - w;
            break;
        case WMSZ_TOPLEFT:
            pRECT->top = pRECT->bottom - h;
            pRECT->left = pRECT->right - w;
            break;
        case WMSZ_TOPRIGHT:
            pRECT->top = pRECT->bottom - h;
            pRECT->right = pRECT->left + w;
            break;
        case WMSZ_BOTTOMLEFT:
            pRECT->bottom = pRECT->top + h;
            pRECT->left = pRECT->right - w;
            break;
        case WMSZ_BOTTOMRIGHT:
            pRECT->bottom = pRECT->top + h;
            pRECT->right = pRECT->left + w;
            break;
        }

        return TRUE;
    }
    case WM_PAINT:
    {
        log() << "WM_PAINT\n";
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        SelectObject(hDCMem, hBitmap);
        if (hBitmap != NULL)
        {
            BitBlt(hdc, 0, 0, iWidth, iHeight, hDCMem, 0, 0, SRCCOPY);
        }
        EndPaint(hWnd, &ps);
        break;
    }
    case WM_MOUSEMOVE:
    {
        log() << "WM_MOUSEMOVE\n";
        _raton_dentro = true;
        _xraton = GET_X_LPARAM(lParam);
        _yraton = GET_Y_LPARAM(lParam);
        _bot_izq = wParam & MK_LBUTTON;
        _bot_der = wParam & MK_RBUTTON;
        break;
    }
    case WM_MOUSELEAVE:
    {
        _raton_dentro = false;
        break;
    }
    case WM_LBUTTONDOWN:
    {
        _bot_izq = true;
        break;
    }
    case WM_LBUTTONUP:
    {
        _bot_izq = false;
        break;
    }
    case WM_RBUTTONDOWN:
    {
        _bot_der = true;
        break;
    }
    case WM_RBUTTONUP:
    {
        _bot_der = false;
        break;
    }
    case WM_KEYDOWN:
    {
        bool push_it = false;

        // Escape
        push_it |= (wParam == VK_ESCAPE);

        // Flechas
        push_it |= (wParam == VK_LEFT ||
                    wParam == VK_RIGHT ||
                    wParam == VK_UP ||
                    wParam == VK_DOWN);

        // Barra espaciadora
        push_it |= (wParam == VK_SPACE);

        push_it |= (wParam == VK_RETURN);

        // N�meros 0-9
        push_it |= (wParam >= 48 && wParam <= 57);

        // Letras A-Z
        push_it |= (wParam >= 65 && wParam <= 90);

        // Teclas de funci�n
        for (unsigned int i = 0; i < 10; i++)
        {
            push_it |= (wParam == (VK_F1 + i));
        }

        if (push_it)
            _teclas.push(wParam);

        break;
    }
    case WM_KEYUP:
    {
        bool push_it = false;

        // Escape
        push_it |= (wParam == VK_ESCAPE);

        // Flechas
        push_it |= (wParam == VK_LEFT ||
                    wParam == VK_RIGHT ||
                    wParam == VK_UP ||
                    wParam == VK_DOWN);

        // Barra espaciadora
        push_it |= (wParam == VK_SPACE);

        push_it |= (wParam == VK_RETURN);

        // N�meros 0-9
        push_it |= (wParam >= 48 && wParam <= 57);

        // Letras A-Z
        push_it |= (wParam >= 65 && wParam <= 90);

        // Teclas de funci�n
        for (unsigned int i = 0; i < 10; i++)
        {
            push_it |= (wParam == (VK_F1 + i));
        }

        if (push_it)
            _teclasUp.push(wParam);

        break;
    }
    case WM_DESTROY:
    {
        DeleteObject(hBitmap);
        DeleteDC(hDCMem);
        PostQuitMessage(0);
        break;
    }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
//   Funciones del API
//
////////////////////////////////////////////////////////////////////////////////

COLORREF _color = RGB(255, 255, 255);
COLORREF _back_color = RGB(255, 255, 255);

namespace miniwin
{

    MiniWinImage::MiniWinImage(std::string ruta)
    {
        BITMAP bitmap;

        this->_hBitmap = (HBITMAP)LoadImageA(NULL, ruta.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        if (this->_hBitmap == NULL)
        {
            throw "No fue posible cargar la imagen.";
        }
        GetObject(this->_hBitmap, sizeof(bitmap), &bitmap);
        this->_ruta = ruta;
        this->_pos_x = 0;
        this->_pos_y = 0;
        this->_alto = bitmap.bmHeight;
        this->_ancho = bitmap.bmWidth;

        this->_hBitmapMask = NULL;
        this->_ruta_mask = "";
    }

    MiniWinImage::MiniWinImage(std::string ruta, std::string ruta_mask)
    {
        BITMAP bitmap;

        this->_hBitmap = (HBITMAP)LoadImageA(NULL, ruta.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        if (this->_hBitmap == NULL)
        {
            throw "No fue posible cargar la imagen.";
        }
        GetObject(this->_hBitmap, sizeof(bitmap), &bitmap);
        this->_ruta = ruta;
        this->_pos_x = 0;
        this->_pos_y = 0;
        this->_alto = bitmap.bmHeight;
        this->_ancho = bitmap.bmWidth;

        // mask
        this->_hBitmapMask = (HBITMAP)LoadImageA(NULL, ruta_mask.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        if (this->_hBitmapMask == NULL)
        {
            throw "No fue posible cargar la mascara.";
        }
        this->_ruta_mask = ruta_mask;
    }

    MiniWinImage::~MiniWinImage()
    {
        DeleteObject(this->_hBitmap);
        DeleteObject(this->_hBitmapMask);
    }

    HGDIOBJ MiniWinImage::bitmap()
    {
        return this->_hBitmap;
    }

    HGDIOBJ MiniWinImage::bitmap_mask()
    {
        return this->_hBitmapMask;
    }

    void MiniWinImage::posX(int x)
    {
        this->_pos_x = x;
    }
    void MiniWinImage::posY(int y)
    {
        this->_pos_y = y;
    }

    int MiniWinImage::posX()
    {
        return this->_pos_x;
    }
    int MiniWinImage::posY()
    {
        return this->_pos_y;
    }

    long MiniWinImage::ancho()
    {
        return this->_ancho;
    }
    long MiniWinImage::alto()
    {
        return this->_alto;
    }

    std::string MiniWinImage::ruta()
    {
        return this->_ruta;
    }

    int tecla()
    {
        if (_teclas.empty())
            return NINGUNA;

        int ret = _teclas.front();
        _teclas.pop();

        return ret;
    }

    int teclaDown()
    {
        return tecla();
    }

    int teclaUp()
    {
        while (!_teclas.empty())
            _teclas.pop();

        if (_teclasUp.empty())
            return NINGUNA;

        int ret = _teclasUp.front();
        _teclasUp.pop();
        
        return ret;
    }

    bool raton(float &x, float &y)
    {
        if (!_raton_dentro)
        {
            return false;
        }
        x = _xraton;
        y = _yraton;
        return true;
    }

    bool raton_dentro()
    {
        return _raton_dentro;
    }

    float raton_x()
    {
        return _xraton;
    }

    float raton_y()
    {
        return _yraton;
    }

    void raton_botones(bool &izq, bool &der)
    {
        izq = _bot_izq;
        der = _bot_der;
    }

    bool raton_boton_izq()
    {
        return _bot_izq;
    }

    bool raton_boton_der()
    {
        return _bot_der;
    }

    void espera(int miliseg)
    {
        Sleep(miliseg);
    }

    void mensaje(std::string msj)
    {
        MessageBox(hWnd, msj.c_str(), "Mensaje...", MB_OK);
    }

    void mensaje(std::string msj, std::string titulo)
    {
        MessageBox(hWnd, msj.c_str(), titulo.c_str(), MB_OK);
    }

    bool pregunta(std::string msj)
    {
        return MessageBox(hWnd, msj.c_str(), "Pregunta...", MB_OKCANCEL) == IDOK;
    }

    bool pregunta(std::string msj, std::string titulo)
    {
        return MessageBox(hWnd, msj.c_str(), titulo.c_str(), MB_OKCANCEL) == IDOK;
    }

    void borra()
    {
        RECT R;
        SetRect(&R, 0, 0, iWidth, iHeight);
        HBRUSH hBrush = CreateSolidBrush(_back_color);
        FillRect(hDCMem, &R, hBrush);
        DeleteObject(hBrush);
    }

    void refresca()
    {
        InvalidateRect(hWnd, NULL, FALSE);
    }

    void punto(float x, float y)
    {
        SetPixel(hDCMem, int(x), int(y), _color);
    }

    void linea(float x_ini, float y_ini, float x_fin, float y_fin)
    {
        BeginPath(hDCMem);
        MoveToEx(hDCMem, int(x_ini), int(y_ini), NULL);
        LineTo(hDCMem, int(x_fin), int(y_fin));
        EndPath(hDCMem);
        HPEN hPen = CreatePen(PS_SOLID, 1, _color);
        SelectObject(hDCMem, hPen);
        StrokePath(hDCMem);
        DeleteObject(hPen);
    }

    inline void _rect(float izq, float arr, float der, float aba)
    {
        BeginPath(hDCMem);
        MoveToEx(hDCMem, int(izq), int(arr), NULL);
        LineTo(hDCMem, int(izq), int(aba));
        LineTo(hDCMem, int(der), int(aba));
        LineTo(hDCMem, int(der), int(arr));
        LineTo(hDCMem, int(izq), int(arr));
        EndPath(hDCMem);
    }

    void rectangulo(float izq, float arr, float der, float aba)
    {
        HPEN hPen = CreatePen(PS_SOLID, 1, _color);
        HGDIOBJ orig = SelectObject(hDCMem, hPen);
        _rect(izq, arr, der, aba);
        StrokePath(hDCMem);
        SelectObject(hDCMem, orig);
        DeleteObject(hPen);
    }

    void rectangulo_lleno(float izq, float arr, float der, float aba)
    {
        HBRUSH hBrush = CreateSolidBrush(_color);
        HGDIOBJ orig = SelectObject(hDCMem, hBrush);
        _rect(izq, arr, der, aba);
        FillPath(hDCMem);
        SelectObject(hDCMem, orig);
        DeleteObject(hBrush);
    }

    inline void _circ(float x_cen, float y_cen, float radio)
    {
        BeginPath(hDCMem);
        Arc(hDCMem, int(x_cen - radio), int(y_cen - radio),
            int(x_cen + radio), int(y_cen + radio),
            int(x_cen - radio), int(y_cen - radio),
            int(x_cen - radio), int(y_cen - radio));
        EndPath(hDCMem);
    }

    void circulo(float x_cen, float y_cen, float radio)
    {
        HPEN hPen = CreatePen(PS_SOLID, 1, _color);
        HGDIOBJ orig = SelectObject(hDCMem, hPen);
        _circ(x_cen, y_cen, radio);
        StrokePath(hDCMem);
        SelectObject(hDCMem, orig);
        DeleteObject(hPen);
    }

    void circulo_lleno(float x_cen, float y_cen, float radio)
    {
        HBRUSH hBrush = CreateSolidBrush(_color);
        HGDIOBJ orig = SelectObject(hDCMem, hBrush);
        _circ(x_cen, y_cen, radio);
        FillPath(hDCMem);
        SelectObject(hDCMem, orig);
        DeleteObject(hBrush);
    }

    void texto(float x, float y, const std::string &texto)
    {
        SetTextColor(hDCMem, _color);
        TextOut(hDCMem, int(x), int(y), texto.c_str(), int(texto.size()));
    }

    void texto(float x, float y, const std::string &texto, int tamanioFuente,
               bool italica, bool negrita, bool subrayada, std::string fuente)
    {
        HFONT hf, hforiginal;
        int peso = FW_NORMAL;
        long lfHeight;
        lfHeight = -MulDiv(tamanioFuente, GetDeviceCaps(hDCMem, LOGPIXELSY), 72);

        if (negrita)
            peso = FW_BOLD;
        hf = CreateFont(tamanioFuente, 0, 0, 0, peso, italica, subrayada, 0, 0, 0, 0, 0, 0, fuente.c_str());
        hforiginal = (HFONT)SelectObject(hDCMem, hf);
        SetTextColor(hDCMem, _color);
        TextOut(hDCMem, (int)x, (int)y, texto.c_str(), texto.length());
        SelectObject(hDCMem, hforiginal);
        DeleteObject(hf);
    }

    void muestraImagen(MiniWinImage &imagen)
    {
        HGDIOBJ oldBitmap;
        BITMAP bitmap;
        HDC imagehdc;

        if (imagen.bitmap_mask() != NULL)
        {
            imagehdc = CreateCompatibleDC(NULL);
            GetObject(imagen.bitmap_mask(), sizeof(bitmap), &bitmap);

            oldBitmap = SelectObject(imagehdc, imagen.bitmap_mask());
            StretchBlt(hDCMem, imagen.posX(), imagen.posY(), imagen.ancho(), imagen.alto(), imagehdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCAND);
            if (imagen.bitmap() != NULL)
            {
                SelectObject(imagehdc, imagen.bitmap());
                StretchBlt(hDCMem, imagen.posX(), imagen.posY(), imagen.ancho(), imagen.alto(), imagehdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCPAINT);
            }
            SelectObject(imagehdc, oldBitmap);
            DeleteObject(imagehdc);
            DeleteObject(oldBitmap);
        }
        else if (imagen.bitmap() != NULL)
        {
            imagehdc = CreateCompatibleDC(NULL);
            GetObject(imagen.bitmap(), sizeof(bitmap), &bitmap);

            oldBitmap = SelectObject(imagehdc, imagen.bitmap());
            StretchBlt(hDCMem, imagen.posX(), imagen.posY(), imagen.ancho(), imagen.alto(), imagehdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
            SelectObject(imagehdc, oldBitmap);
            DeleteObject(imagehdc);
            DeleteObject(oldBitmap);
        }
    }

    static COLORREF _colores[] = {
        RGB(0, 0, 0),       // NEGRO
        RGB(255, 0, 0),     // ROJO
        RGB(0, 255, 0),     // VERDE
        RGB(0, 0, 255),     // AZUL
        RGB(255, 255, 0),   // AMARILLO
        RGB(255, 0, 255),   // MAGENTA
        RGB(0, 255, 255),   // CYAN
        RGB(255, 255, 255), // BLANCO
    };

    void color(Colores c)
    {
        if (c >= 0 && c <= 7)
            _color = _colores[c];
        else
            _color = _colores[0];
    }

    void color_rgb(int r, int g, int b)
    {
        _color = RGB(r < 0 ? 0 : r > 255 ? 255
                                         : r,
                     g < 0 ? 0 : g > 255 ? 255
                                         : g,
                     b < 0 ? 0 : b > 255 ? 255
                                         : b);
    }

    void color_fondo(Colores c)
    {
        if (c >= 0 && c <= 7)
            _back_color = _colores[c];
        else
            _back_color = _colores[0];
    }

    void color_fondo_rgb(int r, int g, int b)
    {
        _back_color = RGB(r < 0 ? 0 : r > 255 ? 255
                                              : r,
                          g < 0 ? 0 : g > 255 ? 255
                                              : g,
                          b < 0 ? 0 : b > 255 ? 255
                                              : b);
    }

    int vancho()
    {
        return iWidth;
    }

    int valto()
    {
        return iHeight;
    }

    void vredimensiona(int ample, int alt)
    {
        iWidth = ample;
        iHeight = alt;
        int w, h;
        int xPos;
        int yPos;

        frame_real(iWidth, iHeight, w, h);

        // Centra la ventana
        xPos = (GetSystemMetrics(SM_CXSCREEN) - w) / 2;
        yPos = (GetSystemMetrics(SM_CYSCREEN) - h) / 2;

        SetWindowPos(hWnd, HWND_TOP, xPos, yPos, w, h, SWP_FRAMECHANGED);
        newMemDC(w, h);
    }

    void fullscreen(bool fullscreenOn)
    {
        DWORD dwStyle = GetWindowLong(hWnd, GWL_STYLE);
        if (fullscreenOn && !_fullscreen)
        {
            MONITORINFO mi = {sizeof(mi)};
            if (GetWindowPlacement(hWnd, &g_wpPrev) &&
                GetMonitorInfo(MonitorFromWindow(hWnd, MONITOR_DEFAULTTOPRIMARY), &mi))
            {
                SetWindowLong(hWnd, GWL_STYLE,
                              dwStyle & ~WS_OVERLAPPEDWINDOW);
                SetWindowPos(hWnd, HWND_TOP,
                             mi.rcMonitor.left, mi.rcMonitor.top,
                             mi.rcMonitor.right - mi.rcMonitor.left,
                             mi.rcMonitor.bottom - mi.rcMonitor.top,
                             SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
                iWidthPrev = iWidth;
                iHeightPrev = iHeight;
                iWidth = mi.rcMonitor.right - mi.rcMonitor.left;
                iHeight = mi.rcMonitor.bottom - mi.rcMonitor.top;
                _fullscreen = true;
                borra();
                refresca();
            }
        }
        else if (!fullscreenOn && _fullscreen)
        {
            SetWindowLong(hWnd, GWL_STYLE,
                          dwStyle | WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX);
            SetWindowPlacement(hWnd, &g_wpPrev);
            iWidth = iWidthPrev;
            iHeight = iHeightPrev;
            _fullscreen = false;
            vredimensiona(iWidth, iHeight);
            borra();
            refresca();
        }
    }

    void ventana(int ancho, int alto)
    {
        vredimensiona(ancho, alto);
    }

    void cierra()
    {
        PostMessage(hWnd, WM_CLOSE, 0, 0);
    }

    void titulo(std::string titulo)
    {
        SetWindowTextA(hWnd, titulo.c_str());
    }

} // namespace miniwin

#else

#error "MiniWin no funciona en esta plataforma"

#endif
