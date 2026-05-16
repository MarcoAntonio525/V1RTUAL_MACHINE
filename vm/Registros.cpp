#include "Registros.hpp"
#include <iostream>

Registros::Registros() {
    reset();
}

void Registros::reset() {
    AL = AH = BL = BH = 0;
    AX = BX = CX = DX = 0;
    PC = 0;
    IR = 0;
    MBR = 0;
    MAR = 0;
    AC = 0;
}

int Registros::getAL() const { return AL; }
void Registros::setAL(int value) { AL = value; }

int Registros::getAH() const { return AH; }
void Registros::setAH(int value) { AH = value; }

int Registros::getBL() const { return BL; }
void Registros::setBL(int value) { BL = value; }

int Registros::getBH() const { return BH; }
void Registros::setBH(int value) { BH = value; }

int Registros::getPC() const { return PC; }
void Registros::setPC(int value) { PC = value; }
void Registros::incrementPC() { PC++; }

int Registros::getIR() const { return IR; }
void Registros::setIR(int value) { IR = value; }

int Registros::getMBR() const { return MBR; }
void Registros::setMBR(int value) { MBR = value; }

int Registros::getMAR() const { return MAR; }
void Registros::setMAR(int value) { MAR = value; }

int Registros::getAC() const { return AC; }
void Registros::setAC(int value) { AC = value; }

void Registros::display() const {
    std::cout << "=====================" << std::endl;
    std::cout << "REGISTROS:" << std::endl;
    std::cout << "  [Propósito General]" << std::endl;
    std::cout << "    AL = " << AL << "   AH = " << AH << std::endl;
    std::cout << "    BL = " << BL << "   BH = " << BH << std::endl;
    std::cout << "  [Propósito Específico]" << std::endl;
    std::cout << "    PC  = " << PC << std::endl;
    std::cout << "    IR  = " << IR << std::endl;
    std::cout << "    MAR = " << MAR << std::endl;
    std::cout << "    MBR = " << MBR << std::endl;
    std::cout << "    AC  = " << AC << std::endl;
    std::cout << "=====================" << std::endl;
}
