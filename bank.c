#include <stdio.h>

int main(){

    unsigned int check;
    float balance = 1000;
    float amount;

    printf("\n\n----------------------------\n");
    printf("        BANK RANDOM");
    printf("\n----------------------------\n");

    printf("\n [1] Check your balance\n");
    printf("\n [2] Take money\n");
    printf("\n [3] Deposit \n");
    printf("\n [4] Exit \n\n");

    printf(" - What do you like to do today ? ");
    scanf("%d", &check);

    switch (check){

        case 1:

            printf("\n\n Your balance: $1000.\n\n");
            break;

        case 2:

            printf("\nHow much would you like to take ? ");
            scanf("%f", &amount);

            if(amount <= balance){
                printf("\nDone ! Please take your money.\n");
                printf("\nNew balance: $ %.2f\n", balance - amount);

            }else{
                printf("\nYou don't have this amount.\n");
            }
            break;

        case 3:

            printf("\nHow much would you like to deposit ? ");
            scanf("%f", &amount);
            printf("\n\n");
            printf("Done !\nNew balance: $ %.2f\n", (balance + amount));
            break;

        case 4:

            break;

        default:

            break;
    }
        return 0;
}
