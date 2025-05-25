#include "Posicion.hpp"


Posicion::Posicion(float lat, float lon, float alt, float t) : 
    MedicionBase(t), 
    latitud(lat),
    longitud(lon),
    altitud(alt) {}

// Constructor de copia que copia todos los atributos, incluyendo los heredados de MedicionBase.
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

// Serializa los datos del objeto Posicion en un archivo binario.
// Escribe en orden: tiempo de medición, latitud, longitud y altitud.
void Posicion::serializar(std::ofstream& out) const{
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(float));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(float));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(float));
}

// Deserializa los datos del objeto Posicion desde un archivo binario.
// Lee en el mismo orden en el que fueron escritos: tiempo, latitud, longitud, altitud.
void Posicion::deserializar(std::ifstream& in){
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&latitud), sizeof(float));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(float));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(float));
}