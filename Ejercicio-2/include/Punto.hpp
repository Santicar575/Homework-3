#pragma once

class Punto{
    protected:
        float x;
        float y;
    public:
        // Constructor que inicializa las coordenadas del punto
        Punto(float x, float y);
        void setX(float x);
        float getX() const;
        void setY(float y);
        float getY() const;
        ~Punto() = default;
};