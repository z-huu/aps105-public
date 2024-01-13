//function testing zone

#include <stdbool.h>
#include <stdio.h>

bool isShuffled(int);
int getNumDigits(int);
int getSmallestDigit(int);
bool lookForDigit(int, int);

int main (void) {

  //lets test getSmallestDigit
  int num1 = 123;
  int num2 = 991;
  int num3 = 111;

  //int smallest1 = getSmallestDigit(num1);
  int smallest2 = getSmallestDigit(num2);
  //int smallest3 = getSmallestDigit(num3);

  printf("%d", smallest2);
}

bool isShuffled(int shuffledOrder) {
  bool isShuffled = true;
  int numOfDigits = getNumDigits(shuffledOrder);
  int smallestDigit = getSmallestDigit(shuffledOrder);

  for (int place = 1; place <= numOfDigits && isShuffled; place++) {
    if (!lookForDigit(shuffledOrder, smallestDigit + place)) {
      isShuffled = false;
    }
  }
  return shuffledOrder;
}


int getNumDigits(int num) { // LOOKS GOOD ;3
  int count = 0;
  while (num > 0) {
    num = num / 10;
    count++;
  }
  return count;
}

int getSmallestDigit(int num) {
  int smallestDigit = 0;
  int digit = 0;
  while (num != 0) {
    digit = num % 10;
    if (digit < smallestDigit) {
      smallestDigit = digit;
    }
    num /= 10;
  }
  return digit;
}

bool lookForDigit(int num, int searchDigit) {
  int digit = 0;
  bool foundDigit = false;
  while (num != 0 || foundDigit) {
    digit = num % 10;
    if (digit == searchDigit) {
      foundDigit = true;
    }
    num /= 10;
  }
  return digit;
}
