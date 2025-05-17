#pragma once
#include "MedicionBase.hpp"

class Posicion : public MedicionBase{
    public:
        float latitud;
        float longitud;
        float altitud;

        Posicion() = default;
        Posicion(float lat, float lon, float alt, float t);
        Posicion(const Posicion& other);
        virtual void imprimir() const override;
        virtual void serializar(std::ofstream& out) const override;
        virtual void deserializar(std::ifstream& in) override;
        ~Posicion() = default;
};
