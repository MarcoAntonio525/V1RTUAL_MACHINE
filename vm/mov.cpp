#include "MOV.hpp"
#include <iostream>


// MOV.cpp
MOV::MOV() : Instruccion("MOV", 5, 2), regist(""), address(""), value(0) {}

MOV::MOV(string name, short int code, short int length, string theRegist, string theAddress) 
    : Instruccion(name, code, length), regist(theRegist), address(theAddress), value(0) {}

MOV::MOV(string name, int theValue, string theRegister) 
    : Instruccion("MOV", 5, 2), regist(theRegister), address(""), value(theValue) {}

int MOV::getValue() { return value; }
string MOV::getRegist() { return regist; }
string MOV::getAddress() { return address; }

void MOV::display() {
    if (!address.empty())
        cout << regist << ", " << address << endl;
    else
        cout << regist << ", " << value << endl;
}

