#include "Rectangulo.hpp"
#include <stdexcept>

Rectangulo::Rectangulo(float x, float y, float ancho, float largo) : verticeIzquierdoInferior(x, y){
    if (ancho < 0 || largo < 0) throw std::invalid_argument("El ancho y el largo no pueden ser negativos");
    this->ancho = ancho;
    this->largo = largo;
}

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

Punto Rectangulo::getVerticeIzquierdoInferior() const {
    return verticeIzquierdoInferior;
}

void Rectangulo::setVerticeIzquierdoInferior(float x, float y) {
    verticeIzquierdoInferior.setX(x);
    verticeIzquierdoInferior.setY(y);
}

void Rectangulo::setVerticeIzquierdoInferior(const Punto& p) {
    verticeIzquierdoInferior.setX(p.getX());
    verticeIzquierdoInferior.setY(p.getY());
}
