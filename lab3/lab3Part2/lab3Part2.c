/* Part 2 - Printing a Circle

inputs ~~~~~~~~~~~~~~~~~~~
    radius
    
outputs

printed using the character o


psuedo code ~~~~~~~~~~~~~~~~
    ask user for input integer
    scan user input

    for loop (i increasing +1 until reaching user input value)
        first row: for loop (k increasing +1 until (2*user input +1)) *k starts at 0
                    x = -user input + k, y = user input + i
                    see if x^2 +y^2 > r^2 ;    
                        if yes, we know it is not within the circle. print .
                        if no, we know it is within the circle. print o
        

*/

#include <stdio.h>
#include <math.h>

int main(void) {

int radius, x, y;

    printf("Enter the radius of the circle: ");
    scanf("%i", &radius);



    for (int i = 0; i<((2*radius)+1); i++) { // counting down the rows in a column

        y = radius-i;
        

        for (int k = 0; k<((2*radius)+1); k++) { //printing row by row

            x = ((-1)*radius)+k;

            if (sqrt((x*x)+(y*y))>radius) { //if x^2 + y^2 > r, it means that coordinate is outside circle

            printf(".");

            } else {

            printf("o");

            }

        }

        printf("\n");

    }

    
}