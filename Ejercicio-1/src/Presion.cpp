#include "Presion.hpp"

Presion::Presion(float p, float q, float t) : 
    MedicionBase(t), 
    presionEstatica(p),
    presionDinamica(q) {}

Presion::Presion(const Presion& other) : 
    MedicionBase(other), 
    presionEstatica(other.presionEstatica),
    presionDinamica(other.presionDinamica) {}   

void Presion::imprimir() const{
    std::cout << "Presion" << std::endl;
    std::cout << "Presion dinamica: " << presionDinamica << std::endl;
    std::cout << "Presion estatica: " << presionEstatica << std::endl;
    std::cout << "Tiempo de medicion: " << getTiempo() << std::endl; 
}

void Presion::serializar(std::ofstream& out) const{
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(float));
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(float));
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(float));
}

void Presion::deserializar(std::ifstream& in){
    tiempoMedicion = std::make_unique<float>();
    in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(float));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(float));
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(float));
}