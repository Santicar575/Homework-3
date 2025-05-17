#pragma once
#include "Punto.hpp"

class Rectangulo{
    private:
        Punto verticeIzquierdoInferior;
        float ancho;
        float largo;
    public:
        Rectangulo(float x, float y, float ancho, float largo);
        void setAncho(float ancho);
        float getAncho() const;
        void setLargo(float largo);
        float getLargo() const;
        ~Rectangulo() = default;
};
