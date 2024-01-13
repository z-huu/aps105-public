/* Part 1 - Kaprekar's Constant

when you take any four digit number (with at least 2 different digits)
and obtain two new numbers by rearranging the digits in ascending and descending order

and do bigger number - smaller number over and over again, it will eventually converge
to the number 6174

goal; given a user input of a positive four digit integer (with at least two different digits)
output the number of iterations needed to reach the convergence of 6174

    erorr checking; output error message if user input has less or more than four digits




*/

#include <stdio.h>


//function declaration
int inputChecker (int);
int iterator (int, int);
int getDescendingOrderDigits (int);

//remove this definition afterwards
int getAscendingOrderDigits (int);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


int main (void) {

int userInput = 0, ascendingDigits, descendingDigits, iterationCount = 0, invalidInput = 0;

    printf("Enter a number (-1 to stop): ");
    scanf("%d", &userInput);

    if (userInput == -1) {


    } else {

        while (userInput != -1) {

            //check user input

            invalidInput = inputChecker(userInput);

            if (invalidInput == 1) { //if userInput is too small

                printf("Error: The number is too small.");

            } else if (invalidInput == 2) { //if userInput is too large

                printf("Error: The number is too large.");

            } else {

                printf("Number 1: %d\n", userInput);

            ascendingDigits = getAscendingOrderDigits(userInput);
            descendingDigits = getDescendingOrderDigits(userInput);

                if (userInput == 6174) {

                    iterationCount = 0;

                } else {

                    iterationCount = iterator(ascendingDigits, descendingDigits);

                }
            
            printf("Kaprekar's Constant was reached in %d iteration(s)", iterationCount);

            }
        
                printf("\nEnter a number (-1 to stop): ");
                scanf("%d", &userInput);
    
            }


        return 0;
    }
    return 0;
}



int inputChecker (int userInput) {

    int digitCount = 0;

    //given userInput, count # of digits and return error message if number of digits != 4
    while (userInput >= 1) {

        userInput = userInput/10;
        digitCount = digitCount+1;
    }

        if (digitCount == 4) {

            return 0;

        } else if (digitCount < 4) {

            return 1;
            
        } else {

            return 2;

        }


}

//delete this ascendingOrder function definition after

int getAscendingOrderDigits(int number) { //both digit rearranging functions are not accounting for 0 digits
    int digits[10] = {0};

    while (number > 0) {
        digits[number % 10]++;
        number /= 10;
    }
        int i = 0;

    while (i < 10) {
        if (digits[i] > 0) {

        number *= 10;
        number += i;
        digits[i]--;

        } else {
            i++;
        }
    }

    return number;
}

int getDescendingOrderDigits(int number) {
int digits[10] = {0};
    while (number > 0) {
        digits[number % 10]++;
        number /= 10;
    }

        int i = 9;
    while (i >= 0 ) {
        if (digits[i] > 0) {
            number *= 10;
            number += i;
            digits[i]--;
        } else {
            i--;
        }
    }

    if (number < 1000) {
        number = number*10;

    }

return number;
}

int iterator (int ascendingDigits, int descendingDigits) { //finish

    //ran after input is verified, so assume userInput has four digits
    int difference=0, iterationCount=0;

    while (difference != 6174) {

        if (ascendingDigits > descendingDigits) { //subtracting smaller number from bigger number

            difference = ascendingDigits - descendingDigits;
        
        } else if (descendingDigits > ascendingDigits) {

            difference = descendingDigits - ascendingDigits;

        } else if (ascendingDigits == descendingDigits) {

            difference = ascendingDigits - descendingDigits;

        }
    
        ascendingDigits = getAscendingOrderDigits(difference);
        descendingDigits = getDescendingOrderDigits(difference);
        iterationCount++;

        printf("Number %d: %d\n", (iterationCount+1), difference);

    }
    
    return iterationCount;
}