
/* APS105-W23 Lab 2 Part 4
//
// Program that reads in an encoded 4-digit combination, and
// prints the original combination. 

A combination is simply encrypted by swapping the 1st and 4th digits
and replacing the 2nd and the 3rd digits by their 9's complement.

input 8021; output 1978 Y

9's complement definition; 9 - the digit

input 1872; output 2121 Y
input 0990; output 0000 Y
input 9159; output 9849 Y

//
// Assumption: The input is a valid 4-digit integer
// The program works for 0000, but not for other numbers!
*/ 

#include <stdio.h>

int main(void) {
    int d4 = 0;
    int d3 = 0;
    int d2 = 0;
    int d1 = 0;
  
  double encComb;
  printf("Enter an encrypted 4-digit combination: ");
  scanf("%lf", &encComb);

  // Determine the 4 digits of the encrypted combination. something probably goes wrong here
 
        encComb = encComb / 1000; //integer division
            d4 = (int)encComb % 1000;
        encComb = encComb * 10;
            d3 = (int)encComb % 10;
        encComb = encComb * 10;
            d2 = (int)encComb % 10;
        encComb = encComb * 10;
            d1 = (int)encComb % 10;

  // printing the decrypted combination: d4 and d1 are swapped. d3 and d2 are
  // are 9's complemented
  printf("\nThe real combination is: %d%d%d%d\n", d1, 9 - d3, 9 - d2, d4);

  return 0;
}
