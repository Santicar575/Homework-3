#include "IMediciones.hpp"
#include "MedicionBase.hpp"
#include "Presion.hpp"
#include "Posicion.hpp"
#include "SaveFlightData.hpp"

int main(){
    //PREGUNTAR si esta bien agregarle la f o dejarlo asi y hacer cambios en el codigo
    //Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3);
    Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3f);
    posicion.imprimir();
    std::cout << std::endl;
    Presion presion(101.3f, 5.8f, 6.1f);
    presion.imprimir();

    //Prueba de serializacion y deserializacion de la clase Posicion
    std::ofstream out1("Posicion_serial.dat", std::ios::binary);
    if(out1.is_open()){
        posicion.serializar(out1);
        out1.close();
    }

    Posicion posicion2;
    std::ifstream in1("Posicion_serial.dat", std::ios::binary);
    if(in1.is_open()){
        posicion2.deserializar(in1);
        in1.close();
    }
    std::cout << "\nPosicion luego de deserializar: " << std::endl;
    posicion2.imprimir();

    //Prueba de serializacion y deserializacion de la clase Presion
    std::ofstream out2("Presion_serial.dat",std::ios::binary);
    if(out2.is_open()){
        presion.serializar(out2);
        out2.close();
    }

    Presion presion2;
    std::ifstream in2("Presion_serial.dat", std::ios::binary);
    if(in2.is_open()){
        presion2.deserializar(in2);
        in2.close();
    }
    std::cout << "\nPresion luego de deserializar: " << std::endl;
    presion2.imprimir();

    //Prueba de SaveFlightData
    SaveFlightData flightData(posicion, presion);
    flightData.imprimir();

    //Prueba serializacion de SaveFlightData
    std::ofstream out("SaveFlightData_serial.dat", std::ios::binary);
    if(out.is_open()){
        flightData.serializar(out);
        out.close();
    }

    //Prueba deserializacion de SaveFlightData
    SaveFlightData flightData2;
    std::ifstream in("SaveFlightData_serial.dat", std::ios::binary);
    if(in.is_open()){
        flightData2.deserializar(in);
        in.close();
    }
    std::cout << "\nFlight data luego de deserializar: " << std::endl;
    flightData2.imprimir();

    return 0;
}