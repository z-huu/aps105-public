/* Part 2 - Currency Conversion Assignment*/
/* 
inputs; ~~~~~~~~~~~~~~~~~~~~~~
    conversion rate from some currency to CAD 
        assume conversion rate is above 0
    amount in some currency
        assume amount of some currency is 0 or above
            account for input of 0

outputs; ~~~~~~~~~~~~~~~~~~~~
    amount of some currency converted to CAD
        rounded to two decimal places

conditions; ~~~~~~~~~~~~~~~~~~~~~~
    assume user enters valid numbers; no need for type checking
    output dollar should be rounded to two decimal places

*/

#include <stdio.h>

float originalCurrency; // stores amount in original currency
float conversionRate; // multiply with originalCurrency to get amountCad
float amountCad; // stores amount in Canadian dollars

int main() {

        //take in user inputs
        printf("Enter the conversion rate:");
        scanf("%f", &conversionRate);
        printf("\nEnter the amount to be converted (in foreign currency):");
        scanf("%f", &originalCurrency);

        //account for inputs of 0, 
            
            if (originalCurrency==0) { // if amount of original currency is 0, amount in Canadian is 0
                
                amountCad = 0;
    
            } else { // otherwise, amount in Canadian is original currency * conversion rate

                amountCad = conversionRate*originalCurrency;

            }

        //displaying output value
        printf("\nThe amount in Canadian dollars is: $");
        printf("%0.2f", amountCad);

        //debugging outputs
        printf("\nConversion rate: ");
        printf("%f", conversionRate);
        printf("\nOriginal currency: ");
        printf("%f", originalCurrency);

    return 0;

}