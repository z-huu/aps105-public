/* Part 1 - Printing Assignment*/
/* To print messages, use the command printf(); */

#include <stdio.h>

int main() {

        printf("C uses escape sequences for a variety of purposes.\n");
        printf("Some common ones are:\n");
        char output1 [128] = "     to print \", use \\\"\n";
        printf(output1);
        char output2 [128] = "     to print \\, use \\\\\n";
        printf(output2);
        char output3 [128] = "     to jump to a new line, use \\";
        printf(output3);
        printf("n");
        /* output 1,  are indented. use \t */
    return 0;

}
