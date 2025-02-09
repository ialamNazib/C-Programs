#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int bookID;
    char title[50];
    char author[50];
    int available;
};

struct Book books[100];
int bookCount = 0;

void addBook() {
    struct Book newBook;
    printf("Enter Book ID: ");
    scanf("%d", &newBook.bookID);
    printf("Enter Book Title: ");
    getchar();
    fgets(newBook.title, 50, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;
    printf("Enter Book Author: ");
    fgets(newBook.author, 50, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;
    newBook.available = 1;
    books[bookCount] = newBook;
    bookCount++;
    printf("Book added successfully.\n");
}

void displayBooks() {
    printf("BookID\tTitle\t\tAuthor\t\tAvailable\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d\t%s\t\t%s\t\t%s\n", books[i].bookID, books[i].title, books[i].author, books[i].available ? "Yes" : "No");
    }
}

void issueBook() {
    int bookID;
    printf("Enter Book ID to issue: ");
    scanf("%d", &bookID);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].bookID == bookID) {
            if (books[i].available) {
                books[i].available = 0;
                printf("Book issued successfully.\n");
                return;
            } else {
                printf("Book is already issued.\n");
                return;
            }
        }
    }
    printf("Book not found.\n");
}

void returnBook() {
    int bookID;
    printf("Enter Book ID to return: ");
    scanf("%d", &bookID);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].bookID == bookID) {
            if (!books[i].available) {
                books[i].available = 1;
                printf("Book returned successfully.\n");
                return;
            } else {
                printf("This book was not issued.\n");
                return;
            }
        }
    }
    printf("Book not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                issueBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
