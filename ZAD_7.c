#include <stdio.h>

#define MAX 30
#define FILE_NAME "sutrudnici.dat"

typedef struct {
    int id;
    double pochasoPlashtane;
    int chasove;
    double sedmichnaZaplata;
} Sutrudnik;

double izchisliZaplata(double pochasoPlashtane, int chasove) {
    double bruto, danuk, neto;

    if (chasove <= 40) {
        bruto = chasove * pochasoPlashtane;
    } else {
        bruto = 40 * pochasoPlashtane;
        bruto += (chasove - 40) * pochasoPlashtane * 1.5;
    }

    danuk = bruto * 0.0365;
    neto = bruto - danuk;

    return neto;
}

int broiZapisi() {
    FILE *fail = fopen(FILE_NAME, "rb");
    Sutrudnik s;
    int broi = 0;

    if (fail == NULL) {
        return 0;
    }

    while (fread(&s, sizeof(Sutrudnik), 1, fail) == 1) {
        broi++;
    }

    fclose(fail);
    return broi;
}

void dobaviSutrudnik() {
    FILE *fail;
    Sutrudnik s;
    int broi = broiZapisi();

    if (broi >= MAX) {
        printf("Ne moje da se dobavqt poveche ot 30 sutrudnici.\n");
        return;
    }

    fail = fopen(FILE_NAME, "ab");

    if (fail == NULL) {
        printf("Greshka pri otvarqne na faila.\n");
        return;
    }

    printf("Vuvedete identifikacionen nomer: ");
    scanf("%d", &s.id);

    printf("Vuvedete pochaso plashtane: ");
    scanf("%lf", &s.pochasoPlashtane);

    printf("Vuvedete broi otraboteni chasove za sedmica: ");
    scanf("%d", &s.chasove);

    s.sedmichnaZaplata = izchisliZaplata(s.pochasoPlashtane, s.chasove);

    fwrite(&s, sizeof(Sutrudnik), 1, fail);

    fclose(fail);

    printf("Sutrudnikut e dobaven uspeshno.\n");
}

void pokazhiZaplati() {
    FILE *fail = fopen(FILE_NAME, "rb");
    Sutrudnik s;

    if (fail == NULL) {
        printf("Nqma suzdaden fail ili nqma zapisi.\n");
        return;
    }

    printf("\nSedmichni zaplati:\n");

    while (fread(&s, sizeof(Sutrudnik), 1, fail) == 1) {
        printf("ID: %d | Sedmichna zaplata: %.2f\n",
               s.id,
               s.sedmichnaZaplata);
    }

    fclose(fail);
}

void pokazhiVsichkiSutrudnici() {
    FILE *fail = fopen(FILE_NAME, "rb");
    Sutrudnik s;

    if (fail == NULL) {
        printf("Nqma suzdaden fail ili nqma zapisi.\n");
        return;
    }

    printf("\nVsichki sutrudnici:\n");

    while (fread(&s, sizeof(Sutrudnik), 1, fail) == 1) {
        printf("ID: %d\n", s.id);
        printf("Pochaso plashtane: %.2f\n", s.pochasoPlashtane);
        printf("Otraboteni chasove: %d\n", s.chasove);
        printf("Sedmichna zaplata: %.2f\n\n", s.sedmichnaZaplata);
    }

    fclose(fail);
}

int main() {
    int izbor;

    do {
        printf("\nMenu:\n");
        printf("1. Dobavqne na nov sutrudnik\n");
        printf("2. Pokazvane na sedmichni zaplati\n");
        printf("3. Pokazvane na vsichki sutrudnici\n");
        printf("0. Izhod\n");
        printf("Izberete opciq: ");
        scanf("%d", &izbor);

        switch (izbor) {
            case 1:
                dobaviSutrudnik();
                break;
            case 2:
                pokazhiZaplati();
                break;
            case 3:
                pokazhiVsichkiSutrudnici();
                break;
            case 0:
                printf("Krai na programata.\n");
                break;
            default:
                printf("Nevaliden izbor.\n");
        }
    } while (izbor != 0);

    return 0;
}
