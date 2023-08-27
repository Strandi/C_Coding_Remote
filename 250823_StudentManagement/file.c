#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "headerfile.h"






void loadStudentData(student *header){
    FILE *studentfile;
    studentfile = fopen("students.txt", "r");
    if(studentfile == NULL){
        printf("\nDie eingetragenen Studenten konnten nicht abgerufen werden!\n\n");
        return;
    }


    char first_name[256];
    char last_name[256];
    int matr_numb = 0;
    int age = 0;
    char program[256];
    while(fscanf(studentfile, "%[^;];%[^;];%d;%d;%s%*c",
                                                    first_name,
                                                    last_name,
                                                    &matr_numb,
                                                    &age,
                                                    program
                                                    ) != EOF){
        student *student_to_add = (student *)malloc(sizeof(student));
        addStudentsFromFile(header, student_to_add);
        strcpy(student_to_add->first_name, first_name);
        strcpy(student_to_add->last_name, last_name);
        student_to_add->mat_numb = matr_numb;
        student_to_add->age = age;
        strcpy(student_to_add->program, program);
        
    }


    fclose(studentfile);
}



void loadCourseData(program *pheader){
    FILE *coursefile;
    coursefile = fopen("courses.txt", "r");

    if(coursefile == NULL){
        printf("\nDie eingetragenen Studienrichtungen konnten nicht abgerufen werden!\n\n");
        return;
    }


    char program_name[256];
    int number_of_students = 0;

    while(fscanf(coursefile, "%[^;];%d%*c",
                                                    program_name,
                                                    &number_of_students
                                                    ) != EOF){
        program *program_to_add = (program *)malloc(sizeof(program));
        addCoursesFromFile(pheader, program_to_add);
        strcpy(program_to_add->name, program_name);
        program_to_add->number_of_students = number_of_students;
        
    }


    fclose(coursefile);
}








// UPDATE STUDENTS FILE -----------------
//
//
void updateStudentFile(student *header){
    FILE *studentfile;
    studentfile = fopen("students.txt", "w");
    if (studentfile == NULL) {
        perror("Fehler beim Öffnen der Datei 'students.txt'\n");
        return;
    }


    student *counter = header ->next_student;

    while(counter != NULL){
        fprintf(studentfile, "%s;", counter->first_name);
        fprintf(studentfile, "%s;", counter->last_name);
        fprintf(studentfile, "%d;", counter->mat_numb);
        fprintf(studentfile, "%d;", counter->age);
        fprintf(studentfile, "%s\n", counter->program);
        fflush(studentfile);


        counter = counter->next_student;
        
    }
}



// UPDATE PROGRAMS FILE -----------------
//
//
void updateProgramFile(program *header){




}