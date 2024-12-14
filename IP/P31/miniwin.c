/**
 * @file miniwin.c
 * @author Jose Luis Cruz (j0z3ph@gmail.com)
 * @brief Traduccion a C de MiniWin. Un mini-conjunto de funciones para abrir una ventana, pintar en
 *    ella y detectar la presión de algunas teclas. Básicamente para hacer
 *    juegos sencillos.
 *    Basado en el trabajo de Pau Fernández.
 * @version 0.2
 * @date 2023-12-09
 *
 *  MiniWin: Un mini-conjunto de funciones para abrir una ventana, pintar en
 *    ella y detectar la presión de algunas teclas. Básicamente para hacer
 *    juegos sencillos.
 *
 *  (c) Pau Fernández, licencia MIT: http://es.wikipedia.org/wiki/MIT_License
 *
 *
 * Git original: https://github.com/pauek/MiniWin
 * Git: https://github.com/j0z3ph/Miniwin
 */

#if defined(_WIN32)

// Windows ////////////////////////////////////////////////////////////////////////////

#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <process.h>
#include <windows.h>
#include <windowsx.h>
#include <stdlib.h>

#define MINIWIN_SOURCE
#include "miniwin.h"

static LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

static char szClassName[] = "MiniWin";

// Variables globales >~< (ya se, ya se) //////////////////////////////////////////////////////////

static HWND hWnd;				// ventana principal
static HBITMAP hBitmap;			// bitmap para pintar off-screen
static int iWidth = 400;		// ancho de la ventana
static int iHeight = 300;		// alto de la ventana
static HDC hDCMem = NULL;		// Device Context en memoria
static bool _raton_dentro;		// el raton est� dentro del 'client area'
static int _xraton, _yraton;	// posicion del raton
static bool _bot_izq, _bot_der; // botones izquierdo y derecho
WINDOWPLACEMENT g_wpPrev;		// respaldo de la posicion de la ventana antes de ir a fullscreen
int iWidthPrev;					// respaldo del ancho de la ventana antes de ir a fullscreen
int iHeightPrev;				// respaldo del alto de la ventana antes de ir a fullscreen
bool _fullscreen = false;		// modo fullscreen

// Queue stuff
static Queue *keyDownQueue = NULL;
static Queue *keyUpQueue = NULL;

void queue_push(Queue **queue, int val)
{
	if (*queue == NULL)
	{
		*queue = (Queue *)malloc(sizeof(Queue));
		(*queue)->head = (Node *)malloc(sizeof(Node));
		(*queue)->head->value = val;
		(*queue)->head->next = NULL;
		(*queue)->tail = (*queue)->head;
	}
	else
	{
		(*queue)->tail->next = (Node *)malloc(sizeof(Node));
		(*queue)->tail = (*queue)->tail->next;
		(*queue)->tail->value = val;
		(*queue)->tail->next = NULL;
	}
}

int queue_front(Queue **queue)
{
	int val = -1;
	if (*queue != NULL)
	{
		val = (*queue)->head->value;
	}

	return val;
}

int queue_pop(Queue **queue)
{
	int val = -1;
	if (*queue != NULL)
	{
		val = (*queue)->head->value;
		Node *tmp = (*queue)->head;
		(*queue)->head = (*queue)->head->next;
		free(tmp);
		if ((*queue)->head == NULL)
		{
			free(*queue);
			*queue = NULL;
		}
	}

	return val;
}

bool queue_empty(Queue **queue)
{
	return *queue == NULL;
}

void queue_clear(Queue **queue)
{
	if (*queue != NULL)
	{
		Queue *q = *queue;
		*queue = NULL;
		Node *tmp;
		while (q->head != NULL)
		{
			tmp = q->head;
			q->head = q->head->next;
			free(tmp);
		}
		free(q);
	}
}

////////////////////////////////////////////////////////////////////////////////

static VOID Thread(PVOID pvoid)
{
	Sleep(50); // FIXME
	_main_();
}

static void maybe_call_main()
{
	static bool started = false;
	if (!started)
	{
		_beginthread(Thread, 0, NULL); // Llama a 'main' (realmente  '_main_')
		started = true;
	}
}

static void frame_real(int w, int h, int *rw, int *rh)
{
	RECT frame = {0, 0, w, h};
	AdjustWindowRect(&frame, WS_OVERLAPPEDWINDOW, FALSE);
	*rw = frame.right - frame.left;
	*rh = frame.bottom - frame.top;
}

