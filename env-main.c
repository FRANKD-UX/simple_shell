#include <stdio.h>
#include <stdlib.h>
#include "main.h" /*Make sure to include the header file where necessary*/

/*Function prototypes if needed*/
void some_function(void);

/*Main function*/
int main(void)
{
    /*our implementation here*/
    printf("Hello from main!\n");
    
    /*Call other functions if needed*/
    some_function();
    
    return 0;
}

/*Example additional function*/
void some_function(void)
{
    printf("This is an additional function.\n");
}

