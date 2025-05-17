#pragma once
#include "Posicion.hpp"
#include "Presion.hpp"

class SaveFlightData{
    public:
        Posicion posicion;
        Presion presion;

        SaveFlightData() = default;
        SaveFlightData(const Posicion& p, const Presion& q);
        void serializar(std::ofstream& out) const;
        void deserializar(std::ifstream& in);
        void imprimir() const;
        ~SaveFlightData() = default;
};