/* Part 2 - Function Printing assignment

user inputs order of the function

user is prompted for coefficients up until function order

outpout graph of the function in a cartesian grid ranging from x,y = {-10, 10}

if there is no axis or point on the graph at a location, print three spaces

*/

#include <stdio.h>
#include <math.h>

//function declarations or prototypes
int checkFunctionOrder (int);
void graphFunction (int, int, int, int);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main (void) {   

int functionOrder = 1, xCubed=0, xSquared=0, xOne=0, constant=0, orderStatus = 0;

        while (orderStatus != 2) {

            xCubed = 0, xSquared = 0, xOne = 0, constant = 0;

            printf("Enter the order of the function: ");
            scanf("%d", &functionOrder);
            orderStatus = checkFunctionOrder(functionOrder); 

            if (orderStatus == 1) { //too big or too small

                printf("The order must be between [0, 3].\n");

            } else if (orderStatus == 2) { //user wants to stop
            
                return 0;
            
            } else { //input is valid

                //take in user inputs
                for (int i = 0; i <= functionOrder; i++) {

                    if (i == 0) {

                        printf("Enter coefficient of x^0: ");
                        scanf("%d", &constant);

                    } else if (i == 1) {

                        printf("Enter coefficient of x^1: ");
                        scanf("%d", &xOne);

                    } else if (i == 2) {

                        printf("Enter coefficient of x^2: ");
                        scanf("%d", &xSquared);

                    } else if (i == 3) {

                        printf("Enter coefficient of x^3: ");
                        scanf("%d", &xCubed);

                    } else {
                        //****************************
                        printf("why did the for loop run run");
                    }        
                }

                //graph function
                // three spaces for empty, | for y axis, - for x axis, " * " for points on the graph
                graphFunction(xCubed, xSquared, xOne, constant);
                printf("\n");
            }
        
        }

    return 0;
}



int checkFunctionOrder(int functionOrder) { //returns 1 if invalid, 0 if valid, 2 if stop

    if (functionOrder == -1) {

        return 2;

    } else if (functionOrder < 0) {

        return 1;
        
    } else if (functionOrder > 3) {

        return 1;

    } else {

        return 0;

    }

}

void graphFunction (int xCubed, int xSquared, int xOne, int constant) {

int y=10;
int x=-10;

//printing row by row

int yFunction;

    for (y = 10; y >= -10; y--) { //y coordinate up to down

    if (y <= 9) {
    printf("\n");
    }

        for (x = -10; x <= 10; x++) { //x coordinate left to right

            //check if coordinate is empty, axis, or point
            yFunction = ( (xCubed*pow(x,3)) + (xSquared*pow(x,2))  +  (xOne*x) + constant);

            if (y == 0) { //starting at (-10, 0) ** on x axis

                if (x == 0) {

                    if (y != yFunction) {

                        printf(" | ");
                        //at origin, no point

                    } else if (y == yFunction) {
                    
                        printf(" * ");
                        //at origin, yes point

                    }

                } else { //if not at origin

                    if (y != yFunction) {

                        printf(" - ");
                        //not at origin, no point

                    } else if (y == yFunction) {
                    
                        printf(" * ");
                        //not at origin, yes point

                    }

                }

            } else { //not on x axis

                if ((x == 0) && (y != yFunction)) { //if x = 0, no point

                    printf(" | ");

                } else if ( (x == 0) && (y == yFunction) ) { //if x = 0, yes point

                    printf(" * ");

                } else if ( (x != 0) && (y != yFunction) ) { //if x != 0, no point

                    printf("   ");

                } else if ( (x != 0) && (y == yFunction) ) { //if x != 0, yes point

                    printf(" * ");

                }

            }

        }

    }

}
