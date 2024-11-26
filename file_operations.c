#include <stdio.h>
#include <stdlib.h>
#include "file_operations.h"

void create_file(const char *path) {
    FILE *file = fopen(path, "w");
    if (file) {
        printf("File created successfully: %s\n", path);
        fclose(file);
    } else {
        perror("Error creating file");
    }
}

void write_to_file(const char *path) {
    FILE *file = fopen(path, "a");
    if (file) {
        printf("Enter text to write to the file: ");
        getchar();  // Consume newline character
        char buffer[256];
        fgets(buffer, sizeof(buffer), stdin);
        fprintf(file, "%s", buffer);
        fclose(file);
        printf("Data written successfully.\n");
    } else {
        perror("Error writing to file");
    }
}

void read_file(const char *path) {
    FILE *file = fopen(path, "r");
    if (file) {
        char buffer[256];
        printf("File contents:\n");
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("%s", buffer);
        }
        fclose(file);
    } else {
        perror("Error reading file");
    }
}

void delete_file(const char *path) {
    if (remove(path) == 0) {
        printf("File deleted successfully: %s\n", path);
    } else {
        perror("Error deleting file");
    }
}
