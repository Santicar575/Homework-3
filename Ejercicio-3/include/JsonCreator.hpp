#pragma once
#include "Data.hpp"

class JsonCreator{
    private:
        Data data;
        void printDoubleVector() const;
        void printStringVector() const;
        void printListVector() const;
    public:
        JsonCreator(Data data);
        void printJson() const;
};