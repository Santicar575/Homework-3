#include "Circulo.hpp"

Circulo::Circulo(float x, float y, float r) : 
    centro(x, y), 
    radio(r) {}

void Circulo::setRadio(float r){
    radio = r;
}

float Circulo::getRadio() const{
    return radio;
}