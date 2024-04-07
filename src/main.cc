#include <iostream>
#include <string>

#include "Methods.h"
#include "Sequence.h"
#include "Functions.h"
#include "Nif.h"

typedef int Key;
int main(int argc, char* argv[]) {
  int size;
  int ordMethod;
  std::string insertMethod;
  std::string filename = "";
  bool traceFlag = false;

  if (argc > 10 || argc < 9) {
    std::cerr << "Uso: " << argv[0] << " -size <s> -ord <m> -init <i> [f] -trace <y|n>" << std::endl;
    return 1;
  }

  for (int i = 1; i < argc; ++i) {
    std::string option(argv[i]);
    if (option == "-size") {
      size = std::stoi(argv[++i]);
    } else if (option == "-ord") {
      ordMethod = std::stoi(argv[++i]);
    } else if (option == "-init") {
      insertMethod = argv[++i];
      if (insertMethod == "file")
      {
        filename = argv[++i];
      }
    } else if (option == "-trace") {
      traceFlag = (std::string(argv[++i]) == "y");
    } else {
      std::cerr << "Opción no válida: " << option << std::endl;
      std::cerr << "Uso: " << argv[0] << " -size <s> -ord <m> -init <i> [f] -trace <y|n>" << std::endl;
      return 1;
    }
  }

  std::cout << "Size: " << size << std::endl;
  std::cout << "Ordenación: " << ordMethod << std::endl;
  std::cout << "Inicialización: " << insertMethod << std::endl;
  std::cout << "Trace: " << (traceFlag ? "yes" : "no") << std::endl;
  std::cout << filename << std::endl;

  return 0;
}
