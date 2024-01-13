/* Part 3 - Debugging Assignment */


#include <stdbool.h>
#include <stdio.h>

//function declaration

bool isShuffled (int shuffledOrder);

int main(void) {
  int num;
  printf("Enter the number to check: ");
  scanf("%d", &num);
  if (isShuffled(num)) {
    printf("Shuffled!");
  } else {
    printf("Not shuffled!");
  }
  return 0;
}

int getNumDigits(int num) { // LOOKS GOOD ;3
  int count = 0;
  while (num > 0) {
    num = num / 10;
    count++;
  }
  return count;
}


int getSmallestDigit(int num) { //LOOKS GOOD !!!!

  int digit = num;
  int smallestDigit = num % 10;
  //smallestDigit should be the first digit; digit should be looping num var

  while (num != 0) { 
    digit = num % 10; //fine
    if (digit < smallestDigit) { 
      smallestDigit = digit;
    }
    num /= 10; //fine
  }
  return smallestDigit; //return the SMALLESTDIGIT not the temp digit value
}

bool lookForDigit(int num, int searchDigit) { //YUP NOT BAD
  int digit;

  bool foundDigit = false;
  // the while loop should not depend if digit was found or not
  while (num != 0) { 

    digit = num % 10;
    //digit = num % 10;
    if (digit == searchDigit) {
      foundDigit = true;
    }

    num /= 10;
  }
  return foundDigit; 
  //should return the digit that was found, not the temp. digit value
}

bool isShuffled (int shuffledOrder) {
  bool isItShuffled = true;
  int numOfDigits = getNumDigits(shuffledOrder);
  int smallestDigit = getSmallestDigit(shuffledOrder);

  for (int place = 1; place <= numOfDigits && isShuffled; place++) {
    if (!lookForDigit(shuffledOrder, smallestDigit)) { 
      isItShuffled = false;
    }
    smallestDigit = smallestDigit+1;
    //if we don't increment smallestDigit, we end up not checking the rest of the inputted integer
  }
  //retrun boolean
  return isItShuffled;
}
  