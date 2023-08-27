#ifndef HEADERFILE_H
#define HEADERFILE_H

typedef struct student_struct{
    struct student_struct *previous_student;
    struct student_struct *next_student;
    char first_name[256];
    char last_name[256];
    int mat_numb;
    int age;
    char program[256];
}student;


typedef struct program_struct{
    struct program_struct *previous_program;
    struct program_struct *next_program;
    char name[256];
    int number_of_students;
}program;



void loadStudentData(student *header);
void loadCourseData(program *pheader);
void addStudentsFromFile(student *header, student *student_to_add);
void addCoursesFromFile(program *pheader, program *program_to_add);

void addStudent(student *header);
void listStudents(student *header);
void removeStudent(student *header);

void listProgramOptions(program *pheader, student *header);
void addProgram(program *pheader);
void removeProgram(program *pheader);
void listAllPrograms(program *pheader);

void updateStudentFile(student *header);
void updateProgramFile(program *pheader, student *header);
void countStudentsOfProgram(int *number, char program[256], student *header);

#endif