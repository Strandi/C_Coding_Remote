#include<stdio.h>
#include<string.h>



int checkIfPal(char word[50]);


int main(){
    char word[50];
    printf("Bitte geben Sie ein Wort zur Überprüfung ein: ");
    fgets(word, 50, stdin);

    int palindrom = checkIfPal(word);

    if(palindrom == 1){
        printf("Das eingegebene Wort ist ein Palindrom: %s", word);
    } else {
        printf("Das eingegebene Wort ist kein Palindrom!\n");
    }




}

int checkIfPal(char word[50]){

    int is_palindrom = 1;

    int len;
    len = strlen(word) - 1;
    printf("strlen: %d\n", len);
    printf("strlenhalf: %d\n", len/2);

    int is_odd = len%2;

    char part1[len];
    char part2[len];

    for(int i = 0; i < (len/2); i++){
        part1[i] = word[i];
        part2[i] = word[len - i - 1];
    }

    printf("Wortteil 1: %s\n", part1);
    printf("Wortteil 2: %s\n", part2);

    for(int i = 0; i < (len/2); i++){
        if(part1[i] != part2[i]){
            is_palindrom = 0;
        }
    }


        return is_palindrom;
}
