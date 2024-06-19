#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char data[100];

    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("Enter data to write to the file (max 100 characters):\n");
    fgets(data, sizeof(data), stdin); 
    fputs(data, fp);

    fclose(fp);

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("\nContents of data.txt:\n");
    while (fgets(data, sizeof(data), fp) != NULL) {
        printf("%s", data);
    }

    fclose(fp);

    return 0;
}
