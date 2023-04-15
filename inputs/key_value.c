#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];  // buffer to hold user input
    char *token;       // pointer to individual tokens in input
    char *name;        // pointer to student name
    char *grade_str;   // pointer to grade as string
    int total = 0;     // total of all grades
    int count = 0;     // count of all grades

    printf("Enter a string of comma-separated values representing student grades: ");
    fgets(input, 1000, stdin);

    // Parse the input string
    token = strtok(input, ",");
    while (token != NULL) {
        name = token;
        grade_str = strtok(NULL, ",");
        if (grade_str != NULL) {
            total += atoi(grade_str);
            count++;
        }
        token = strtok(NULL, ",");
    }

    // Calculate the average grade
    double average = (double) total / count;

    // Print the average grade
    printf("The average grade is %.2f\n", average);

    return 0;
}
