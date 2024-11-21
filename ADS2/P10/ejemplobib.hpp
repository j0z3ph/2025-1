#ifndef __EJEMPLOBIB_HPP__
#define __EJEMPLOBIB_HPP__

int suma(int, int);

class Figura {
    protected:
    int base;
    int altura;

    public:
    // Setters
    void setBase(int base);
    void setAltura(int altura);

    // Getters
    int getBase();
    int getAltura();

    // Metodos
    int area();

    int perimetro();
};


class Rectangulo : public Figura
{
    public:
    void metodo() {
        
    }
};

class Cuadrado : public Figura
{
};

class Triangulo : public Figura
{
};


#endif