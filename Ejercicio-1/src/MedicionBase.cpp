#include "MedicionBase.hpp"

MedicionBase::MedicionBase(float tiempo) : tiempoMedicion(std::make_unique<float>(tiempo)) {}

//Creo el copy constructor para poder copiar el unique_ptr cuando se hace una copia de la clase
//De esta manera, puedo guardar los datos en la clase SaveFlightData
MedicionBase::MedicionBase(const MedicionBase& other){
    tiempoMedicion = std::make_unique<float>(other.getTiempo());
}

// Metodo getter para obtener el tiempo de medición.
// Lanza una excepción si el unique_ptr no ha sido inicializado.
float MedicionBase::getTiempo() const{
    if(tiempoMedicion){
        return *tiempoMedicion;
    }else{
        throw std::runtime_error("tiempoMedicion no ha sido inicializado.");
    }
}

void MedicionBase::serializar(std::ofstream& out) const{
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(float));
}

void MedicionBase::deserializar(std::ifstream& in){
    //Reservo memoria dinamica para tiempoMedicion
    tiempoMedicion = std::make_unique<float>();
    in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(float));
}
