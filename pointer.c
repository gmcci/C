#include <stdio.h>

int main(){
    int travel = 10;
    int *place = &travel;

    printf("\nAssociation: \n\n");

    printf("int travel = 10; \n");
    printf("int *place = &travel; \n\n");

    printf("travel gets: %d \n", travel);
    printf("*place gets: %p \n\n", *place);

    printf("Travel gets the number, *place the exact place in memory. \n");
}
