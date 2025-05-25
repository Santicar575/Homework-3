#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <concepts>



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
         * El método valida el tipo de T en tiempo de compilación con if constexpr.
        */
        void addValue(T value){
            if constexpr (IsDouble<T>){
                vector.push_back(value);
            }
            else if constexpr (IsString<T>){
                vector.push_back(value);
            }
            else if constexpr (IsIntList<T>){
                vector.push_back(value);
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
