#include <stdio.h>
#include <string.h>

int anagrama(char niz1[], char niz2[]) {
    int broi1[256] = {0};
    int broi2[256] = {0};

    if (strlen(niz1) != strlen(niz2)) {
        return 0;
    }

    for (int i = 0; niz1[i] != '\0'; i++) {
        broi1[(unsigned char)niz1[i]]++;
        broi2[(unsigned char)niz2[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (broi1[i] != broi2[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char niz1[100];
    char niz2[100];

    printf("Vuvedete purvi niz: ");
    scanf("%s", niz1);

    printf("Vuvedete vtori niz: ");
    scanf("%s", niz2);

    if (anagrama(niz1, niz2)) {
        printf("Nizovete sa anagrama.\n");
    } else {
        printf("Nizovete ne sa anagrama.\n");
    }

    return 0;
}
