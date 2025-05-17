#include "Data.hpp"
#include "JsonCreator.hpp"

int main(){
    Data data;
    data.addValue(1.3);
    data.addValue(2.1);
    data.addValue(3.2);
    data.addValue("Hola");
    data.addValue("Mundo");
    std::vector<int> list = {1,2};
    data.addValue(list);
    list = {3,4};
    data.addValue(list);
    JsonCreator builder(data);
    builder.printJson();
    return 0;
}