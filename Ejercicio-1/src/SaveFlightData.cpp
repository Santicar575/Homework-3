#include "SaveFlightData.hpp"

// Constructor que inicializa los datos de vuelo a partir de objetos Posicion y Presion.
// Utiliza inicialización por copia (requiere que ambas clases sean copiables).
SaveFlightData::SaveFlightData(const Posicion& p, const Presion& q) :
    posicion(p),
    presion(q) {}

// Serializa el estado completo del objeto SaveFlightData en un archivo binario.
// Llama a las funciones de serialización de los objetos Posicion y Presion en ese orden.
void SaveFlightData::serializar(std::ofstream& out) const{
    posicion.serializar(out);
    presion.serializar(out);
}

// Deserializa el contenido de un archivo binario y reconstruye el estado del objeto.
// Lee en el mismo orden en el que fueron escritos: Posicion luego Presion.
void SaveFlightData::deserializar(std::ifstream& in){
    posicion.deserializar(in);
    presion.deserializar(in);
}

void SaveFlightData::imprimir() const{
    std::cout << "Flight Data: " << std::endl;
    posicion.imprimir();
    presion.imprimir();
}