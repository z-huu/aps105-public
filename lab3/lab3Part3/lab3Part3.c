
// Sums all digits in a number
#include <stdbool.h>
#include <stdio.h>
// A program that takes in from the user a sequence of numbers separated
// by + or -, once their sum reaches below zero it prints out "Sum is below zero."
// You need to verify if the character entered is a number or not, and if the sign 
// is '+'' or '-'. If not, the user is asked to re-enter till a valid input is 
//taken

int main(void) {
  char userChar;
  int sum = 0, sign = +1;
  bool number = true;

  printf("Enter sequence of characters with numbers to add: ");
  
  do {

  scanf(" %c", &userChar);

    if (number) {
      while (userChar < '0' || userChar > '9') {
        printf("Invalid! Re-enter number.\n");
        scanf(" %c", &userChar);
      }
      number = false;
      sum += sign * (userChar - '0');
    } else {
      while (userChar != '+' && userChar != '-') {
        printf("Invalid! Re-enter sign.\n");
        scanf(" %c", &userChar);
      }
      number = true;
      if (userChar == '+') {
        sign = +1;
      } else {
        sign = -1;
      }
    }
  } while (sum > 0);
  printf("Sum fell below zero.\n");
  return 0;
}