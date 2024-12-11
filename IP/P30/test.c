#include"miniwin.h"

int main()
{
    int t;
    float x,y;
    bool full = false;
    ventana(300,300);
    color_fondo(AZUL);

    t = tecla();
    while(t != ESCAPE) {
        t = tecla();
        borra();
        if(t == ESPACIO) {
            full = !full;
            fullscreen(full);
        }
        raton(&x,&y);
        color(BLANCO);
        circulo(x,y,10);

        
        refresca();

        espera(1);
    }

    cierra();

    return 0;
}
