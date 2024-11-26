#include <stdio.h>
#include <stdlib.h>
#include "file_operations.h"
#include "directory_operations.h"

void print_menu() {
    printf("\nFile System Manager\n");
    printf("1. Create File\n");
    printf("2. Write to File\n");
    printf("3. Read File\n");
    printf("4. Delete File\n");
    printf("5. Create Directory\n");
    printf("6. List Directory Contents\n");
    printf("7. Delete Directory\n");
    printf("8. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char path[256];

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file path: ");
                scanf("%s", path);
                create_file(path);
                break;
            case 2:
                printf("Enter file path: ");
                scanf("%s", path);
                write_to_file(path);
                break;
            case 3:
                printf("Enter file path: ");
                scanf("%s", path);
                read_file(path);
                break;
            case 4:
                printf("Enter file path: ");
                scanf("%s", path);
                delete_file(path);
                break;
            case 5:
                printf("Enter directory path: ");
                scanf("%s", path);
                create_directory(path);
                break;
            case 6:
                printf("Enter directory path: ");
                scanf("%s", path);
                list_directory(path);
                break;
            case 7:
                printf("Enter directory path: ");
                scanf("%s", path);
                delete_directory(path);
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
