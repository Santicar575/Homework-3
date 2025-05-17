#pragma once
#include "MedicionBase.hpp"

class Presion : public MedicionBase{
    public:
        float presionEstatica;
        float presionDinamica;

        Presion() = default;
        Presion(float p, float q, float t);
        Presion(const Presion& other);
        virtual void imprimir() const override;
        virtual void serializar(std::ofstream& out) const override;
        virtual void deserializar(std::ifstream& in) override;
        ~Presion() = default;
};