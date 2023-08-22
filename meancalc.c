#include<stdio.h>
#include<stdlib.h>

int main(){

    int quant;
    printf("Bitte gib an, von wie vielen Zahlen du den Mittelwert berechnen möchtest: ");
    scanf("%d", &quant);


    int arr[quant];
    int sum;

    for(int i = 0; i < quant; i++){
        printf("Geben sie die %i. Zahl ein: ", i+1);
        scanf("%d", &arr[i]);
        printf("Du hast die Zahl %d eingegeben\n\n", arr[i]);
        sum = sum + arr[i];
    }

    int mean = sum / quant;

    printf("Summe = %d\n", sum);
    printf("Mittelwert = %d\n", mean);

}
