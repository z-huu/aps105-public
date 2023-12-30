/* to comment in C, we precede comments and end them
with the appropriate starts and ends --> */

/* lab 0 wants us to print "Hello World!" */

/* to do this, we can use the command 'printf();' */

#include "stdio.h" /* standard io.h ; necessary library to include in order
to use the printf(); command*/

int main() {
int var = 5;
var+=1;
printf("Hello World!");
for (int i = 0; i < 5; i++) {
    printf("%d", i);
}
return 0;

}