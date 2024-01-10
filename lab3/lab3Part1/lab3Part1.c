/* Part 1 - Numerical Bases Problem

inputs ~~~~~~~~~~~~~~~~~~`
    an operation (either +, -, *, /, or $)
        $ will signify the end of inputs
    an input base (2 to 10, inclusive)
    the first operand
        a positive integer written as a numeral in the input base
    the second operand
        another positive integer written as a numerla in the input base
    an output base (2 to 10 inclusive)

**user will ALWAYS supply five inputs and ALWAYS input $ on the sixth input

outputs ~~~~~~~~~~~~~~~~~~~~~`

    result of first operand (operator) second operand in output base

psuedo code ~~~~~~~~~~~~~~~~~~~`

take user input

check for invalid inputs 
    check if operator is invalid (store operator as string; string compare to different possible operators)
        if yes, print error message
      else if input/output base is invalid (check if base outside of 2-10 inclusive; user will supply positive integers)
        if yes, print error message
      else if input operands are invalid (verify that they are within input base)
            verify within input base by checking if each digit is <= input base
        if yes, print error message
      else, carry on 

convert user inputs from input base to base 10

    while (user input >= 10) {      while loop to read each digit of the first operand
            looping variable i, increments with each digit
            digit[i] = userinput%10
            userinput/10
            i++

            digit[] array will hold least significant digit first and most significant digit last
    }

    repeat for second operand

    convert operands to base 10;

        for loop continuing until looping varialbe k reaches i, the # of digits held in digit array
            operandOneBase10 = digit[k] * 10^k (k should start at 0, so maybe until k reaches i-1)
            i++
        
        repeat for second operand
            

perform operations

    outputBase10 = operandOneBase10  (operator)  operandTwoBase10

convert outputBase10 from base 10 to output base

    read each digit in outputBase10

        while (outputBase10 >= 10) {
            
            outputDigits[i] = (outputBase10 % outputBase)
            outputBase10 = outputBase10/outputBase
            i++ (counts number of digits, i starts at 0)

            **outputDigits starts with the right most digits and ends with the left most digits
        }

concatenate outputDigits into a single integer


print output

    output format:
    input operand (operator) input operand = operandBase10 (operator) operandBase10 = resultOutputBase

*/

//declaring functions

int operatorVerify (char);
int baseVerify (int);
int operandVerify (int, int);
int convertToBase10 (int, int);
int operatorPerform(int, int, char);
int outputConvert(int, int);

#include <stdio.h>
#include <math.h>

int main(void) {

char operator = '+';
int inputBase, operandOne, operandTwo, outputBase, base10Result, outputBaseResult, operandOneBase10, operandTwoBase10;
int invalidOperator = 0, invalidBase = 0, invalidOperand = 0;

        while (operator != '$') {

        // take in user inputs
        printf("Give input ($ to stop): ");
        scanf("%s %d %d %d %d", &operator, &inputBase, &operandOne, &operandTwo, &outputBase);

            if (operator == '$') {
                operator = '$';
            } else {

                //verify user inputs
                invalidOperator = operatorVerify(operator);
                invalidBase = baseVerify(inputBase);
                if (invalidBase == 0) {
                    invalidBase = baseVerify(outputBase);
                }
                invalidOperand = operandVerify(operandOne, inputBase);

                if (invalidOperand == 0) { //if first operand is valid, check second operand
                    invalidOperand = operandVerify(operandTwo, inputBase);
                }

                //error output message

                    if (invalidOperator == 1) {

                        printf("Invalid operator\n");
                        invalidOperator = 0, invalidBase = 0, invalidOperand = 0;

                    } else if (invalidBase == 1) {

                        printf("Invalid base\n");
                        invalidOperator = 0, invalidBase = 0, invalidOperand = 0;

                    } else if (invalidOperand == 1) {

                        printf("Invalid digits in operand\n");
                        invalidOperator = 0, invalidBase = 0, invalidOperand = 0;

                    } else {

                        //functions for calculations go here
                        operandOneBase10 = convertToBase10(operandOne, inputBase);
                        operandTwoBase10 = convertToBase10(operandTwo, inputBase);
                        base10Result = operatorPerform(operandOneBase10, operandTwoBase10, operator);
                        outputBaseResult = outputConvert(base10Result, outputBase);

                        //print output
                        printf("%d %c %d (base %d) = %d %c %d = %d (base %d)\n", operandOne, operator, operandTwo, inputBase, operandOneBase10, operator, operandTwoBase10, outputBaseResult, outputBase);


                    }
                }

            }

        

    return 0;
}

//function definitions

int operatorVerify (char operator) {

     for (int i = 0; i <=3; i++) { //checking operator

            if (operator == '+') {
                return 0;
            } else if (operator == '-') {
                return 0;
            } else if (operator == '*') {
                return 0;
            } else if (operator == '/') {
                return 0;
            } else if (operator == '$') {
                return 0;
            } else {
                return 1;
            }

        }

}

int baseVerify (inputBase) {
    //check that inputBase and outputBase is within 2 and 10 inclusive

    if (inputBase < 2) { //check if smaller than 2

        return 1;
    
    } else if (inputBase > 10) { //check if bigger than 10

        return 1;

    } else { //if 2 < base < 10, returns validBase

        return 0;

    }

}

int operandVerify(operand, base) {

    //cycle through operand digits, verify that each one is <= base

    while (operand > 0) {

        if ((operand%10)>=base) {

            return 1;

        } else {

            operand = operand/10;

        }

    }

}

int convertToBase10(operand, inputBase) { // i think its good

    double operandBase10 = 0;
    int k = 0;

    while (operand > 0) {

        operandBase10 = operandBase10 + ((operand%10)*pow(inputBase, k));
        k = k+1;
        operand = operand/10;

    }

    int returnOperand = operandBase10;
    return returnOperand;

}

int operatorPerform(int num1, int num2, char operator) {

    double outputDouble;

        if (operator == '+') {

            outputDouble = num1+num2;

        } else if (operator == '-') {

            outputDouble = num1-num2;

        } else if (operator == '/') {

            outputDouble = num1/num2;

        } else if (operator == '*') {

            outputDouble = num1*num2;

        }

    int output = outputDouble;
    return output;

}

int outputConvert(operand, outputBase) { // fix this

    int outputDouble = 0; //changed to int here
    int j = 0;

    while (operand > 0) {

        outputDouble += ((operand%outputBase)*pow(10,j));
        j=j+1;
        operand = operand/outputBase;

    }

    return outputDouble;

}
