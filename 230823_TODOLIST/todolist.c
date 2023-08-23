#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Task {
    char title[100];
    char description[100];
    int id;
};




int main(){

    printf("Willkommen zur TO-DO-LISTE\n");

    int option;
    int *ptr_opt = &option;
    int number_of_tasks = 0;
    struct Task *tasks = NULL;

    while(1){
        printf("1. Aufgabe hinzfügen\n");
        printf("2. Aufgabe anzeigen\n");
        printf("3. Beenden\n");


        printf("Bitte wähle eine Option: ");
        scanf("%d", &option);
        getchar();

        switch (option){
            case 1:
                number_of_tasks++;
                tasks = (struct Task *)realloc(tasks, number_of_tasks * sizeof(struct Task));
                if(tasks == NULL){
                    return 1;
                }


                printf("\nTitel der Aufgabe: ");
                fgets(tasks[number_of_tasks - 1].title , 100, stdin);

                printf("Beschreibung der Aufgabe: ");
                fgets(tasks[number_of_tasks - 1].description , 100, stdin);

                printf("\nAufgabe erfolgreich hinzugefügt!\n\n\n");
                break;



            case 2:
                printf("\nHIER DEINE AUFGABEN:\n");
                for(int i = 0; i < number_of_tasks; i++){


                    printf("--------------------------------------\n");
                    printf("Aufgabe: %d\n", i+1);
                    printf("Titel: %s\n", tasks[i].title);
                    printf("Beschreibung: %s\n", tasks[i].description);
                    printf("--------------------------------------\n\n\n");
                }
                break;

            case 3:
                printf("Liste wird gelöscht!\n\n\n");
                free(tasks);
                return 0;


            default:
                printf("Ungültige Eingabe!\n\n\n");

        }


    }










    return 0;
}


