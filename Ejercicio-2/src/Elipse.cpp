#include "Elipse.hpp"
#include <stdexcept>

Elipse::Elipse(float x, float y, float a, float b) : centro(x, y){
    if (a < 0 || b < 0) throw std::invalid_argument("Los semiejes no pueden ser negativos");
    if (a < b) throw std::invalid_argument("El semieje mayor debe ser mayor o igual que el semieje menor");
    this->a = a;
    this->b = b;
}

void Elipse::setSemiejeMayor(float a){
    if (a < 0) throw std::invalid_argument("El semieje mayor no puede ser negativo");
    if (a < b) throw std::invalid_argument("El semieje mayor no puede ser menor que el semieje menor");
    this->a = a;
}

float Elipse::getSemiejeMayor() const{
    return a;
}

void Elipse::setSemiejeMenor(float b){
    if (b < 0) throw std::invalid_argument("El semieje menor no puede ser negativo");
    if (a < b) throw std::invalid_argument("El semieje menor no puede ser mayor que el semieje mayor");
    this->b = b;
}

float Elipse::getSemiejeMenor() const{
    return b;
}

Punto Elipse::getCentro() const{
    return centro;
}

void Elipse::setCentro(float x, float y){
    centro.setX(x);
    centro.setY(y);
}

void Elipse::setCentro(const Punto& p){
    centro.setX(p.getX());
    centro.setY(p.getY());
}
