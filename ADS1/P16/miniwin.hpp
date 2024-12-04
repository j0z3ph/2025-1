/**
 * @file miniwin.h
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

#ifndef _MINIWIN_H_
#define _MINIWIN_H_

#define _MINIWIN_VERSION_ "MiniWin 0.2.3"

#include <iostream>
#include <windows.h>

#ifndef MINIWIN_SOURCE
#define main _main_ // Super-cutre hack! (pero funciona)
#endif

int _main_();

std::ostream &log();

// Funciones del API

namespace miniwin
{

	enum Teclas
	{
		ESCAPE = VK_ESCAPE,
		IZQUIERDA = VK_LEFT,
		DERECHA = VK_RIGHT,
		ARRIBA = VK_UP,
		ABAJO = VK_DOWN,
		F1 = VK_F1,
		F2 = VK_F2,
		F3 = VK_F3,
		F4 = VK_F4,
		F5 = VK_F5,
		F6 = VK_F6,
		F7 = VK_F7,
		F8 = VK_F8,
		F9 = VK_F9,
		F10 = VK_F10,
		ESPACIO = VK_SPACE,
		RETURN = VK_RETURN,
		NUMERO_0 = 48,
		NUMERO_1 = 49,
		NUMERO_2 = 50,
		NUMERO_3 = 51,
		NUMERO_4 = 52,
		NUMERO_5 = 53,
		NUMERO_6 = 54,
		NUMERO_7 = 55,
		NUMERO_8 = 56,
		NUMERO_9 = 57,
		LETRA_A = 65,
		LETRA_B = 66,
		LETRA_C = 67,
		LETRA_D = 68,
		LETRA_E = 69,
		LETRA_F = 70,
		LETRA_G = 71,
		LETRA_H = 72,
		LETRA_I = 73,
		LETRA_J = 74,
		LETRA_K = 75,
		LETRA_L = 76,
		LETRA_M = 77,
		LETRA_N = 78,
		LETRA_O = 79,
		LETRA_P = 80,
		LETRA_Q = 81,
		LETRA_R = 82,
		LETRA_S = 83,
		LETRA_T = 84,
		LETRA_U = 85,
		LETRA_V = 86,
		LETRA_W = 87,
		LETRA_X = 88,
		LETRA_Y = 89,
		LETRA_Z = 90,
		NINGUNA = 0
	};

	enum Colores
	{
		NEGRO,
		ROJO,
		VERDE,
		AZUL,
		AMARILLO,
		MAGENTA,
		CYAN,
		BLANCO
	};

	class MiniWinImage
	{
	private:
		long _ancho;
		long _alto;
		int _pos_x;
		int _pos_y;
		HGDIOBJ _hBitmap;
		HGDIOBJ _hBitmapMask;
		std::string _ruta;
		std::string _ruta_mask;

	public:
		/**
		 * @brief Crea una imagen de MiniWin
		 *
		 * @param ruta La ruta de la imagen. El archivo debe ser <b>BMP</b>
		 */
		MiniWinImage(std::string ruta);
		/**
		 * @brief Crea una imagen de MiniWin
		 *
		 * @param ruta La ruta de la imagen. El archivo debe ser <b>BMP</b>
		 * @param ruta_mask La ruta de la mascara. El archivo debe ser <b>BMP</b> y del mismo tamanio
		 * que la imagen.
		 */
		MiniWinImage(std::string ruta, std::string ruta_mask);

		~MiniWinImage();

		/**
		 * @brief Devuelve el mapa de bits.
		 *
		 * @return HGDIOBJ Mapa de bits.
		 */
		HGDIOBJ bitmap();
		/**
		 * @brief Devuelve el mapa de bits de la mascara.
		 *
		 * @return HGDIOBJ Mapa de bits
		 */
		HGDIOBJ bitmap_mask();

		/**
		 * @brief Establece la posicion en X de la imagen.
		 *
		 * @param x Coordanda en X de la pantalla.
		 */
		void posX(int x);
		/**
		 * @brief Establece la posicion en Y de la imagen.
		 *
		 * @param y Coordenada en Y de la pantalla.
		 */
		void posY(int y);
		/**
		 * @brief Obtiene la posicion en X de la imagen.
		 *
		 * @return int Coordenada en X de la pantalla.
		 */
		int posX();
		/**
		 * @brief Obtiene la posicion en Y de la imagen.
		 *
		 * @return int Coordenada en Y de la pantalla.
		 */
		int posY();

		/**
		 * @brief Obtiene el ancho en pixeles de la imagen.
		 *
		 * @return long Ancho.
		 */
		long ancho();
		/**
		 * @brief Obtiene el alto en pixeles de la imagen.
		 *
		 * @return long Alto.
		 */
		long alto();

		/**
		 * @brief Permite establecer el ancho de la imagen.
		 *
		 * @param ancho Nuevo ancho.
		 */
		void ancho(long ancho)
		{
			this->_ancho = ancho;
		}

		/**
		 * @brief Permite establecer el alto de la imagen.
		 *
		 * @param alto Nuevo alto.
		 */
		void alto(long alto)
		{
			this->_alto = alto;
		}

		/**
		 * @brief Obtiene la ruta de la imagen.
		 *
		 * @return std::string Ruta de la imagen.
		 */
		std::string ruta();
	};

	/**
	 * @brief Permite cambiar al modo pantalla completa.
	 * Nota: Las dimensiones de la ventana cambian.
	 *
	 * @param fullscreenOn Si es true, cambia al modo pantalla completa.
	 * Si es false, regresa al modo ventana con las ultimas dimensiones establecidas.
	 */
	void fullscreen(bool fullscreenOn);

	/**
	 * @brief Permite cambiar el color de fondo de la ventana.
	 *
	 * @param c Nuevo color de alguno de los enumeradores.
	 */
	void color_fondo(Colores c);

	/**
	 * @brief Permite cambiar el color de fondo de la ventana.
	 *
	 * @param r Rojo (0-255)
	 * @param g Verde (0-255)
	 * @param b Azul (0-255)
	 */
	void color_fondo_rgb(int r, int g, int b);

	/**
	 * @brief Muestra la imagen en pantalla.
	 *
	 * @param imagen La imagen en mostrar.
	 */
	void muestraImagen(MiniWinImage &imagen);

	/**
	 * @brief Permite imprimir un texto en pantalla.
	 *
	 * @param x Posicion en X
	 * @param y Posicion en Y
	 * @param texto Texto a mostrar
	 * @param tamanioFuente Tamanio de la fuente
	 * @param italica True para mostrar en italica. False para mostrar normal.
	 * @param negrita True para mostrar en negrita. False para mostrar normal.
	 * @param subrayada True para mostrar texto subrayado. False para mostrar normal.
	 * @param fuente Nombre de la fuente a usar.
	 */
	void texto(float x, float y, const std::string &texto, int tamanioFuente,
			   bool italica, bool negrita, bool subrayada, std::string fuente);

	/**
	 * @brief Permite determinar si se solto una tecla.
	 *
	 * @return int Codigo de la tecla que se solto.
	 */
	int teclaUp();
	/**
	 * @brief Permite determinar si se presiono una tecla.
	 *
	 * @return int Codigo de la tecla presionada.
	 */
	int teclaDown();

	/**
	 * @brief Permite abrir una ventana del tamanio especificado.
	 *
	 * @param ancho Ancho de la ventana
	 * @param alto Alto de la ventana
	 */
	void ventana(int ancho, int alto);

	/**
	 * @brief Limpia el contenido de la ventana.
	 * El color del fondo de la ventana se manda al color del fondo.
	 *
	 */
	void borra();
	/**
	 * @brief Forza el repintado del contenido de la ventana.
	 *
	 */
	void refresca();
	/**
	 * @brief Muestra un dialogo con el mensaje indicado.
	 *
	 * @param msj Mensaje que se mostrara en el dialogo.
	 */
	void mensaje(std::string msj);
	/**
	 * @brief Muestra un dialogo con el mensaje indicado.
	 *
	 * @param msj Mensaje que se mostrara en el dialogo.
	 * @param titulo Titulo del dialogo.
	 */
	void mensaje(std::string msj, std::string titulo);
	/**
	 * @brief Muestra un dialogo de pregunta.
	 *
	 * @param msj Mensaje que se mostrara en el dialogo.
	 * @return true Si la respuesta fue afirmativa.
	 * @return false En cualquier otro caso.
	 */
	bool pregunta(std::string msj);
	/**
	 * @brief Muestra un dialogo de pregunta.
	 *
	 * @param msj Mensaje que se mostrara en el dialogo.
	 * @param titulo Titulo del dialogo.
	 * @return true Si la respuesta fue afirmativa.
	 * @return false En cualquier otro caso.
	 */
	bool pregunta(std::string msj, std::string titulo);
	/**
	 * @brief Detiene la ejecucion del proceso por una cantidad
	 * de tiempo.
	 *
	 * @param miliseg Tiempo en milisegundos que se detendra el proceso.
	 */
	void espera(int miliseg);

	/**
	 * @brief Obtiene el ancho de la ventana.
	 *
	 * @return int Ancho de la ventana.
	 */
	int vancho();
	/**
	 * @brief Obtiene el alto de la ventana.
	 *
	 * @return int Alto de la ventana.
	 */
	int valto();
	/**
	 * @brief Permite cambiar el tamanio de la ventana.
	 *
	 * @param ancho Nuevo ancho.
	 * @param alto Nuevo alto.
	 */
	void vredimensiona(int ancho, int alto);
	/**
	 * @brief Permite cerrar la ventana.
	 *
	 */
	void cierra();
	/**
	 * @brief Permite cambiar el titulo de la ventana.
	 *
	 * @param titulo Nuevo titulo de la ventana.
	 */
	void titulo(std::string titulo);

	/**
	 * @brief Permite cambiar el color a usar para dibujar en
	 * la pantalla.
	 *
	 * @param c Entero entre 0 y 7
	 * 0 - NEGRO
	 * 1 - ROJO
	 * 2 - VERDE
	 * 3 - AZUL
	 * 4 - AMARILLO
	 * 5 - MAGENTA
	 * 6 - CYAN
	 * 7 - BLANCO
	 */
	void color(Colores c);
	/**
	 * @brief Permite cambiar el color a usar para dibujar en
	 * la pantalla.
	 *
	 * @param r Cantidad de rojo (0-255)
	 * @param g Cantidad de verde (0-255)
	 * @param b Cantidad de azul (0-255)
	 */
	void color_rgb(int r, int g, int b);

	/**
	 * @brief Permite dibujar un punto en la ventana.
	 *
	 * @param x Coordenada x.
	 * @param y Coordenada y.
	 */
	void punto(float x, float y);
	/**
	 * @brief Permite dibujar una linea en la pantalla.
	 *
	 * @param x_ini Coordenada x inicial.
	 * @param y_ini Coordenada y inicial.
	 * @param x_fin Coordenada x final.
	 * @param y_fin Coordenada y final.
	 */
	void linea(float x_ini, float y_ini, float x_fin, float y_fin);
	/**
	 * @brief Permite dibujar un rectangulo sin relleno en la ventana.
	 *
	 * @param izq Coordenada x de la esquina superior izquierda.
	 * @param arr Coordenada y de la esquina superior izquierda.
	 * @param der Coordenada x de la esquina inferior derecha.
	 * @param aba Coordenada y de la esquina inferior derecha.
	 */
	void rectangulo(float izq, float arr, float der, float aba);
	/**
	 * @brief Permite dibujar un rectangulo con relleno en la ventana.
	 *
	 * @param izq Coordenada x de la esquina superior izquierda.
	 * @param arr Coordenada y de la esquina superior izquierda.
	 * @param der Coordenada x de la esquina inferior derecha.
	 * @param aba Coordenada y de la esquina inferior derecha.
	 */
	void rectangulo_lleno(float izq, float arr, float der, float aba);
	/**
	 * @brief Permite dibujar un circulo sin relleno en la ventana.
	 *
	 * @param x_cen Coordenada x del centro del circulo.
	 * @param y_cen Coordenada y del centro del circulo.
	 * @param radio Radio del circulo.
	 */
	void circulo(float x_cen, float y_cen, float radio);
	/**
	 * @brief Permite dibujar un circulo con relleno en la ventana.
	 *
	 * @param x_cen Coordenada x del centro del circulo.
	 * @param y_cen Coordenada y del centro del circulo.
	 * @param radio Radio del circulo.
	 */
	void circulo_lleno(float x_cen, float y_cen, float radio);
	/**
	 * @brief Permite dibujar un texto en la ventana.
	 *
	 * @param x Coordenada x.
	 * @param y Coordenada y.
	 * @param texto Texto a dibujar.
	 */
	void texto(float x, float y, const std::string &texto);

	/**
	 * @brief Permite determinar si se presiono una tecla.
	 * No detiene el proceso.
	 *
	 * @return int Codigo de la tecla presionada.
	 * Las teclas conocidas son:
	 * 0 - ESCAPE
	 * 1 - IZQUIERDA
	 * 2 - DERECHA
	 * 3 - ARRIBA
	 * 4 - ABAJO
	 * 5 - F1
	 * 6 - F2
	 * 7 - F3
	 * 8 - F4
	 * 9 - F5
	 * 10 - F6
	 * 11 - F7
	 * 12 - F8
	 * 13 - F9
	 * 14 - F10
	 * 15 - ESPACIO
	 * 16 - RETURN
	 * 17 - NINGUNA
	 *
	 * Para cualquier otra tecla se devuelve su valor numerico.
	 */
	int tecla();

	/**
	 * @brief Permite obtener la posicion x,y del mouse
	 * respecto a la ventana.
	 *
	 * @param x Posicion del raton en x.
	 * @param y Posicion del raton en y.
	 * @return true Si el mouse se encuentra dentro de la ventana.
	 * @return false Si el mouse se encuentra fuera de la ventana.
	 */
	bool raton(float &x, float &y);
	/**
	 * @brief Permite saber si el mouse se encuentra dentro de la ventana.
	 *
	 * @return true
	 * @return false
	 */
	bool raton_dentro();
	/**
	 * @brief Permite obtener la coordenada en x del raton.
	 *
	 * @return float Coordenada en x.
	 */
	float raton_x();
	/**
	 * @brief Permite obtener la coordenada en y del raton.
	 *
	 * @return float Coordenada en y.
	 */
	float raton_y();
	/**
	 * @brief Permite obtener el boton del mouse que se a presionado.
	 *
	 * @param izq true Si se presiono el boton izquierdo. false En cualquier otro caso.
	 * @param der true Si se presiono el boton derecho. false En cualquier otro caso.
	 */
	void raton_botones(bool &izq, bool &der);
	/**
	 * @brief Permite determinar si se presiono el boton izquierdo del mouse.
	 *
	 * @return true Si se presiono.
	 * @return false Si no se presiono.
	 */
	bool raton_boton_izq();
	/**
	 * @brief Permite determinar si se presiono el boton derecho del mouse.
	 *
	 * @return true Si se presiono.
	 * @return false Si no se presiono.
	 */
	bool raton_boton_der();

} // namespace miniwin

#endif
