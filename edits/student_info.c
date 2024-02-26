#include "alx_se_program.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    Student student1;

    student1.name = "John";
    student1.age = 25;
    student1.cohort = 12;

    print_student_info(&student1);

    return (0);
}

/**
 * print_student_info - Prints information about a student
 * @student: Pointer to the student whose information is to be printed
 *
 * Description: This function prints the name, age, and cohort of a student.
 */
void print_student_info(Student *student)
{
    if (student != NULL)
    {
        printf("Name: %s\n", student->name);
        printf("Age: %d\n", student->age);
        printf("Cohort: %d\n", student->cohort);
    }
}

