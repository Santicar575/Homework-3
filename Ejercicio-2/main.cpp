#include "PorcesadorFigura.hpp"

int main(){
    Punto p(1.0f, 2.0f);
    Circulo c(1.0f, 2.0f, 3.0f);
    Elipse e(1.0f, 2.0f, 3.0f, 4.0f);
    Rectangulo r(1.0f, 2.0f, 3.0f, 4.0f);
    // Se calcula y muestra el área para cada figura usando la clase ProcesadorFigura
    std::cout << "Area del punto: " << ProcesadorFigura<Punto>::calcArea(p) << std::endl;
    std::cout << "Area del circulo: " << ProcesadorFigura<Circulo>::calcArea(c) << std::endl;
    std::cout << "Area de la elipse: " << ProcesadorFigura<Elipse>::calcArea(e) << std::endl;
    std::cout << "Area del rectangulo: " << ProcesadorFigura<Rectangulo>::calcArea(r) << std::endl;
    // Intento de calcular área para un tipo no soportado (int),
    // que debería lanzar una excepción atrapada en el bloque catch
    try{
        ProcesadorFigura<int>::calcArea(20);
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }
    return 0;
}