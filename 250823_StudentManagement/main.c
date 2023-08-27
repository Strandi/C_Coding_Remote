#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "headerfile.h"





int main(){



    

    int number_of_students = 10;
    printf("\n\n\n\n==============================================================================================\n");
    printf("Willkommen im Studentenverwaltungsprogramm!\n");
    printf("Momentan sind %d Studenten an unserer Universität beschäftigt.\n", number_of_students);
    printf("==============================================================================================\n\n\n");


    int option = 0;

    // init student header-------------------------------
    student *header = (student *)malloc(sizeof(student));
    header->previous_student = NULL;
    header->next_student = NULL;
    // --------------------------------------------------

    // init program header-------------------------------
    program *pheader = (program *)malloc(sizeof(program));
    pheader->previous_program = NULL;
    pheader->next_program = NULL;
    // --------------------------------------------------


    // load student data from file ----------------------
    loadStudentData(header);
    //---------------------------------------------------
    
    // load course data from file ----------------------
    loadCourseData(pheader);
    //---------------------------------------------------

    int stop = 0;
    while(stop == 0){


        printf("==========================================================\n");
        printf("Sie haben nun die Möglichkeit aus den untenstehenden Optionen zu wählen\n\n");
        printf("1: Neuen Studenten hinzufügen\n");
        printf("2: Azeigen aller Studenten\n");
        printf("3: Löschen eines Studenten\n");
        printf("4: Studiengangsoptionen\n");
        printf("5: Beenden\n");
        printf("Bitte geben Sie eine Nummer ein: ");
        scanf("%d", &option);
        getchar();
        printf("==========================================================\n\n\n");



        

        switch(option){

            case 1:
                addStudent(header);
                updateStudentFile(header);
            break;


            case 2:
                listStudents(header);
            break;


            case 3:
                removeStudent(header);
                updateStudentFile(header);
            break;


            case 4:
                listProgramOptions(pheader, header);
            break;
            
            
            case 5:
                printf("\nProgramm wird beendet!\n\n");
                stop = 1;
                break;
            break;


            default:
            printf("Heast gib hald amal was ein was a an Sinn ergibt! Wappler!\n\n");


        }
    }
    return 0;
}






// CASE 4 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// 
// 
void listProgramOptions(program *pheader, student *header){

    int stop = 0;
    while(stop == 0){
        int program_option;



        printf("\n\n<<-------- Studiengangsoptionen -------->>\n");
        printf("Was möchten Sie tun?\n");
        printf("1 - Studiengang hinzufügen\n");
        printf("2 - Studiengang löschen\n");
        printf("3 - Alle Studiengänge anzeigen\n");
        printf("4 - Studiengangsoptionen beenden\n");
        printf("Bitte wählen Sie eine Option -> ");
        scanf("%d", &program_option);
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }


        


        switch (program_option)
        {
        case 1:
            addProgram(pheader);
            updateProgramFile(pheader, header);
            break;


        case 2:
            removeProgram(pheader);
            updateProgramFile(pheader, header);

            break;


        case 3: 
            listAllPrograms(pheader);
            break;
        

        case 4: 
            printf("Studienoptionen beenden\n");
            stop = 1;
            break;
        


        default:
            printf("Illegale Option!\n");
            break;
        }
    }
}