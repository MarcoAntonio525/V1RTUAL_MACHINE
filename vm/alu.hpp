#ifndef ALU_HPP
#define ALU_HPP

class ALU
{
private:
    short int op1;
    short int op2;

public:
    ALU();
    ALU(short int Op1, short int Op2);
    
    short int add(short int theOperand1, short int theOperand2);
    short int sub(short int theOperand1, short int theOperand2);
    short int mul(short int theOperand1, short int theOperand2);
    short int div(short int theOperand1, short int theOperand2);
};

#endif