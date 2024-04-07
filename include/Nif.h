#include <string>
#include <stdexcept>

class NIF {
private:
  long nums;
  char letra;
  int letraAscii;
  std::string originalString;

public:
  NIF(std::string nifString) {
    if (!isValidNif(nifString))
    {
      throw std::invalid_argument("NIF inválido. Debe ser 8 números seguidos de una letra.");
    } else
    {
      nums = std::stol(nifString.substr(0,8));
      letra = nifString[nifString.length() - 1];
      letraAscii = letra;
      if (letraAscii < 65 || letraAscii > 90)
      {
        throw std::invalid_argument("NIF inválido. Debe ser 8 números seguidos de una letra mayúscula.");
      }
      
    }
  }

  long getNums() {
    return nums;
  }

  char getLetra() {
    return letra;
  }

  std::string getOriginal() {
    return originalString;
  }

  // Método para comprobar si un string es válido, comprueba la longitud, los 8 primeros caracteres y el ultimo por separado
  bool isValidNif(std::string nifString) {
    bool result = true;

    if (nifString.length() != 9)
    {
      result = false;
    } else
    {
      for (int i = 0; i < nifString.length() - 1; i++)
      {
        if (!isdigit(nifString[i])) { result = false; }
      }
      if (!std::isalpha(nifString[nifString.length() - 1])) { result = false; }
    }

    return result;
  }

  // Sobrecarga de operadores

  // Comparación
  bool operator==(const NIF& otro) const {
    return originalString == otro.originalString;
  }

  bool operator!=(const NIF& otro) const {
    return originalString != otro.originalString;
  }

  bool operator<(const NIF& otro) const {
    if (nums < otro.nums) { return true; } 
    else if (nums == otro.nums) {
      if (letraAscii < otro.letraAscii){ return true; }
    } else { return false; }
  }

  bool operator>(const NIF& otro) const {
    if (nums > otro.nums) { return true; } 
    else if (nums == otro.nums) {
      if (letraAscii > otro.letraAscii){ return true; }
    } else { return false; }
  }

  bool operator<=(const NIF& otro) const {
    if (nums < otro.nums) { return true; } 
    else if (nums == otro.nums) {
      if (letraAscii <= otro.letraAscii){ return true; }
    } else { return false; }
  }

  bool operator>=(const NIF& otro) const {
    if (nums > otro.nums) { return true; } 
    else if (nums == otro.nums) {
      if (letraAscii >= otro.letraAscii){ return true; }
    } else { return false; }
  }

};