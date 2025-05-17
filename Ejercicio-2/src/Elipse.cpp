#include "Elipse.hpp"

Elipse::Elipse(float x, float y, float a, float b) : 
    centro(x, y),
    a(a),
    b(b) {}

void Elipse::setSemiejeMayor(float a){
    this->a = a;
}

float Elipse::getSemiejeMayor() const{
    return a;
}

void Elipse::setSemiejeMenor(float b){
    this->b = b;
}

float Elipse::getSemiejeMenor() const{
    return b;
}