static void newMemDC(int w, int h)
{
	if (hDCMem != NULL)
	{
		DeleteObject(hBitmap);
		DeleteDC(hDCMem);
	}
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
	frame_real(iWidth, iHeight, &w, &h);

	// Centra la ventana
	xPos = (GetSystemMetrics(SM_CXSCREEN) - w) / 2;
	yPos = (GetSystemMetrics(SM_CYSCREEN) - h) / 2;

	hWnd = CreateWindowEx(
		0,									   /* Extended possibilites for variation */
		szClassName,						   /* Classname */
		_MINIWIN_VERSION_,					   /* Title Text */
		WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX, /* no resizable window */
		xPos,								   /* The window position  */
		yPos,								   /* in x and y coordinates */
		w,									   /* The programs width */
		h,									   /* and height in pixels */
		HWND_DESKTOP,						   /* The window is a child-window to desktop */
		NULL,								   /* No menu */
		hThisInstance,						   /* Program Instance handler */
		NULL								   /* No Window Creation data */
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

static LRESULT CALLBACK WindowProcedure(HWND hWnd,
										UINT message,
										WPARAM wParam,
										LPARAM lParam)
{
	switch (message)
	{
	case WM_SIZE:
	{
		RECT R;
		GetClientRect(hWnd, &R);
		int w = R.right - R.left;
		int h = R.bottom - R.top;
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
		int w, h;
		frame_real(iWidth, iHeight, &w, &h);
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
			queue_push(&keyDownQueue, wParam);

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
			queue_push(&keyUpQueue, wParam);

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

static COLORREF _color = RGB(255, 255, 255);
static COLORREF _back_color = RGB(255, 255, 255);

int tecla()
{
	if (queue_empty(&keyDownQueue))
		return NINGUNA;

	int ret = queue_pop(&keyDownQueue);
	return ret;
}

int teclaDown()
{
	return tecla();
}

int teclaUp()
{
	queue_clear(&keyDownQueue);

	if (queue_empty(&keyUpQueue))
		return NINGUNA;

	int ret = queue_pop(&keyUpQueue);
	return ret;
}

bool raton(float *x, float *y)
{
	if (!_raton_dentro)
	{
		return false;
	}
	*x = _xraton;
	*y = _yraton;
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

void raton_botones(bool *izq, bool *der)
{
	*izq = _bot_izq;
	*der = _bot_der;
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

void mensaje(const char *msj)
{
	MessageBox(hWnd, msj, "Mensaje...", MB_OK);
}

void mensajeT(const char *msj, const char *titulo)
{
	MessageBox(hWnd, msj, titulo, MB_OK);
}

bool pregunta(const char *msj)
{
	return MessageBox(hWnd, msj, "Pregunta...", MB_OKCANCEL) == IDOK;
}

bool preguntaT(const char *msj, const char *titulo)
{
	return MessageBox(hWnd, msj, titulo, MB_OKCANCEL) == IDOK;
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
	SetPixel(hDCMem, (int)x, (int)y, _color);
}

void linea(float x_ini, float y_ini, float x_fin, float y_fin)
{
	BeginPath(hDCMem);
	MoveToEx(hDCMem, (int)x_ini, (int)y_ini, NULL);
	LineTo(hDCMem, (int)x_fin, (int)y_fin);
	EndPath(hDCMem);
	HPEN hPen = CreatePen(PS_SOLID, 1, _color);
	SelectObject(hDCMem, hPen);
	StrokePath(hDCMem);
	DeleteObject(hPen);
}

static void _rect(float izq, float arr, float der, float aba)
{
	BeginPath(hDCMem);
	MoveToEx(hDCMem, (int)izq, (int)arr, NULL);
	LineTo(hDCMem, (int)izq, (int)aba);
	LineTo(hDCMem, (int)der, (int)aba);
	LineTo(hDCMem, (int)der, (int)arr);
	LineTo(hDCMem, (int)izq, (int)arr);
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

static void _circ(float x_cen, float y_cen, float radio)
{
	BeginPath(hDCMem);
	Arc(hDCMem, (int)(x_cen - radio), (int)(y_cen - radio),
		(int)(x_cen + radio), (int)(y_cen + radio),
		(int)(x_cen - radio), (int)(y_cen - radio),
		(int)(x_cen - radio), (int)(y_cen - radio));
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

void texto(float x, float y, const char *texto)
{
	SetTextColor(hDCMem, _color);
	TextOut(hDCMem, (int)x, (int)y, texto, strlen(texto));
}

void textoExt(float x, float y, const char *texto, int tamanioFuente,
			  bool italica, bool negrita, bool subrayada, const char *fuente)
{
	HFONT hf, hforiginal;
	int peso = FW_NORMAL;
	long lfHeight;
	lfHeight = -MulDiv(tamanioFuente, GetDeviceCaps(hDCMem, LOGPIXELSY), 72);

	if (negrita)
		peso = FW_BOLD;
	hf = CreateFont(tamanioFuente, 0, 0, 0, peso, italica, subrayada, 0, 0, 0, 0, 0, 0, fuente);
	hforiginal = (HFONT)SelectObject(hDCMem, hf);
	SetTextColor(hDCMem, _color);
	TextOut(hDCMem, (int)x, (int)y, texto, strlen(texto));
	SelectObject(hDCMem, hforiginal);
	DeleteObject(hf);
}

MiniWinImage *creaImagenBMP(const char *ruta)
{
	MiniWinImage *image = (MiniWinImage *)malloc(sizeof(MiniWinImage));
	BITMAP bitmap;
	image->ruta[0] = 0;
	image->alto = 0;
	image->ancho = 0;
	image->hBitmap = (HBITMAP)LoadImageA(NULL, ruta, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	if (image->hBitmap != NULL)
	{
		strcpy(image->ruta, ruta);
		GetObject(image->hBitmap, sizeof(bitmap), &bitmap);
		image->ancho = bitmap.bmWidth;
		image->alto = bitmap.bmHeight;
	}
	image->pos_x = 0;
	image->pos_y = 0;
	image->hBitmap_mask = NULL;
	image->ruta_mask[0] = '\0';

	if (image->hBitmap == NULL)
	{
		free(image);
		image = NULL;
	}
	return image;
}

MiniWinImage *creaImagenYMascaraBMP(const char *ruta, const char *ruta_mask)
{
	MiniWinImage *image = (MiniWinImage *)malloc(sizeof(MiniWinImage));
	BITMAP bitmap;
	image->ruta[0] = 0;
	image->ruta_mask[0] = 0;
	image->alto = 0;
	image->ancho = 0;
	image->hBitmap = (HBITMAP)LoadImageA(NULL, ruta, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	if (image->hBitmap != NULL)
	{
		strcpy(image->ruta, ruta);
		GetObject(image->hBitmap, sizeof(bitmap), &bitmap);
		image->ancho = bitmap.bmWidth;
		image->alto = bitmap.bmHeight;
	}
	image->pos_x = 0;
	image->pos_y = 0;

	image->hBitmap_mask = (HBITMAP)LoadImageA(NULL, ruta_mask, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	if (image->hBitmap != NULL)
	{
		strcpy(image->ruta_mask, ruta_mask);
	}

	if (image->hBitmap == NULL || image->hBitmap_mask == NULL)
	{
		free(image);
		image = NULL;
	}

	return image;
}

void eliminaImagen(MiniWinImage *imagen)
{
	DeleteObject(imagen->hBitmap);
	DeleteObject(imagen->hBitmap_mask);
	free(imagen);
}

void muestraImagen(MiniWinImage *imagen)
{
	HGDIOBJ oldBitmap;
	BITMAP bitmap;
	HDC imagehdc;

	if (imagen->hBitmap_mask != NULL)
	{
		imagehdc = CreateCompatibleDC(NULL);
		GetObject(imagen->hBitmap_mask, sizeof(bitmap), &bitmap);
		oldBitmap = SelectObject(imagehdc, imagen->hBitmap_mask);
		StretchBlt(hDCMem, imagen->pos_x, imagen->pos_y, imagen->ancho, imagen->alto, imagehdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCAND);
		if (imagen->hBitmap != NULL)
		{
			SelectObject(imagehdc, imagen->hBitmap);
			StretchBlt(hDCMem, imagen->pos_x, imagen->pos_y, imagen->ancho, imagen->alto, imagehdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCPAINT);
		}
		SelectObject(imagehdc, oldBitmap);
		DeleteObject(imagehdc);
		DeleteObject(oldBitmap);
	}
	else if (imagen->hBitmap != NULL)
	{
		imagehdc = CreateCompatibleDC(NULL);
		GetObject(imagen->hBitmap, sizeof(bitmap), &bitmap);
		oldBitmap = SelectObject(imagehdc, imagen->hBitmap);
		StretchBlt(hDCMem, imagen->pos_x, imagen->pos_y, imagen->ancho, imagen->alto, imagehdc, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
		SelectObject(imagehdc, oldBitmap);
		DeleteObject(imagehdc);
		DeleteObject(oldBitmap);
	}
}

static COLORREF _colores[] = {
	RGB(0, 0, 0),		// NEGRO
	RGB(255, 0, 0),		// ROJO
	RGB(0, 255, 0),		// VERDE
	RGB(0, 0, 255),		// AZUL
	RGB(255, 255, 0),	// AMARILLO
	RGB(255, 0, 255),	// MAGENTA
	RGB(0, 255, 255),	// CYAN
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

void vredimensiona(int ancho, int alto)
{
	iWidth = ancho;
	iHeight = alto;
	int w, h;
	int xPos;
	int yPos;

	frame_real(iWidth, iHeight, &w, &h);

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

void titulo(const char *titulo)
{
	SetWindowTextA(hWnd, titulo);
}

///////////////////////////////////////////////////////////////////////////////////////

#elif defined(__linux)
// TODO
#error "MiniWin no funciona en esta plataforma"

#else

#error "MiniWin no funciona en esta plataforma"

#endif
