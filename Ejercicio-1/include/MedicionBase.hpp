#pragma once
#include <memory>
#include "IMediciones.hpp"

class MedicionBase : public IMediciones{
    protected:
        std::unique_ptr<float> tiempoMedicion;
    public:
        MedicionBase() = default;
        MedicionBase(float tiempo);
        MedicionBase(const MedicionBase& other);
        float getTiempo() const;
        virtual void serializar(std::ofstream& out) const override;
        virtual void deserializar(std::ifstream& in) override;
        virtual void imprimir() const = 0;
        virtual ~MedicionBase() = default;
};
