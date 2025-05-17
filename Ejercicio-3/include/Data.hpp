#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <concepts>

template <typename T>
concept IsDouble = std::is_same_v<T,double>;

template <typename T>
concept IsString = std::is_same_v<T,std::string> || std::is_same_v<T,const char*>;

template <typename T>
concept IsIntList = std::is_same_v<T,std::vector<int>>;

class Data{
    private:
        std::vector<double> doubleVector;
        std::vector<std::string> stringVector;
        std::vector<std::vector<int>> intListVector;

    public:
        template <typename T>
        void addValue(T value){
            if constexpr (IsDouble<T>){
                doubleVector.push_back(value);
            }
            else if constexpr (IsString<T>){
                stringVector.push_back(value);
            }
            else if constexpr (IsIntList<T>){
                intListVector.push_back(value);
            }
            else{
                static_assert(IsDouble<T> || IsString<T> || IsIntList<T>, "Tipo de dato no soportado");
            }
        }

        const std::vector<double>& getDoubleVector() const {return doubleVector;}
        const std::vector<std::string>& getStringVector() const {return stringVector;}
        const std::vector<std::vector<int>>& getIntListVector() const {return intListVector;}
};
