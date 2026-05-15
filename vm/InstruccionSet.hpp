#ifndef INSTRUCTIONSET_HPP
#define INSTRUCTIONSET_HPP

#include "Instruccion.hpp"

using namespace std;

class InstruccionSet
{
	private:
		Instruccion set[10];
		short int index;
	
	public:
		InstruccionSet();
		bool addInstruction(const Instruccion& theInstruction);
		Instruccion getInstruction(short int pos);
};

#endif