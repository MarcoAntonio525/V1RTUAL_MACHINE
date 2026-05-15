#include "ALU.hpp"

ALU::ALU() : op1(0), op2(0) {}

ALU::ALU(short int theOperand1, short int theOperand2)
{
    op1 = theOperand1;
    op2 = theOperand2;
}

short int ALU::add(short int theOperand1, short int theOperand2)
{
    return theOperand1 + theOperand2;
}

short int ALU::sub(short int theOperand1, short int theOperand2)
{
    return theOperand1 - theOperand2;
}

short int ALU::mul(short int theOperand1, short int theOperand2)
{
    return theOperand1 * theOperand2;
}

short int ALU::div(short int theOperand1, short int theOperand2)
{
    if (theOperand2 == 0)
    {
        return 0;  // Manejo simple de división por cero
    }
    return theOperand1 / theOperand2;
}