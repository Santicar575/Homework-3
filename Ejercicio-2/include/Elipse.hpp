#pragma once
#include "Punto.hpp"

class Elipse {
    private:
        Punto centro; //Centro de la elipse
        float a; //Semieje mayor
        float b; //Semieje menor
    public:
        // Constructor que inicializa el centro y los semiejes de la elipse
        Elipse(float x, float y, float a, float b);
        void setSemiejeMayor(float a);
        float getSemiejeMayor() const;
        void setSemiejeMenor(float b);
        float getSemiejeMenor() const;
        Punto getCentro() const;
        void setCentro(float x, float y);
        void setCentro(const Punto& p);
        ~Elipse() = default;
};