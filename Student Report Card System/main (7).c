#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define MAX_SUBJECTS 5

typedef struct {
    char name[50];
    int roll;
    float marks[MAX_SUBJECTS];
    float total;
    float percentage;
    char grade;
} Student;

Student students[MAX_STUDENTS];
int numStudents = 0;

void addStudent() {
    if (numStudents < MAX_STUDENTS) {
        printf("Enter student name: ");
        scanf("%s", students[numStudents].name);
        printf("Enter student roll number: ");
        scanf("%d", &students[numStudents].roll);
        printf("Enter marks in %d subjects: ", MAX_SUBJECTS);
        for (int i = 0; i < MAX_SUBJECTS; i++) {
            scanf("%f", &students[numStudents].marks[i]);
        }
        students[numStudents].total = 0;
        for (int i = 0; i < MAX_SUBJECTS; i++) {
            students[numStudents].total += students[numStudents].marks[i];
        }
        students[numStudents].percentage = (students[numStudents].total / MAX_SUBJECTS) * 100;
        if (students[numStudents].percentage >= 90) {
            students[numStudents].grade = 'A';
        } else if (students[numStudents].percentage >= 80) {
            students[numStudents].grade = 'B';
        } else if (students[numStudents].percentage >= 70) {
            students[numStudents].grade = 'C';
        } else if (students[numStudents].percentage >= 60) {
            students[numStudents].grade = 'D';
        } else {
            students[numStudents].grade = 'F';
        }
        numStudents++;
        printf("Student added successfully!\n");
    } else {
        printf("No more students can be added.\n");
    }
}

void displayReportCard() {
    int roll;
    printf("Enter student roll number: ");
    scanf("%d", &roll);
    for (int i = 0; i < numStudents; i++) {
        if (students[i].roll == roll) {
            printf("Student Name: %s\n", students[i].name);
            printf("Roll Number: %d\n", students[i].roll);
            printf("Marks:\n");
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                printf("Subject %d: %.2f\n", j + 1, students[i].marks[j]);
            }
            printf("Total: %.2f\n", students[i].total);
            printf("Percentage: %.2f%%\n", students[i].percentage);
            printf("Grade: %c\n", students[i].grade);
            return;
        }
    }
    printf("Student not found!\n");
}

void displayAllReportCards() {
    for (int i = 0; i < numStudents; i++) {
        printf("Student Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].roll);
        printf("Marks:\n");
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("Subject %d: %.2f\n", j + 1, students[i].marks[j]);
        }
        printf("Total: %.2f\n", students[i].total);
        printf("Percentage: %.2f%%\n", students[i].percentage);
        printf("Grade: %c\n", students[i].grade);
        printf("\n");
    }
}

int main() {
    while (1) {
        printf("1. Add student\n");
        printf("2. Display report card\n");
        printf("3. Display all report cards\n");
        printf("4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayReportCard();
                break;
            case 3:
                displayAllReportCards();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}