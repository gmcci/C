#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    unsigned int selection = 0;
    unsigned int choiceUser = 0;
    unsigned int choicePC = 0;

    srand(time(0));

    printf("\n\n-----------------\n");
    printf("    JOKENPO");
    printf("\n-----------------\n\n");

    printf("\n[1] Play the game");
    printf("\n[2] Rules");
    printf("\n[3] Exit\n\n");

    scanf("%d", &selection);

    switch(selection){
    
        case 1:

            printf("\n\n-----------------\n");

            printf("\n[1] - Rock");
            printf("\n[2] - Paper");
            printf("\n[3] - Scissor\n");

            printf("\n-----------------\n\n");

            printf("\nWhat's your choice ? ");
            scanf("%d", &choiceUser);

            choicePC = rand() % 3 + 1;

            printf("\n\n\n-----------------");

            if(choiceUser != 1 && choiceUser != 2 && choiceUser != 3){
                printf("\nUser: Invalid choice.\n");
                printf("\nPC: %d\n", choicePC);

            }else{
                if(choiceUser == 1){
                    printf("\nUser: Rock\n");
                }else if(choiceUser == 2){
                    printf("\nUser: Paper\n");
                }else{
                    printf("\nUser: Scissor\n");
                }

                if(choicePC == 1){
                    printf("\nPC: Rock\n");
                }else if(choicePC == 2){
                    printf("\nPC: Paper\n");
                }else{
                    printf("\nPC: Scissor\n");
                }
            }

            printf("-----------------\n");

            break;

        case 2:

            printf("\n The rules are: \n");
            printf("\n - Paper kills rock");
            printf("\n - Rock kills scissor");
            printf("\n - Scissor kills paper\n\n");
 
            break;

        case 3:

            break;
    }

    switch(choiceUser){

        case 1:

            if(choicePC == 1){
                printf("\n\nResult: Draw\n");
            }else if(choicePC == 2){
                printf("\n\nResult: You lose\n");
            }else{
                printf("\n\nResult: You won\n");
            }

          break; 

        case 2:

            if(choicePC == 2){
                printf("\n\nResult: Draw\n");
            }else if(choicePC == 3){
                printf("\n\nResult: You lose\n");
            }else{
                printf("\n\nResult: You won\n");
            }

          break;

        case 3:

            if(choicePC == 3){
                printf("\n\nResult: Draw\n");
            }else if(choicePC == 1){
                printf("\n\nResult: You lose\n");
            }else{
                printf("\n\nResult: You won\n");
            }

          break;

        default:

            printf("\nResult: You lose\n");
            break;

    }

    printf("\n\n");

    return 0;
}
