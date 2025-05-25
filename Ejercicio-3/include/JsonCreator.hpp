#pragma once
#include "Data.hpp"
#include <sstream>

/**
 * Clase encargada de construir el JSON final.
 * Almacena internamente las cadenas formateadas para cada sección del JSON,
 * y provee métodos para procesar vectores/matrices de distintos tipos.
*/
class JsonCreator{
    private:
        std::string doubleString; // String con el contenido JSON para "vec_doubles"
        std::string palabras; // String con el contenido JSON para "palabras"
        std::string listas; // String con el contenido JSON para "listas"

        std::string processDoubleVector(const Data<double>& data) const{
            size_t currentSize;
            size_t i;
            std::ostringstream oss;
            const auto& doubleVector = data.getVector();
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

        std::string processStringVector(const Data<std::string>& data) const{
            size_t currentSize;
            size_t i;
            std::ostringstream oss;
            const auto& stringVector = data.getVector();
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

        std::string processListVector(const Data<std::vector<int>>& data) const{
            size_t currentSize;
            size_t i;
            std::ostringstream oss;
            const auto& intListVector = data.getVector();
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
            oss<<"          ]\n";
            return oss.str();
        }
        template <typename T>
        void processData(const Data<T>& data){
            if constexpr (IsDouble<T>){
                doubleString = processDoubleVector(data);
            }
            else if constexpr (IsString<T>){
                palabras = processStringVector(data);
            }
            else if constexpr (IsIntList<T>){
                listas = processListVector(data);
            }
            else{
                static_assert(IsDouble<T> || IsString<T> || IsIntList<T>, "Tipo de dato no soportado");
            }
        }

        void printDoubles() const{
            std::cout<<"\"vec_doubles\" : [";
            if(!doubleString.empty()){
                std::cout<<doubleString;
            }else{
                std::cout<<"],\n";
            }
        }
        // Métodos privados para imprimir cada sección con las etiquetas JSON

        void printPalabras() const{
            std::cout<<"  \"palabras\" : [";
            if(!palabras.empty()){
                std::cout<<palabras;
            }else{
                std::cout<<"],\n";
            }
        }

        void printListas() const{
            std::cout<<"  \"listas\" : [\n";
            if(!listas.empty()){
                std::cout<<listas;
            }else{
                std::cout<<"          ]\n";
            }
        }

    public:
        /**
         * Constructor variádico que recibe múltiples Data<T> y los procesa.
         * Permite pasar en cualquier orden los distintos tipos de datos.
        */
        template <typename... Args>
        JsonCreator(Args&&... data){
            (processData(std::forward<Args>(data)), ...);
        }
        
        // Método para imprimir el JSON completo con el formato esperado.
        void printJson() const{
            std::cout<<"{ ";
            printDoubles();
            printPalabras();
            printListas();
            std::cout<<"}\n";
        }
};