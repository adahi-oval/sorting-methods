#include <iostream>
#include <fstream>
#include <string>

#include "Methods.h"
#include "Sequence.h"
#include "Functions.h"
#include "Nif.h"

typedef NIF Key;
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

  // Se crean los objetos
  staticSequence<Key> sequence(size);
  if (traceFlag) {
    sequence.setTrace(true);
  }

  if (insertMethod == "random") {
    std::srand(std::time(0));
    for (int i = 0; i < size; i++)
    {
      Key placeholder; // Constructor por defecto random
      sequence.insert(placeholder);
    }
  } else if (insertMethod == "manual") {
    std::cout << "Introduzca los " << size << " NIF de la secuencia: " << std::endl;
    for (int i = 0; i < size; i++)
    {
      std::string inputString;
      std::cout << i << ": ";
      std::cin >> inputString;

      Key input(inputString);
      std::cout << input.getOriginal() << std::endl;
      sequence.insert(input);
    }
  } else if (insertMethod == "file") {
    std::ifstream file(filename);
    if (!file.is_open()) {
      std::cerr << "No se pudo abrir el archivo." << std::endl;
      return 1;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
      lines.push_back(line);
    }

    file.close();

    for (int i = 0; i < size; i++)
    {
      Key input(lines[i]);
      sequence.insert(input);
    }
  }

  std::cout << "Inicio: ";
  sequence.print();
  std::cout << std::endl;
  
  if(ordMethod == 1) {
    SelectSort<Key> ordMain(sequence, size);
    ordMain.Sort();

    std::cout << std::endl << "Final: ";
    ordMain.print();
  } else if (ordMethod == 2) {
    QuickSort<Key> ordMain(sequence, size);
    ordMain.Sort();

    std::cout << std::endl << "Final: ";
    ordMain.print();
  } else if (ordMethod == 3) {
    HeapSort<Key> ordMain(sequence, size);
    ordMain.Sort();

    std::cout << std::endl << "Final: ";
    ordMain.print();
  } else if (ordMethod == 4) {
    ShellSort<Key> ordMain(sequence, size);
    ordMain.Sort();

    std::cout << std::endl << "Final: ";
    ordMain.print();
  } else if (ordMethod == 5) {
    RadixSort<Key> ordMain(sequence, size);
    ordMain.Sort();

    std::cout << std::endl << "Final: ";
    ordMain.print();
  } else {
    throw std::out_of_range("1. Seleccion 2. QuickSort 3. HeapSort 4. ShellSort 5. RadixSort"); 
  }

  return 0;
}
