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

public:

  staticSequence(int size) {
    maxSize = size;
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
    if (keyVector.size < maxSize)
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
      throw std::out_of_range('La posición a la que intenta acceder está fuera de rango.');
    }
  }
};
