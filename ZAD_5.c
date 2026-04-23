#include <stdio.h>
#include <string.h>

int main() {
    char duma[100];
    char skritaDuma[100];
    char bukva;
    int duljina;
    int broiOpiti = 0;
    int pozna = 0;

    printf("Vuvedete duma za otgatvane: ");
    scanf("%s", duma);

    duljina = strlen(duma);

    for (int i = 0; i < duljina; i++) {
        skritaDuma[i] = '_';
    }
    skritaDuma[duljina] = '\0';

    while (strcmp(duma, skritaDuma) != 0) {
        printf("\nDuma: %s\n", skritaDuma);
        printf("Vuvedete bukva: ");
        scanf(" %c", &bukva);

        broiOpiti++;

        for (int i = 0; i < duljina; i++) {
            if (duma[i] == bukva) {
                skritaDuma[i] = bukva;
                pozna = 1;
            }
        }

        if (pozna) {
            printf("Ima takava bukva!\n");
        } else {
            printf("Nqma takava bukva!\n");
        }

        pozna = 0;
    }

    printf("\nPoznahte dumata: %s\n", duma);
    printf("Broi vuvedeni bukvi: %d\n", broiOpiti);

    if (broiOpiti <= duljina + 2) {
        printf("Pechelite!\n");
    } else {
        printf("Gubite!\n");
    }

    return 0;
}
