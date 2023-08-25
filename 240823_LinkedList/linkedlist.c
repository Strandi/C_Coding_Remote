#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Item{
    struct Item *previous_item;
    struct Item *next_item;
    char text[100];
    int id;
};


void addItem(struct Item *header){

    int number_of_items = 0;
    char enter_text[100];

    struct Item *counter_item = header;
    while(counter_item->next_item != NULL){
        counter_item = counter_item->next_item;
        number_of_items++;
    }


    struct Item *new_item = (struct Item *)malloc(sizeof(struct Item));
    new_item->previous_item = counter_item;
    new_item->next_item = NULL;
    new_item->id = number_of_items;
    counter_item->next_item = new_item;

    printf("Bitte geben Sie hier einen Text ein!: ");
    scanf("%[^\n]", &enter_text);
    getchar();
    printf("\n");

    strcpy(new_item->text, enter_text);

}


void removeItem(int to_remove, struct Item *header){

    struct Item *counter_item = header;
    struct Item *jiggle_item = NULL;
    struct Item *item_to_free = NULL;

    for(int i = 0; i < to_remove; i++){

        if(counter_item->next_item == NULL && (i+1) < to_remove)
            printf("Dieses Element existiert nicht!\n");
        }

        if(counter_item->next_item != NULL){
            counter_item = counter_item->next_item;
        }


    item_to_free = counter_item;
    jiggle_item = item_to_free->previous_item;
    jiggle_item->next_item = item_to_free->next_item;

    if(item_to_free->next_item != NULL){
        counter_item = item_to_free->next_item;
        counter_item->previous_item = jiggle_item;
    }

    free(item_to_free);
}






void printItems(struct Item *header){

    int number_of_items = 0;
    struct Item *counter_item = header->next_item;

    while(counter_item->next_item != NULL){
        number_of_items++;
        printf("\n\n//////////////////////////////////\n");
        printf("Itemnummer: %d\n", number_of_items);
        printf("Text: %s\n", counter_item->text);
        printf("//////////////////////////////////\n\n");
        counter_item = counter_item->next_item;
    }
    number_of_items++;
    printf("\n\n//////////////////////////////////\n");
    printf("Itemnummer: %d\n", number_of_items);
    printf("Text: %s\n", counter_item->text);
    printf("//////////////////////////////////\n\n");


}


void endProgram(struct Item *header){

    struct Item *counter_item = header;
    struct Item *ptr_saver_item;

    while(counter_item->next_item != NULL){
        ptr_saver_item = counter_item->next_item;
        free(counter_item);
        counter_item = ptr_saver_item;
    }
    free(counter_item);

}













int main(){

    int option;
    int *number_of_items;
    number_of_items = 0;


    struct Item *header = (struct Item *)malloc(sizeof(struct Item));
    header->previous_item = NULL;
    header->next_item = NULL;
    strcpy(header->text, "Header");


    while(1){

        printf("==========================\n");
        printf("1: Element hinzufügen\n");
        printf("2: Element löschen\n");
        printf("3: Alle Elemente anzeigen\n");
        printf("4: Beenden\n");
        printf("Bitte wähle eine Option:");
        scanf("%d", &option);
        getchar();
        printf("==========================\n");

        switch(option){
            case 1:
                addItem(header);


                break;


            case 2:
                int to_clear;
                printf("Nummer des zu löschenden Eintrags: ");
                scanf("%d", &to_clear);
                removeItem(to_clear, header);

                break;


            case 3:
                printItems(header);

                break;

            case 4:
                endProgram(header);

                return 0;
        }




    }




}
