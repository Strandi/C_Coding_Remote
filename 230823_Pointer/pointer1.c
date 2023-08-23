#include<stdio.h>




void swap(int *num1, int *num2){
    int joker;
    joker = *num1;
    *num1 = *num2;
    *num2 = joker;

}


int main(){

    int number1;
    int number2;
    int *ptr1 = &number1;
    int *ptr2= &number2;


    printf("Bitte geben Sie die erste Zahl ein: ");
    scanf("%d", &number1);
    printf("\nBitte geben Sie die zweite Zahl ein: ");
    scanf("%d", &number2);

    printf("\nErste Zahl: %d \nZweite Zahl: %d \n\n\n", number1, number2);

    printf("-$-$-$-  SWAPIT  -$-$-$-\n\n\n");
    swap(ptr1, ptr2);

    printf("Erste Zahl: %d \nZweite Zahl: %d\n", number1, number2);


    return 0;
}
