#include "InstruccionSet.hpp"

InstruccionSet::InstruccionSet()
{
	index = 0;
}


bool InstruccionSet::addInstruction(const Instruccion& theInstruction)
{
	if (index >= 10) {
        return false;  
    }
	set[index++] = theInstruction;
	return true;
}


Instruccion InstruccionSet::getInstruction(short int pos)
{
	if (pos < 0 || pos >= index) {
        // Podrías devolver una instrucción vacía o manejar el error
        return Instruccion();
    }
	return set[pos];
}