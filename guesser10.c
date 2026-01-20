#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    unsigned int option;
    unsigned int secretNumber;
    unsigned int guess;

    printf("\n\n-----------------------------\n");
    printf("     Simple guess game");
    printf("\n-----------------------------\n\n");

    printf("\n[1] - Start the game.\n");
    printf("[2] - Laws of the game.\n");
    printf("[3] - Exit \n\n");

    scanf("%d", &option);

    switch(option){

        case 1:

            srand(time(0));
            secretNumber = rand() % 20;

            printf("\n- Among 0 and 20, which number am I thinking ? ");
            scanf("%d", &guess);

            if(guess == secretNumber){
                printf("\nYou hit it !\n\n");
            }else{
                printf("\nNo. It was %d\n\n", secretNumber);
            }

            break;

        case 2:

            printf("\n\nThe game is about you guess a number among 0 and 10.\n");
            break;

        case 3:

            break;

        default:

            break;

    }
}
