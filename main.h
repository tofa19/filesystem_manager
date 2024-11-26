#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "commands.h"

void process_command(char *command) {
    char action[50], arg1[100], arg2[100];

    int args = sscanf(command, "%s %s %[^\n]", action, arg1, arg2);

    if (strcmp(action, "create") == 0 && args >= 2) {
        FILE *file = fopen(arg1, "w");
        if (file) {
            fclose(file);
            printf("File '%s' created successfully.\n", arg1);
        } else {
            perror("Error creating file");
        }
    } else if (strcmp(action, "delete") == 0 && args >= 2) {
        if (remove(arg1) == 0) {
            printf("File '%s' deleted successfully.\n", arg1);
        } else {
            perror("Error deleting file");
        }
    } else if (strcmp(action, "read") == 0 && args >= 2) {
        FILE *file = fopen(arg1, "r");
        if (file) {
            char buffer[1024];
            while (fgets(buffer, sizeof(buffer), file)) {
                printf("%s", buffer);
            }
            fclose(file);
        } else {
            perror("Error reading file");
        }
    } else if (strcmp(action, "write") == 0 && args >= 3) {
        FILE *file = fopen(arg1, "a");
        if (file) {
            fprintf(file, "%s\n", arg2);
            fclose(file);
            printf("Content written to '%s' successfully.\n", arg1);
        } else {
            perror("Error writing to file");
        }
    } else if (strcmp(action, "mkdir") == 0 && args >= 2) {
        if (mkdir(arg1, 0777) == 0) {
            printf("Directory '%s' created successfully.\n", arg1);
        } else {
            perror("Error creating directory");
        }
    } else if (strcmp(action, "ls") == 0) {
        system("ls -l");
    } else {
        printf("Invalid command or arguments.\n");
    }
}