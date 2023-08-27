#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "headerfile.h"







void chooseProgram(char program[256]){
    strcpy(program, "Informatik");
}


int checkMatrNumb(int mat_numb, student *header){

    student *counter = header;

    if(counter->next_student != NULL){
        counter = counter->next_student;
    }


    while (counter->next_student != NULL){
        if(counter->mat_numb == mat_numb){
            printf("------420-----------\n");
            return 420;
        }
        counter = counter->next_student;
    }


    return 69;
}




// CASE 1 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void addStudent(student *header){


    student *student_to_add = (student *)malloc(sizeof(student));
    student *counter = header;
    
    while (counter->next_student != NULL){
        counter = counter->next_student;
    }
    counter->next_student = student_to_add;
    student_to_add->next_student = NULL;
    student_to_add->previous_student = counter;
    


    int specs_ok = 0;

    while(specs_ok != 1){

        printf("\nHinzufügen eines neuen Studenten\n\n");

        printf("Bitte geben Sie den Vornamen des Studenten ein -> ");
        fgets(student_to_add->first_name, sizeof(student_to_add->first_name), stdin);
        student_to_add->first_name[strcspn(student_to_add->first_name, "\n")] = '\0';
        printf("Bitte geben Sie den Nachnamen des Studenten ein -> ");
        fgets(student_to_add->last_name, sizeof(student_to_add->last_name), stdin);
        student_to_add->last_name[strcspn(student_to_add->last_name, "\n")] = '\0';
        printf("Bitte geben Sie die Matrikelnummer des Studenten ein -> ");
        scanf("%d", &student_to_add->mat_numb);
        printf("Bitte geben Sie das Alter des Studenten ein -> ");
        scanf("%d", &student_to_add->age);
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
        printf("Bitte wählen Sie aus der Liste den gewünschten Studiengang aus\n");
        
        char program[256];
        chooseProgram(program);
        strcpy(student_to_add->program, program);

        printf("%s\n", student_to_add->first_name);
        printf("%s\n", student_to_add->last_name);
        printf("%d\n", student_to_add->mat_numb);
        printf("%d\n", student_to_add->age);
        printf("%s\n", student_to_add->program);

        if(checkMatrNumb(student_to_add->mat_numb, header) == 69){
            specs_ok = 1;
            printf("------inCHECKMATRNUMB--------\n");
        }else{
            printf("Die eingegebene Matrikelnummer existiert bereits!\n");
        }
    }
}


// CASE 2 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void listStudents(student *header){

    student *counter = header->next_student;
    int count = 1;
    
    while(counter->next_student != NULL){
        printf("%d ------------------------------------------\n", count);
        printf("Vorname: %s\n", counter->first_name);
        printf("Nachname: %s\n", counter->last_name);
        printf("Matrikelnummer: %d\n", counter->mat_numb);
        printf("Alter: %d\n", counter->age);
        printf("Studienrichtung: %s\n", counter->program);
        printf("------------------------------------------\n\n\n");

        count++;
        counter = counter->next_student;
    }
    printf("%d ------------------------------------------\n", count);
        printf("Vorname: %s\n", counter->first_name);
        printf("Nachname: %s\n", counter->last_name);
        printf("Matrikelnummer: %d\n", counter->mat_numb);
        printf("Alter: %d\n", counter->age);
        printf("Studienrichtung: %s\n", counter->program);
        printf("------------------------------------------\n\n\n");
}


// CASE 3 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void removeStudent(student *header){
    printf("\n\n$§$§$§$§$§$§$§$§$§$§§$§$§$§$§$§$§$$§$§$§$§$\n");
    printf("Löschen eines Studenten\n");
    printf("Bitte geben Sie die Matrikelnummer des Studenten ein -> ");

    // Scan matr_numb and clear buffer
    int matr_numb = 0;
    scanf("%d", &matr_numb);
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    // -------------------------------

    int mat_numb_found = 0;
    student *counter = header;
    student *student_to_remove;
    student *previous_student;
    student *next_student;

    while (counter != NULL){
        if(counter->mat_numb == matr_numb){
            mat_numb_found = 1;
            if(counter->next_student != NULL){
                student_to_remove = counter;
                previous_student = counter->previous_student;
                next_student = counter->next_student;
                previous_student->next_student = next_student;
                next_student->previous_student = previous_student;
                free(student_to_remove);
            }
            if (counter->next_student == NULL){
                student_to_remove = counter;
                previous_student = counter->previous_student;
                previous_student->next_student = NULL;
                free(student_to_remove);
            }
            break;
        }
        counter = counter->next_student;
    }
    if(mat_numb_found == 0){
        printf("\nEs existiert kein Student mit dieser Matrikelnummer\n\n");
    }
    
}


void addProgram(program *pheader){

    char program_name[256];
    program *program_to_add = (program *)malloc(sizeof(program));
    program *counter = pheader;


    printf("\n\n--------------------------------------\n");
    printf("+++++Einen Studiengang hinzufügen+++++\n");
    printf("Bitte gib den Namen des neuen Studiengangs ein -> ");
    scanf("%[^\n]", program_name);
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    strcpy(program_to_add->name, program_name);

    while (counter->next_program != NULL){
        counter = counter->next_program;
    }
    counter->next_program = program_to_add;
    program_to_add->previous_program = counter;
    program_to_add->next_program = NULL;
}


void listAllPrograms(program *pheader){
    program *counter = pheader->next_program;


    printf("\n\n<<<------- Liste aller Studiengänge ------->>>\n");

    int numb_counter = 0;
    while (counter != NULL){
        numb_counter++;
        printf("Nr. %d: %s\n", numb_counter, counter->name);
        counter = counter->next_program;
    }
}





//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void addStudentsFromFile(student *header, student *student_to_add){
    student *counter = header;
    
    while (counter->next_student != NULL){
        counter = counter->next_student;
    }
    counter->next_student = student_to_add;
    student_to_add->next_student = NULL;
    student_to_add->previous_student = counter;
}

void addCoursesFromFile(program *pheader, program *program_to_add){
    program *counter = pheader;
    
    while (counter->next_program != NULL){
        counter = counter->next_program;
    }
    counter->next_program = program_to_add;
    program_to_add->next_program = NULL;
    program_to_add->previous_program = counter;
}

