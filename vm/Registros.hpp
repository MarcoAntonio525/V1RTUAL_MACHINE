#ifndef REGISTROS_HPP
#define REGISTROS_HPP

class Registros {
private:
    // Proposito General (8 bits: AL, AH, BL, BH)
    int AL, AH, BL, BH;
    
    
    int AX, BX, CX, DX;  // propósito general extendido
    
    // Proposito Específico
    int PC;   // Program Counter
    int IR;   // Instruction Register
    int MBR;  // Memory Buffer Register
    int MAR;  // Memory Address Register
    
    int AC;   // Accumulator (para resultados)
    
public:
    Registros();
    
    // Getters-Setters Proposito General
    int getAL() const;
    void setAL(int value);
    int getAH() const;
    void setAH(int value);
    int getBL() const;
    void setBL(int value);
    int getBH() const;
    void setBH(int value);
    
    // Getters-Setters Proposito Específico
    int getPC() const;
    void setPC(int value);
    void incrementPC();
    
    int getIR() const;
    void setIR(int value);
    
    int getMBR() const;
    void setMBR(int value);
    
    int getMAR() const;
    void setMAR(int value);
    
    int getAC() const;
    void setAC(int value);
    
    // Utilidad
    void reset();
    void display() const;
};

#endif