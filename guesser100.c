#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){

    unsigned int guess = 0;
    unsigned int number = 0;

    srand(time(0));
    number = rand() % 100 + 1;

    printf("\n Will it be bigger, equal or lower than the random machine number ?\n\n Choose a number between 0-100: ");
    scanf("%d", &guess);

    if(guess == number){
        printf("\n\n You've hit it on the nail ! Congratulations ! \n\n");
    }else if(guess > number){
        printf("\n\n Your number is BIGGER\n Computer number: %d \n\n", number);
    }else{
        printf("\n\n Your number is SMALLER\n Computer number: %d \n\n", number);
    }
}
