#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <concepts>
#include <sstream>


//Concept para verificar si el tipo es double
template <typename T>
concept IsDouble = std::is_same_v<T,double>;

//Concept para verificar si el tipo es string o const char*
template <typename T>
concept IsString = std::is_same_v<T,std::string> || std::is_same_v<T,const char*>;

//Concept para verificar si el tipo es un vector de enteros
template <typename T>
concept IsIntList = std::is_same_v<T,std::vector<int>>;

// Clase genérica que almacena un vector de valores y permite agregarlos según su tipo
template <typename T>
class Data{
    private:
        std::vector<T> vector; // Contenedor interno de los datos
    public:
        Data() = default;
        
        /**
         * Agrega un valor al vector interno.
        */
        void addValue(T value){
            vector.push_back(value);
        }

        std::string processData() const{
            if constexpr (IsDouble<T>){
                size_t currentSize;
                size_t i;
                std::ostringstream oss;
                const auto& doubleVector = vector;
                currentSize = doubleVector.size();
                if(currentSize != 0){
                    for(i = 0;i<currentSize-1;i++){
                        oss<<doubleVector[i]<<", ";
                    }
                    oss<<doubleVector[i]<<"],\n";
                }else{
                    oss<<"],\n";
                } 
                return oss.str();
            }
            else if constexpr (IsString<T>){
                size_t currentSize;
                size_t i;
                std::ostringstream oss;
                const auto& stringVector = vector;
                currentSize = stringVector.size();
                if(currentSize != 0){
                    for(i = 0; i<currentSize-1; i++){
                        oss << "\"" << stringVector[i] << "\", ";
                    }
                    oss<< "\"" << stringVector[i]<< "\"],\n";
                }else{
                    oss<<"],\n";
                }
                return oss.str();
            }
            else if constexpr (IsIntList<T>){
                size_t currentSize;
                size_t i;
                std::ostringstream oss;
                const auto& intListVector = vector;
                size_t cantListas = intListVector.size();
                size_t j;
                if(cantListas != 0){
                    for(i = 0; i <cantListas-1; i++){
                        const auto& currentList = intListVector[i];
                        currentSize = currentList.size();
                        if(currentSize == 0) continue;
                        oss<<"           [";
                        for(j = 0; j<currentSize-1; j++){
                            oss<<currentList[j]<<", ";
                        }
                        oss<<currentList[j]<<"],\n";
                    }
                    const auto& currentList = intListVector[i];
                    currentSize = currentList.size();
                    if(currentSize != 0){
                        oss<<"           [";
                        for(j = 0; j<currentSize-1; j++){
                            oss<<currentList[j]<<", ";
                        }
                        oss<<currentList[j]<<"]\n";
                    }
                }
                oss << "          ]\n";
                return oss.str();
            }
            else{
                static_assert(IsDouble<T> || IsString<T> || IsIntList<T>, "Tipo de dato no soportado");
            }
        }

        /**
         * Devuelve una referencia constante al vector interno (solo lectura).
         * @return vector
        */
        const std::vector<T>& getVector() const {return vector;}
};
