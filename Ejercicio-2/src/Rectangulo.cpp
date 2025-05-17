#include "Rectangulo.hpp"

Rectangulo::Rectangulo(float x, float y, float ancho, float largo) : 
    verticeIzquierdoInferior(x, y), 
    ancho(ancho), 
    largo(largo) {}

void Rectangulo::setAncho(float ancho) {
    this->ancho = ancho;
}

float Rectangulo::getAncho() const {
    return ancho;
}

void Rectangulo::setLargo(float largo) {
    this->largo = largo;
}

float Rectangulo::getLargo() const {
    return largo;
}
