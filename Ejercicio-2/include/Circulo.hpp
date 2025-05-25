#pragma once
#include "Punto.hpp"

class Circulo{
    private:
        Punto centro;
        float radio;
    public:
        // Constructor que inicializa el centro y el radio del círculo
        Circulo(float x, float y, float r);
        void setRadio(float r);
        float getRadio() const;
        Punto getCentro() const;
        void setCentro(float x, float y);
        void setCentro(const Punto& p);
        ~Circulo() = default;
};