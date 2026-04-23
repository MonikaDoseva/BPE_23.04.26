#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DUMA 51

void zapishiVBinarienFail(char **duumi, int broiDuumi) {
    FILE *fail = fopen("output.bin", "wb");

    if (fail == NULL) {
        printf("Greshka pri otvarqne na binarniq fail!\n");
        return;
    }

    for (int i = 0; i < broiDuumi; i++) {
        fwrite(duumi[i], sizeof(char), strlen(duumi[i]), fail);

        if (i < broiDuumi - 1) {
            fwrite(" ", sizeof(char), 1, fail);
        }
    }

    fclose(fail);
}

void pokazhiBinarienFail() {
    FILE *fail = fopen("output.bin", "rb");
    char simvol;

    if (fail == NULL) {
        printf("Greshka pri otvarqne na binarniq fail!\n");
        return;
    }

    while (fread(&simvol, sizeof(char), 1, fail) == 1) {
        printf("%c", simvol);
    }

    printf("\n");
    fclose(fail);
}

int main() {
    FILE *vhod = fopen("input.txt", "r");

    if (vhod == NULL) {
        printf("Greshka pri otvarqne na input.txt!\n");
        return 1;
    }

    char **duumi = NULL;
    char predhodnaDuma[MAX_DUMA];
    char tekushtaDuma[MAX_DUMA];

    int broiDuumi = 0;
    int purvaDuma = 1;

    while (fscanf(vhod, "%50s", tekushtaDuma) == 1) {
        if (purvaDuma || tekushtaDuma[0] == predhodnaDuma[strlen(predhodnaDuma) - 1]) {
            char **novMasiv = realloc(duumi, (broiDuumi + 1) * sizeof(char *));

            if (novMasiv == NULL) {
                printf("Greshka pri zadelqne na pamet!\n");
                fclose(vhod);
                return 1;
            }

            duumi = novMasiv;

            duumi[broiDuumi] = malloc((strlen(tekushtaDuma) + 1) * sizeof(char));

            if (duumi[broiDuumi] == NULL) {
                printf("Greshka pri zadelqne na pamet!\n");
                fclose(vhod);
                return 1;
            }

            strcpy(duumi[broiDuumi], tekushtaDuma);
            strcpy(predhodnaDuma, tekushtaDuma);

            broiDuumi++;
            purvaDuma = 0;
        }
    }

    fclose(vhod);

    zapishiVBinarienFail(duumi, broiDuumi);

    printf("Sudurjanie na binarniq fail:\n");
    pokazhiBinarienFail();

    for (int i = 0; i < broiDuumi; i++) {
        free(duumi[i]);
    }

    free(duumi);

    return 0;
}
