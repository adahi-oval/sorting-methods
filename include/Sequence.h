#pragma once

#include <iostream>
#include <vector>

template<class Key>
class Sequence {
public:
  virtual bool search(const Key& k) const = 0;
  virtual bool insert(const Key& k) = 0;
  virtual Key operator[](int index) const = 0;
};

template<class Key>
class staticSequence : public Sequence<Key> {
private:
  std::vector<Key> keyVector;
  int maxSize;
  bool traceFlag = false;
  int iterationCount = 0;

public:

  staticSequence(int size) {
    maxSize = size;
  }

  void setTrace(bool trace_) {
    this->traceFlag = trace_;
  }

  // Método de búsqueda
  bool search(const Key& k) const override {
    for (int i = 0; i < keyVector.size(); ++i) {
      if (keyVector[i] == k) {
        return true;
      }
    }
    return false;
  }

  // Método para inserción
  bool insert(const Key& k) override {
    if (keyVector.size() < maxSize)
    {
      keyVector.push_back(k);
      return true;
    }
    return false;
  }

  // Operador de acceso a posición
  Key operator[](int index) const override {
    if (index >= 0 && index < keyVector.size()) {
      return keyVector[index];
    } else {
      throw std::out_of_range("La posición a la que intenta acceder está fuera de rango.");
    }
  }

  // Sobrecarga del operador de asignación
  staticSequence& operator=(const staticSequence& other) {
    keyVector = other.keyVector;
    maxSize = other.maxSize;
    return *this;
  }

  // Método at para obtener referencias modificables
  Key& at(int index) {
    if (index >= 0 && index < keyVector.size()) {
      return keyVector.at(index);
    } else {
      throw std::out_of_range("La posición a la que intenta acceder está fuera de rango.");
    }
  }

  // Método swap, para los intercambios en el vector interno de sequence
  void swap(int index1, int index2) {
    Key temp = this->keyVector[index1];
    this->keyVector[index1] = this->keyVector[index2];
    this->keyVector[index2] = temp;
  }

  // Método para imprimir la secuencia
  void print() {
  for (int i = 0; i < this->maxSize; ++i) {
    std::cout << this->at(i) << " ";
  }
  std::cout << std::endl;
  }

  // Método auxiliar para hacer la traza más simple
  void trace() {
    if (this->traceFlag)
    {
      std::cout << this->iterationCount << ": ";
      this->print();
      this->iterationCount++;
    }
  }

};
