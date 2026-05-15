#ifndef INSTRUCCION_HPP
#define INSTRUCCION_HPP

#include <string>

using namespace std;
class Instruccion{
    private:
        string name;
        short int code;
        short int lenght;

    public:
        Instruccion();
        Instruccion(string Name, short int Code, short int Lenght);
        void display();
        int getCode() const;
        string getName() const;
        short int getLenght() const;
};
#endif
