#ifndef ALX_SE_PROGRAM_H
#define ALX_SE_PROGRAM_H

#include <stdio.h>

/**
 * struct Student - Represents a student in the ALX SE program
 * @name: The name of the student
 * @age: The age of the student
 * @cohort: The cohort of the student
 */
typedef struct Student
{
	char *name;
	int age;
	int cohort;
} Student;

/**
 * print_student_info - Prints information about a student
 * @student: Pointer to the student whose information is to be printed
 */
void print_student_info(Student *student);

#endif /* ALX_SE_PROGRAM_H */

