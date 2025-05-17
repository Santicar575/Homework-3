#include "JsonCreator.hpp"

JsonCreator::JsonCreator(Data data) : data(data) {}

void JsonCreator::printDoubleVector() const{
    size_t currentSize;
    size_t i;
    std::cout<<"\"vec_doubles\" : [";
    const auto& doubleVector = data.getDoubleVector();
    currentSize = doubleVector.size();
    if(currentSize != 0){
        for(i = 0;i<currentSize-1;i++){
            std::cout<<doubleVector[i]<<", ";
        }
        std::cout<<doubleVector[i]<<"],\n";
    }else{
        std::cout<<"],\n";
    }       
}

void JsonCreator::printStringVector() const{
    size_t currentSize;
    size_t i;
    std::cout<<"  \"palabras\" : [";
    const auto& stringVector = data.getStringVector();
    currentSize = stringVector.size();
    if(currentSize != 0){
        for(i = 0; i<currentSize-1; i++){
            std::cout << "\"" << stringVector[i] << "\", ";
        }
        std::cout<< "\"" << stringVector[i]<< "\"],\n";
    }else{
        std::cout<<"],\n";
    }
}

void JsonCreator::printListVector() const{
    size_t currentSize;
    size_t i;
    std::cout<<"  \"listas\" : [\n";
    const auto& intListVector = data.getIntListVector();
    size_t cantListas = intListVector.size();
    size_t j;
    if(cantListas != 0){
        for(i = 0; i <cantListas-1; i++){
            const auto& currentList = intListVector[i];
            currentSize = currentList.size();
            if(currentSize == 0) continue;
            std::cout<<"           [";
            for(j = 0; j<currentSize-1; j++){
                std::cout<<currentList[j]<<", ";
            }
            std::cout<<currentList[j]<<"],\n";
        }
        const auto& currentList = intListVector[i];
        currentSize = currentList.size();
        if(currentSize != 0){
            std::cout<<"           [";
            for(j = 0; j<currentSize-1; j++){
                std::cout<<currentList[j]<<", ";
            }
            std::cout<<currentList[j]<<"]\n";
        }
    }
    std::cout<<"          ]\n";
}

void JsonCreator::printJson() const{
    std::cout<<"{ ";
    printDoubleVector();
    printStringVector();
    printListVector();
    std::cout<<"}\n";
}
