#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int gosti;
    char predmet[20];

    int stolove = 0;
    int masi = 0;
    int komplektiChashi = 0;
    int komplektiChinii = 0;

    double obshtaSuma = 0;

    scanf("%d", &gosti);

    while (1) {
        scanf("%s", predmet);

        if (strcmp(predmet, "PARTY!") == 0) {
            break;
        }

        if (strcmp(predmet, "Chair") == 0) {
            stolove++;
            obshtaSuma += 13.99;
        } else if (strcmp(predmet, "Table") == 0) {
            masi++;
            obshtaSuma += 42.00;
        } else if (strcmp(predmet, "Cups") == 0) {
            komplektiChashi++;
            obshtaSuma += 5.98;
        } else if (strcmp(predmet, "Dishes") == 0) {
            komplektiChinii++;
            obshtaSuma += 21.02;
        }
    }

    int nujniStolove = gosti;
    int nujniMasi = (int)ceil(gosti / 8.0);
    int nujniKomplektiChashi = (int)ceil(gosti / 6.0);
    int nujniKomplektiChinii = (int)ceil(gosti / 6.0);

    int oshteStolove = nujniStolove - stolove;
    int oshteMasi = nujniMasi - masi;
    int oshteChashi = nujniKomplektiChashi - komplektiChashi;
    int oshteChinii = nujniKomplektiChinii - komplektiChinii;

    if (oshteStolove < 0) oshteStolove = 0;
    if (oshteMasi < 0) oshteMasi = 0;
    if (oshteChashi < 0) oshteChashi = 0;
    if (oshteChinii < 0) oshteChinii = 0;

    printf("%.2f\n", obshtaSuma);

    if (oshteMasi > 0) {
        printf("%d Table\n", oshteMasi);
    }

    if (oshteStolove > 0) {
        printf("%d Chairs\n", oshteStolove);
    }

    if (oshteChashi > 0) {
        printf("%d Cups\n", oshteChashi);
    }

    if (oshteChinii > 0) {
        printf("%d Dishes\n", oshteChinii);
    }

    return 0;
}
