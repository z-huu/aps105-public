/* Part 3 - BMI Classifications

inputs ~~~~~~~~~~~~~~~~~~~~
    a weight immediately followed by a unit; i.e 150lbs or 68kg
        kg or lbs only
    a height immediately followed by a unit; i.e 68.11in or 5.65ft
        metres inches or feet
outputs ~~~~~~~~~~~~~~~~~
    classification of the given height and weight as either:\
        Underweight
        Healthy Weight
        Overweight
        Obesity
    calculated by doing weight(kg) by height (m)

*/

#include <stdio.h>
#include <math.h>
#include <string.h>



int main(void) {

double weightInput, heightInput, weight, height, BMI;
char weightUnitInput[3];
char heightUnitInput[3];
char status[18];
int result, resultInches, resultFeet;

const double lbsToKg = 1/2.205;
const double inchesToM = 1/39.37;
const double feetToM = 1/3.281;

    //gather user inputs
        printf("Enter the body weight: ");
        scanf("%lf %s", &weightInput, &weightUnitInput);

           // printf("%.2f, %s", weightInput, weightUnitInput);

        printf("Enter the height: ");
        scanf("%lf %s", &heightInput, &heightUnitInput);
            
           // printf("%.2f, %s", heightInput, heightUnitInput);
            

    //identify units; convert units if necessary

        //to compare strings, strcmp(str1, str2) = 0 if the strings are equal

        result = strcmp(weightUnitInput, "lb"); //result = 0 if weight is given in pounds

        //converting weight to kg
        if (result == 0) { //if weight given in pounds

            weight = weightInput*lbsToKg;

        } else {

            weight = weightInput;
            
        }

        resultInches = strcmp(heightUnitInput, "in"); //resultInches = 0 if height is given in inches
        resultFeet = strcmp(heightUnitInput, "ft"); //resultFeet = 0 if height is given in feet

        //converting height to m
        if (resultInches == 0) { //if height given in inches
        
            height = heightInput*inchesToM;

        } else if (resultFeet == 0) { //if height given in feet
        
            height = heightInput*feetToM;
        
        } else {
        
            height = heightInput;
        
        }
    
    //calculate BMI

        BMI = weight/pow(height,2);
        BMI = roundf(BMI * 10) / 10;

    //categorize BMI score and output

        if (BMI < 18.5) {

            strcpy(status, "Underweight");

        } else if (BMI >= 18.5 && BMI < 24.9) {

            strcpy(status, "Healthy Weight");

        } else if (BMI >= 24.9 && BMI < 29.9) {

            strcpy(status, "Overweight");

        } else {

            strcpy(status, "Obesity");

        }

        printf("\nThe Body Mass Index (BMI) is: %.1f", BMI);
        printf("\nCategory: %s", status);

    return 0;
}