/* Part 4 - Debugging Assignment */

// the following code is not working as intended

#include <stdio.h>

int main(void) {
				
				//constants are all good
				const double CmPerInch = 2.54;
				const double CmPerMetre = 100.00;
				const int InchesPerFoot = 12;
				const int InchesPerYard = 36;
	
				//user input is fine
				double distance; //distance should not be an integer
				printf("Please provide a distance in metres: ");
				scanf("%lf", &distance); //change data type from %d to %lf to account for double
	
				//metre to inches conversion is good
				double distanceInInches = distance * CmPerMetre / CmPerInch;
	
	// truncate fractional part to get # of inches
	int inches = distanceInInches;
	distanceInInches = distanceInInches - inches;
	
	int yards = inches / InchesPerYard;
	
	// how many inches are left after extracting yards
	inches = inches % InchesPerYard;
	
	int feet = inches / InchesPerFoot;
	
	// how many inches are left after extracting feet
	inches = inches % InchesPerFoot;
	
	printf("%d yards, %d feet, %d inches, %.2f inches remainder\n", yards, feet, inches, distanceInInches);
	
	return 0;
}