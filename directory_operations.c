#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void create_directory() {
    char dirname[100];
    printf("Enter directory name: ");
    scanf("%s", dirname);

    if (mkdir(dirname, 0755) == -1) {
        perror("Error creating directory");
    } else {
        printf("Directory created successfully.\n");
    }
}

void list_directory() {
    char path[100];
    printf("Enter directory path: ");
    scanf("%s", path);

    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    struct dirent *entry;
    printf("Contents of %s:\n", path);
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}
