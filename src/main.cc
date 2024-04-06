// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Algoritmos y Estructuras de Datos Avanzadas
// Curso: 2o
// Práctica 4: Implementación de Tabla Hash
// Autor: Laura Inés González González
// Correo: alu0101332819@ull.edu.es
//
// Archivo main.cc

#include <iostream>

#include "../include/HashTable.h"
#include "../include/DispersionFunction.h"
#include "../include/ExplorationFunction.h"
#include "../include/Sequence.h"
#include "../include/Clave.h"

typedef long Key;
int main(void) {
  DispersionFunction<Key>* dispersion;
  ExplorationFunction<Key>* exploration = nullptr;
  
  int table_size;
  // Se pide el tamaño de la tabla.
	std::cout << "\nIntroduzca el tamaño que desee para la Tabla Hash:" << std::endl;
	std::cin >> table_size;
	
  int disp = 0;
  // Se pide la función de dispersión a usar.
	std::cout << "\nSeleccione el tipo de función de dispersión entre:\n(1) Módulo.\n(2) Suma.\n(3) Pseudoaleatoria." << std::endl;
	std::cin >> disp;

  while (disp < 1 || disp > 3) {
	  std::cout << "\nERROR: Para la función de dispersión debe elegir una de las opciones anteriores (1), (2) ó (3). Por favor, inténtelo de nuevo." << std::endl;
	  std::cout << "Seleccione el tipo de función de dispersión entre:\n(1) Módulo.\n(2) Suma.\n(3) Pseudoaleatoria." << std::endl;
    std::cin >> disp;
	}

  switch (disp) {
    case 1:
      dispersion = new fdModule<Key>(table_size);
      break;
    case 2:
      dispersion = new fdSuma<Key>(table_size);
      break;
    case 3:
      dispersion = new fdPseudoaleatoria<Key>(table_size);
      break;
  }
  
  int seqq = 0;
  // Se pide la técnica de dispersión a usar.
  std::cout << "\nSeleccione la técnica de dispersión entre:\n(1) Abierta.\n(2) Cerrada." << std::endl;
  std::cin >> seqq;
	
  while (seqq < 1 || seqq > 2) {
	  std::cout << "\nERROR: Para la función de dispersión debe elegir una de las opciones anteriores (1) ó (2). Por favor, inténtelo de nuevo." << std::endl;
	  std::cout << "Seleccione la técnica de dispersión entre:\n(1) Abierta.\n(2) Cerrada." << std::endl;
    std::cin >> seqq;
	}
  
  int block_size = 0;
  // Si se elige la técnica de dispersión cerrada.
  if (seqq == 2) {
    // Se pide el tamaño del bloque.
    std::cout << "\nIntroduzca el tamaño que desee para el bloque:" << std::endl;
    std::cin >> block_size;

    int expl = 0;
    // Se pide el tipo de función de exploración.
    std::cout << "\nSeleccione el tipo de función de exploración entre:\n(1) Lineal.\n(2) Cuadrática.\n(3) Dispersión Doble (en caso de escoger esta opción, la segunda dispersión será la misma).\n(4) Redispersión." << std::endl;
    std::cin >> expl;

    while (expl < 1 || expl > 4) {
      std::cout << "\nERROR: Para la función de exploración debe elegir una de las opciones anteriores (1), (2), (3) ó (4). Por favor, inténtelo de nuevo." << std::endl;
      std::cout << "Seleccione el tipo de función de exploración entre:\n(1) Lineal.\n(2) Cuadrática.\n(3) Dispersión Doble (en caso de escoger esta opción, la segunda dispersión será la misma).\n(4) Redispersión." << std::endl;
      std::cin >> expl;
    }

    switch (expl) {
      case 1:
        exploration = new feLineal<Key>;
        break;
      case 2:
        exploration = new feCuadratic<Key>;
        break;
      case 3:
        exploration = new feDoubleDispersion<Key>(*dispersion);
        break;
      case 4:
        exploration = new feReDispersion<Key>;
        break;
    }
  }
	
  // Se crea la Tabla Hash.
  HashTable<Key> *hash = new HashTable<Key>(exploration, dispersion, table_size, block_size);
  long *vector = new long[table_size];

  int opcion;
  // Se crea el menú interactivo.
  do {
    std::cout << "\nA continuación, se muestra el menú de opciones:\n(1) Insertar una clave.\n(2) Buscar una clave.\n(3) Salir del programa." << std::endl;
    std::cin >> opcion;
    switch (opcion) {
      case 1:
        Key key_;
        std::cout << "\nPor favor, introduzca la clave que desea insertar:" << std::endl;
        std::cin >> key_;
        if (hash->insert(key_)) {
          std::cout << "Se ha insertado la clave '" << key_ << "' correctamente." << std::endl;
        } else {
          std::cout << "No se pudo insertar la clave '" << key_ << "'." << std::endl;
        }
        break;
      case 2:
        std::cout << "\nPor favor, introduzca la clave que desea buscar:" << std::endl;
        std::cin >> key_;
        std::cout << (hash->search(key_) ? "¡Clave encontrada con éxito!" : "No se ha encontrado la clave solicitada.") << std::endl; 
        break;
      case 3:
        std::cout << "\nSe ha salido del programa correctamente." << std::endl;
        break;
      default:
        std::cout << "\nLa opción introducida no es válida, debe elegir una de entre las opciones anteriores (1), (2) ó (3). Por favor, inténtelo de nuevo.";
    }
  } while (opcion != 3);
}