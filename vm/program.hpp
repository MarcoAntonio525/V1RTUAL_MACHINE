#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include "Instruccion.hpp"
#include <string>

class Program {
private:
    static const int MAX_INSTRUCTIONS = 10;
    Instruccion instructions[MAX_INSTRUCTIONS];  // instrucciones
    int operand1[MAX_INSTRUCTIONS];              // primer operando
    int operand2[MAX_INSTRUCTIONS];              // segundo operando
    int size;                                     // cantidad real
    
public:
    Program();
    bool addInstruction(Instruccion theInstruction, int op1, int op2);
    Instruccion getInstruction(int position) const;  
    int getSize() const;
    int getOperand1(int position) const;
    int getOperand2(int position) const;
};

#endif