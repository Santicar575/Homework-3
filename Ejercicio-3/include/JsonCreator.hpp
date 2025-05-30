#pragma once
#include "Data.hpp"


/**
 * Clase encargada de construir el JSON final.
 * Almacena internamente las cadenas formateadas para cada sección del JSON
*/
class JsonCreator{
    private:
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

    public:
        /**
         * Constructor que recibe multiples Data<T> y los procesa.
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

        ~JsonCreator() = default;
};