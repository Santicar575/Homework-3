#include "Circulo.hpp"
#include <stdexcept>

Circulo::Circulo(float x, float y, float r) : centro(x, y){
    if (r < 0) throw std::invalid_argument("El radio no puede ser negativo");
    radio = r;
}

void Circulo::setRadio(float r){
    if (r < 0) throw std::invalid_argument("El radio no puede ser negativo");
    radio = r;
}

float Circulo::getRadio() const{
    return radio;
}

Punto Circulo::getCentro() const{
    return centro;
}

void Circulo::setCentro(float x, float y){
    centro.setX(x);
    centro.setY(y);
}

void Circulo::setCentro(const Punto& p){
    centro.setX(p.getX());
    centro.setY(p.getY());
}