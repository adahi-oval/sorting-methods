#pragma once

#include "Sequence.h"
#include "Functions.h"

template<typename Key>
class SortMethod {
protected:
  staticSequence<Key>& sequence;
  int size;

public:
  SortMethod(staticSequence<Key>& seq, int s) : sequence(seq), size(s) {}

  virtual void Sort() const = 0;

  staticSequence<Key> getSequence() {
    return this->sequence;
  }

  void print() {
    this->sequence.print();
  }

};

template<typename Key>
class SelectSort : public SortMethod<Key> {
public:
  SelectSort(staticSequence<Key>& seq, int s) : SortMethod<Key>(seq, s) {}

  void Sort() const override {
    this->sequence = selectionSort(this->sequence, this->size);
  }
};

template<typename Key>
class QuickSort : public SortMethod<Key> {
public:
  QuickSort(staticSequence<Key>& seq, int s) : SortMethod<Key>(seq, s) {}

  void Sort() const override {
    this->sequence = quickSort(this->sequence, this->size);
  }
};

template<typename Key>
class HeapSort : public SortMethod<Key> {
public:
  HeapSort(staticSequence<Key>& seq, int s) : SortMethod<Key>(seq, s) {}

  void Sort() const override {
    this->sequence = heapSort(this->sequence, this->size);
  }
};

template<typename Key>
class ShellSort : public SortMethod<Key> {
private:
  double alpha;

public:
  ShellSort(staticSequence<Key>& seq, int s) : SortMethod<Key>(seq, s) {
    std::cout << "Introduzca alpha (0 < alpha < 1): " << std::endl;
    std::cin >> alpha;
    if (alpha <= 0 || alpha >= 1)
    {
      throw std::out_of_range("Alpha debe estar entre 0 y 1.");
    }
  }

  void Sort() const override {
    this->sequence = shellSort(this->sequence, this->size, this->alpha);
  }
};

template<typename Key>
class RadixSort : public SortMethod<Key> {
public:
  RadixSort(staticSequence<Key>& seq, int s) : SortMethod<Key>(seq, s) {}

  void Sort() const override {
    this->sequence = radixSort(this->sequence, this->size);
  }
};