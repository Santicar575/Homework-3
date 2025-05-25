#pragma once
#include "Circulo.hpp"
#include "Rectangulo.hpp"
#include "Elipse.hpp"
#include <concepts>
#include <iostream>
#include <cmath>

// Template generico de la clase ProcesadorFigura
// Por defecto, lanza una excepción ya que no todas las figuras tienen un cálculo de área definido.
template <typename T>
class ProcesadorFigura{
    public:
        static float calcArea(const T&){
            throw std::runtime_error("No hay un area especificada para esta figura");
        }
};


// Especialización de ProcesadorFigura para la clase Punto.
// Un punto no tiene área, así que se devuelve 0.0f.
template<>
class ProcesadorFigura<Punto>{
    public:
        static float calcArea(const Punto&){
            return 0.0f;
        }
};

// Especialización de ProcesadorFigura para la clase Circulo.
// Se calcula el área utilizando la fórmula: π * radio²
template<>
class ProcesadorFigura<Circulo>{
    public:
        static float calcArea(const Circulo& circulo){
            return circulo.getRadio() * circulo.getRadio() * static_cast<float>(M_PI);
        }
};

// Especialización de ProcesadorFigura para la clase Elipse.
// Se calcula el área utilizando la fórmula: π * semieje mayor * semieje menor.
template<>
class ProcesadorFigura<Elipse>{
    public:
        static float calcArea(const Elipse& elipse){
            return elipse.getSemiejeMayor() * elipse.getSemiejeMenor() * static_cast<float>(M_PI);
        }
};

// Especialización de ProcesadorFigura para la clase Rectangulo.
// Se calcula el área utilizando la fórmula: ancho * largo.
template<>
class ProcesadorFigura<Rectangulo>{
    public:
        static float calcArea(const Rectangulo& rec){
            return rec.getAncho() * rec.getLargo();
        }
};