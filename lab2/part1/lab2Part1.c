/* Part 1 - Trigonometric Calculations

inputs ~~~~~~~~~~~~~~~~``
    side lengths X and Y of a right angled triangle

outputs ~~~~~~~~~~~~~~~~~~~~~~~~`
    length of hypotenuse
    angle measure between hypotenuse and X
*/

#include <stdio.h>
#include <math.h>

double X = 0;
double Y = 0;
double H = 0;
double Tradians = 0;
double T = 0;

int main(void) {

    printf("Enter X: ");
    scanf("%lf", &X);
    printf("Enter Y: ");
    scanf("%lf", &Y);

        H = sqrt((X*X) + (Y*Y));

        Tradians = asin(Y/H); //yields answer in radians
        T = ((180/(M_PI))*Tradians);

        if (T<0) {

            T = T*-1;

        }

    printf("The Hypotenuse Length is: %0.1f", H);
    printf("\nThe Angle Theta is: %0.1f degrees", T);



    return 0;
}