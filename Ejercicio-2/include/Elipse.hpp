#include "Punto.hpp"

class Elipse {
    private:
        Punto centro; //Centro de la elipse
        float a; //Semieje mayor
        float b; //Semieje menor
    public:
        Elipse(float x, float y, float a, float b);
        void setSemiejeMayor(float a);
        float getSemiejeMayor() const;
        void setSemiejeMenor(float b);
        float getSemiejeMenor() const;
        ~Elipse() = default;
};