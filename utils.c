#include <stdio.h>
#include <sys/stat.h>

void search_file() {
    char filename[100];
    printf("Enter file name to search: ");
    scanf("%s", filename);

    struct stat buffer;
    if (stat(filename, &buffer) == 0) {
        printf("File found: %s\n", filename);
    } else {
        printf("File not found.\n");
    }
}
