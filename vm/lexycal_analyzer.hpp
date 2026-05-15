#ifndef LEXICAL_ANALYZER_HPP
#define LEXICAL_ANALYZER_HPP

#include <string>
#include <vector>

struct Token {
    std::string value;
    std::string type;  // "INSTRUCTION", "REGISTER", "NUMBER", "ADDRESS"
};

class LexicalAnalyzer {
public:
    LexicalAnalyzer();
    
    // Analiza una línea de código fuente
    std::vector<Token> analyze(const std::string& line);
    
    // Identifica el tipo de instrucción y devuelve su código
    int getInstructionCode(const std::string& instruction);
    
    // Obtiene el valor numérico de un operando
    int getOperandValue(const std::string& token);
    
    // Divide la línea en tokens
    std::vector<std::string> tokenize(const std::string& line);
    
    // Identifica el tipo de token
    std::string identifyToken(const std::string& token);
    
    // Verifica si es un número
    bool isNumber(const std::string& token);
    
    // Verifica si es un registro
    bool isRegister(const std::string& token);
};

#endif