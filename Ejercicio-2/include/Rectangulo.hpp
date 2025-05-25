#pragma once
#include "Punto.hpp"

class Rectangulo{
    private:
        Punto verticeIzquierdoInferior;
        float ancho;
        float largo;
    public:
        // Constructor que inicializa el vértice inferior izquierdo y las dimensiones del rectángulo
        Rectangulo(float x, float y, float ancho, float largo);
        void setAncho(float ancho);
        float getAncho() const;
        void setLargo(float largo);
        float getLargo() const;
        Punto getVerticeIzquierdoInferior() const;
        void setVerticeIzquierdoInferior(float x, float y);
        void setVerticeIzquierdoInferior(const Punto& p);
        ~Rectangulo() = default;
};
