#include <stdio.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    float marks;
};

void addStudent(struct Student *s) {
    printf("Enter Roll Number: ");
    scanf("%d", &s->roll_no);
    printf("Enter Name: ");
    getchar();
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = 0;
    printf("Enter Marks: ");
    scanf("%f", &s->marks);
}

void displayStudent(struct Student s) {
    printf("Roll Number: %d\n", s.roll_no);
    printf("Name: %s\n", s.name);
    printf("Marks: %.2f\n", s.marks);
}

int main() {
    struct Student students[10];
    int choice, count = 0;

    while(1) {
        printf("1. Add Student\n");
        printf("2. Display Student\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count < 10) {
                addStudent(&students[count]);
                count++;
            } else {
                printf("Student list is full.\n");
            }
        } else if (choice == 2) {
            if (count > 0) {
                for (int i = 0; i < count; i++) {
                    displayStudent(students[i]);
                    printf("\n");
                }
            } else {
                printf("No students to display.\n");
            }
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
