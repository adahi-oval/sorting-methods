#include <iostream>

#include "Methods.h"
#include "Sequence.h"
#include "Functions.h"

typedef int Key;
int main(void) {
  staticSequence<int> test(5);

  test.insert(123);
  test.insert(25);
  test.insert(31);
  test.insert(4);
  test.insert(59);

  printSequence(test, 5);

  RadiSort<int> sort1(test, 5);

  sort1.Sort();

  printSequence(sort1.getSequence(), 5);

}