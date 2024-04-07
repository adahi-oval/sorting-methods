#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include "Sequence.h" // Suponiendo que tienes la definición de staticSequence en un archivo header separado

// Implementación del algoritmo de selección
template<typename Key>
staticSequence<Key> selectionSort(staticSequence<Key>& sequenceOriginal, int size) {
  staticSequence<Key> sequence = sequenceOriginal;

  for (int i = 0; i < size - 1; ++i) {
    int minIndex = i;
    for (int j = i + 1; j < size; ++j) {
      if (sequence[j] < sequence[minIndex]) {
        minIndex = j;
      }
    }
    sequence.swap(i, minIndex);
    sequence.trace();
  }

  return sequence;
}

// Implementación del algoritmo de ordenación rápida (QuickSort)
template<typename Key>
void quickSortHelper(staticSequence<Key>& sequence, int low, int high) {
  if (low < high) {
    int pivot = low;
    int i = low + 1;
    int j = high;
    while (i <= j) {
      while (i <= high && sequence[i] <= sequence[pivot]) {
        ++i;
      }
      while (j > low && sequence[j] >= sequence[pivot]) {
        --j;
      }
      if (i < j) {
        sequence.swap(i, j);
      }
    }
    sequence.swap(j, pivot);
    sequence.trace();
    quickSortHelper(sequence, low, j - 1);
    quickSortHelper(sequence, j + 1, high);
  }
}

template<typename Key>
staticSequence<Key> quickSort(staticSequence<Key>& sequenceOriginal, int size) {
  staticSequence<Key> sequence = sequenceOriginal;
  quickSortHelper(sequence, 0, size - 1);
  return sequence;
}

// Implementación del algoritmo de ordenación por montículos (HeapSort)
template<typename Key>
void heapify(staticSequence<Key>& sequence, int size, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < size && sequence[left] > sequence[largest]) {
    largest = left;
  }

  if (right < size && sequence[right] > sequence[largest]) {
    largest = right;
  }

  if (largest != i) {
    sequence.swap(i, largest);
    sequence.trace();
    heapify(sequence, size, largest);
  }
}

template<typename Key>
staticSequence<Key> heapSort(staticSequence<Key>& sequenceOriginal, int size) {
  staticSequence<Key> sequence = sequenceOriginal;

  for (int i = size / 2 - 1; i >= 0; --i) {
    heapify(sequence, size, i);
  }
  for (int i = size - 1; i > 0; --i) {
    sequence.swap(0, i);
    sequence.trace();
    heapify(sequence, i, 0);
  }

  return sequence;
}

// Implementación del algoritmo de ordenación ShellSort
template<typename Key>
staticSequence<Key> shellSort(staticSequence<Key>& sequenceOriginal, int size, double alpha) {
  staticSequence<Key> sequence = sequenceOriginal;
  
  int gap = size / 2;
  while (gap > 0) {
    for (int i = gap; i < size; ++i) {
      Key temp = sequence.at(i);
      int j;
      for (j = i; j >= gap && sequence[j - gap] > temp; j -= gap) {
        sequence.at(j) = sequence.at(j - gap);
      }
      sequence.at(j) = temp;
    }
    gap *= alpha;
    sequence.trace();
  }

  return sequence;
}

// Implementación del algoritmo de ordenación RadixSort
template<typename Key>
staticSequence<Key> radixSort(staticSequence<Key>& sequenceOriginal, int size) {

  staticSequence<Key> sequence = sequenceOriginal;

  Key maxVal = sequence[0];
  for (int i = 1; i < size; ++i) {
    if (sequence[i] > maxVal) {
      maxVal = sequence[i];
    }
  }

  for (int exp = 1; maxVal / exp > 0; exp *= 10) {
    std::vector<Key> output(size);
    std::vector<int> count(10, 0);

    for (int i = 0; i < size; ++i) {
      count[(sequence[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; ++i) {
      count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; --i) {
      output[count[(sequence[i] / exp) % 10] - 1] = sequence[i];
      count[(sequence[i] / exp) % 10]--;
    }

    for (int i = 0; i < size; ++i) {
      sequence.at(i) = output[i];
    }

    sequence.trace();
  }

  return sequence;
};
