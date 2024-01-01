/* Part 3 - Conversion to Base 2 Assignment

inputs ~~~~~~~~~~~~~~
    INTEGER number to convert to base 2 (NO BIGGER THAN 15)
        account for input of 0
        can assume that input is positive, inputs are integers
outputs ~~~~~~~~~~~~~~~~~
    each digit of the input's base 2 representation, outputted LINE BY LINE
        always output FOUR digits, regardless of how many bits required

*/

#include <stdio.h>

int main() {

    int inputInt;
    int digit1 = 0;
    int digit2 = 0;
    int digit3 = 0;
    int digit4 = 0;
    int result1 = 0;
    int result2 = 0;
    int result3 = 0;
   

        //ask user to input integer
        printf("Enter number to convert to base 2: ");
        scanf("%d", &inputInt);

        //perform repeated division to obtain digit values  
        result1 = inputInt/2;
        result2 = result1/2;
        result3 = result2/2;
        
        digit4 = inputInt%2;    //bit0
        digit3 = result1%2;     //bit1
        digit2 = result2%2;     //bit2
        digit1 = result3%2;     //bit3

    //output first digit

        printf("The four digits of that number are as follows:");
        printf("\nMost significant digit: ");
        printf("%d", digit1);
    
    //output second digit
        printf("\nNext digit: ");
        printf("%d", digit2);

    //output third digit
        printf("\nNext digit: ");
        printf("%d", digit3);

    //output fourth digit
        printf("\nLeast significant digit: ");
        printf("%d",digit4);

    return 0;
}