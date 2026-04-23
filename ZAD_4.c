#include <stdio.h>

int main() {
    FILE *vhod, *izhod;
    char imeNaFail[100];
    int kluch;
    char simvol;

    printf("Vuvedete ime na fail za kodirane: ");
    scanf("%s", imeNaFail);

    printf("Vuvedete kluch ot 2 do 10: ");
    scanf("%d", &kluch);

    if (kluch < 2 || kluch > 10) {
        printf("Nevaliden kluch!\n");
        return 1;
    }

    vhod = fopen(imeNaFail, "r");

    if (vhod == NULL) {
        printf("Failut ne moje da bude otvoren!\n");
        return 1;
    }

    izhod = fopen("encoded.txt", "w");

    if (izhod == NULL) {
        printf("Izhodniqt fail ne moje da bude otvoren!\n");
        fclose(vhod);
        return 1;
    }

    while ((simvol = fgetc(vhod)) != EOF) {
        fputc(simvol + kluch, izhod);
    }

    fclose(vhod);
    fclose(izhod);

    printf("Failut e kodiran uspeshno v encoded.txt\n");

    return 0;
}
