#include "Posicion.hpp"

Posicion::Posicion(float lat, float lon, float alt, float t) : 
    MedicionBase(t), 
    latitud(lat),
    longitud(lon),
    altitud(alt) {}

Posicion::Posicion(const Posicion& other) : 
    MedicionBase(other), 
    latitud(other.latitud),
    longitud(other.longitud),
    altitud(other.altitud) {}

void Posicion::imprimir() const{
    std::cout << "Posicion" << std::endl;
    std::cout << "Latitud: " << latitud << std::endl;
    std::cout << "Longitud: " << longitud << std::endl;
    std::cout << "Altitud: " << altitud << std::endl;
    std::cout << "Tiempo de medicion: " << getTiempo() << std::endl;
}

void Posicion::serializar(std::ofstream& out) const{
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(float));
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(float));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(float));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(float));
}

void Posicion::deserializar(std::ifstream& in){
    tiempoMedicion = std::make_unique<float>();
    in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(float));
    in.read(reinterpret_cast<char*>(&latitud), sizeof(float));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(float));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(float));
}