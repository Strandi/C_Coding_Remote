#include<stdio.h>
#include "operations.h"


int main(){

    int calculation = 0;
    int numb1 = 0;
    int numb2 = 0;
    int *ptr1 = &numb1;
    int *ptr2 = &numb2;


    while(1){

        printf("Addition\n");
        printf("Subtraktion\n");
        printf("Multiplikation\n");
        printf("Bitte wählen Sie eine Rechenoperation: ");
        scanf("%d", &calculation);
        printf("Rechenoperation: %d\n", calculation);
        printf("\nBitte geben Sie die erste Zahl ein: ");
        scanf("%d", ptr1);
        printf("Zahl 1: %d\n", numb1);
        printf("\nBitte geben Sie die zweite Zahl ein: ");
        scanf("%d", ptr2);
        printf("Zahl 2: %d\n", numb2);


        switch(calculation){
            case 1:
                int result1 = add(ptr1, ptr2);
                printf("\nDas Ergebnis der Addition lautet %d\n\n\n", result1);
                break;

            case 2:
                int result2 = sub(ptr1, ptr2);
                printf("\nDas Ergebnis der Subtraktion lautet %d\n\n\n", result2);
                break;

            case 3:
                int result3 = mult(ptr1, ptr2);
                printf("\nDas Ergebnis der Multiplikation lautet %d\n\n\n", result3);
                break;

            default:
                printf("No valid operation!\n");
        }




    }







    return 0;
}
