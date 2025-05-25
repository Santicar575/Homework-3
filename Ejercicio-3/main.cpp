#include "Data.hpp"
#include "JsonCreator.hpp"

int main(){
    Data<double> dataDouble;
    Data<std::string> dataString;
    Data<std::vector<int>> dataMatrix;

    // Agregado de valores a cada Data<T>
    dataDouble.addValue(1.3);
    dataDouble.addValue(2.1);
    dataDouble.addValue(3.2);

    dataString.addValue("Hola");
    dataString.addValue("Mundo");

    dataMatrix.addValue({1,2});
    dataMatrix.addValue({3,4});

    // Construcción del JSON usando los datos
    JsonCreator builder(dataDouble,dataMatrix,dataString);

    // Imprimir el JSON
    builder.printJson();

    return 0;
}