#pragma once
#include "Punto.hpp"

class Circulo{
    private:
        Punto centro;
        float radio;
    public:
        Circulo(float x, float y, float r);
        void setRadio(float r);
        float getRadio() const;
        ~Circulo() = default;
};