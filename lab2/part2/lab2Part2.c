/* Part 2 - Cartesian Coordinates 

inputs ~~~~~~~~~~~~~~~~~~`
    x and y coordinates of a point
        negative & positive inputs

outputs ~~~~~~~~~~~~~~~~~~~~~``
    quadrant that point lies in OR
    axis that point lies on

        when determining quadrant, round x and y inputs to the nearest 100th (two dec points)
        THEN determine location


*/

#include <stdio.h>
#include <math.h>

double xInput = 0;
double yInput = 0;
double x = 0;
double y = 0;

int main(void) {

    printf("Enter the x-coordinate in floating point: ");
    scanf("%lf", &xInput);
    printf("Enter the y-coordinate in floating point: ");
    scanf("%lf", &yInput);

    //round x and y inputs ; assign to x and y variables

    x = roundf(xInput * 100) / 100;
    y = roundf(yInput * 100) / 100;
  
    //axis and origin cases
        if (x == 0) { //if point is on the x axis
            if ( y == 0) { //origin case
                printf("\n(%.2f, %.2f) is at the origin.", x, y);
            } else { //on the y axis case
                printf("\n(%.2f, %.2f) is on the y axis.",x,y);
            }

        }

        if (y == 0) { // if point is on the y axis
            if (x == 0) { //origin case
                printf("\n(%.2f, %.2f) is at the origin.", x, y);

            } else { // on the x axis case
                printf("\n(%.2f, %.2f) is on the x axis.",x,y);
            }

        }

    //quadrant 1 and 4 cases
        if (x > 0) { //if point is in either q1 or q4
            if (y > 0) { //if point is in q1
                printf("\n(%.2f, %.2f) is in quadrant I.", x, y);
            } else { //if point is in q4
                printf("\n(%.2f, %.2f) is in quadrant IV.", x, y);
            }
        }

    //quadrant 2 and 3 cases
        if (x < 0) { //if point is in either q2 or q3
            if (y > 0) { //if point is in q2
                printf("\n(%.2f, %.2f) is in quadrant II.", x, y);
            } else {
                printf("\n(%.2f, %.2f) is in quadrant III.", x, y);
            }
        }

    return 0;
}
