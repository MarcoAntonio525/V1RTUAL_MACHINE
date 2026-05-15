#include "Instruccion.hpp"
#include <iostream>

Instruccion::Instruccion() {}


Instruccion::Instruccion(string theName, short int theCode, short int theLength) 
{
	name = theName;
	code = theCode;
	lenght = theLength;
}


void Instruccion::display()
{
	cout << name <<"," << code << "," << lenght << endl;
}

int Instruccion::getCode() const
{
	return code;
}

string Instruccion::getName() const
{
	return name;
}

short int Instruccion::getLenght() const {
    return lenght;
}