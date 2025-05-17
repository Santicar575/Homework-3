#include "SaveFlightData.hpp"

SaveFlightData::SaveFlightData(const Posicion& p, const Presion& q) :
    posicion(p),
    presion(q) {}

void SaveFlightData::serializar(std::ofstream& out) const{
    posicion.serializar(out);
    presion.serializar(out);
}

void SaveFlightData::deserializar(std::ifstream& in){
    posicion.deserializar(in);
    presion.deserializar(in);
}

void SaveFlightData::imprimir() const{
    std::cout << "Flight Data: " << std::endl;
    posicion.imprimir();
    presion.imprimir();
}