#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Define the structure for a book
struct Book {
    char title[100];
    char author[100];
    int ISBN;
    int quantity;
};

// Function prototypes
void addBook(struct Book library[], int *numBooks);
void deleteBook(struct Book library[], int *numBooks);
void searchBook(struct Book library[], int numBooks);
void displayBooks(struct Book library[], int numBooks);

int main() {
    struct Book library[MAX_BOOKS]; // Array to store books
    int numBooks = 0; // Variable to store the number of books in the library
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Search Book\n");
        printf("4. Display All Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &numBooks);
                break;
            case 2:
                deleteBook(library, &numBooks);
                break;
            case 3:
                searchBook(library, numBooks);
                break;
            case 4:
                displayBooks(library, numBooks);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

