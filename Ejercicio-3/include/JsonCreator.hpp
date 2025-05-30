#pragma once
#include "Data.hpp"


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
        std::string jsonStr;

        template <typename T>
        void processData(const Data<T>& data){
            if constexpr (IsDouble<T>){
                jsonStr += "\"vec_doubles\" : [";
                jsonStr += data.processData();
            }
            else if constexpr (IsString<T>){
                jsonStr += "  \"palabras\" : [";
                jsonStr += data.processData();
            }
            else if constexpr (IsIntList<T>){
                jsonStr += "  \"listas\" : [\n";
                jsonStr += data.processData();
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
            jsonStr += "{ ";
            (processData(std::forward<Args>(data)), ...);
            jsonStr += "}\n";
        }
        
        // Método para imprimir el JSON completo con el formato esperado.
        void printJson() const{
            std::cout<<jsonStr<<std::endl;
        }
};