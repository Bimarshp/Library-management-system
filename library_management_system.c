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
// Function to add a book to the library
void addBook(struct Book library[], int *numBooks) {
    if (*numBooks == MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    printf("Enter Book Title: ");
    scanf(" %[^\n]", library[*numBooks].title);
    printf("Enter Author Name: ");
    scanf(" %[^\n]", library[*numBooks].author);
    printf("Enter ISBN: ");
    scanf("%d", &library[*numBooks].ISBN);
    printf("Enter Quantity: ");
    scanf("%d", &library[*numBooks].quantity);

    (*numBooks)++;
    printf("Book added successfully.\n");
}

// Function to delete a book from the library
void deleteBook(struct Book library[], int *numBooks) {
    int i, ISBN;
    printf("Enter ISBN of the book to delete: ");
    scanf("%d", &ISBN);

    for (i = 0; i < *numBooks; i++) {
        if (library[i].ISBN == ISBN) {
            // Shift books to fill the gap
            for (int j = i; j < *numBooks - 1; j++) {
                library[j] = library[j + 1];
            }
            (*numBooks)--;
            printf("Book deleted successfully.\n");
            return;
        }
    }
    printf("Book not found.\n");
}
