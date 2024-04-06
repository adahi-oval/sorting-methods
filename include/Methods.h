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
class QuicSort : public SortMethod<Key> {
public:
  QuicSort(staticSequence<Key>& seq, int s) : SortMethod<Key>(seq, s) {}

  void Sort() const override {
    this->sequence = quickSort(this->sequence, this->size);
  }
};

template<typename Key>
class HepSort : public SortMethod<Key> {
public:
  HepSort(staticSequence<Key>& seq, int s) : SortMethod<Key>(seq, s) {}

  void Sort() const override {
    this->sequence = heapSort(this->sequence, this->size);
  }
};

template<typename Key>
class ShelSort : public SortMethod<Key> {
private:
  double alpha;

public:
  ShelSort(staticSequence<Key>& seq, int s, double alpha_) : SortMethod<Key>(seq, s) {
    alpha = alpha_;
  }

  void Sort() const override {
    this->sequence = shellSort(this->sequence, this->size, this->alpha);
  }
};

template<typename Key>
class RadiSort : public SortMethod<Key> {
public:
  RadiSort(staticSequence<Key>& seq, int s) : SortMethod<Key>(seq, s) {}

  void Sort() const override {
    this->sequence = radixSort(this->sequence, this->size);
  }
};