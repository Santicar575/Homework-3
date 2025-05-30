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
    JsonCreator builder(dataDouble,dataString,dataMatrix);

    // Imprimir el JSON
    builder.printJson();

    //Prueba imprimir JSON con vectores vacíos
    Data<double> emptyDataDouble;
    Data<std::string> emptyDataString;
    Data<std::vector<int>> emptyDataMatrix;

    JsonCreator emptyBuilder(emptyDataDouble, emptyDataString, emptyDataMatrix);
    emptyBuilder.printJson();

    // Imprimir JSON con un solo tipo de dato
    JsonCreator singleTypeBuilder(dataDouble);
    singleTypeBuilder.printJson();
    JsonCreator singleStringBuilder(dataString);
    singleStringBuilder.printJson();
    JsonCreator singleMatrixBuilder(dataMatrix);
    singleMatrixBuilder.printJson();

    return 0;
}