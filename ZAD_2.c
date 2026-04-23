#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char ime[100];
    double cena;
    int nomer;
} Produkt;

typedef struct {
    char adres[100];
    int nomerProdukt;
} Poruchka;

int main() {
    Produkt produkti[MAX];
    Poruchka chakastiPoruchki[MAX];

    int broiProdukti = 0;
    int broiPoruchki = 0;

    char komanda[20];

    while (1) {
        scanf("%s", komanda);
        getchar();

        if (strcmp(komanda, "END") == 0) {
            break;
        }

        if (strcmp(komanda, "Product") == 0) {
            Produkt novProdukt;

            fgets(novProdukt.ime, sizeof(novProdukt.ime), stdin);
            novProdukt.ime[strcspn(novProdukt.ime, "\n")] = 0;

            scanf("%lf", &novProdukt.cena);
            scanf("%d", &novProdukt.nomer);
            getchar();

            produkti[broiProdukti] = novProdukt;
            broiProdukti++;

            for (int i = 0; i < broiPoruchki; i++) {
                if (chakastiPoruchki[i].nomerProdukt == novProdukt.nomer) {
                    printf("Client %s ordered %s\n", chakastiPoruchki[i].adres, novProdukt.ime);

                    for (int j = i; j < broiPoruchki - 1; j++) {
                        chakastiPoruchki[j] = chakastiPoruchki[j + 1];
                    }

                    broiPoruchki--;
                    i--;
                }
            }
        } else if (strcmp(komanda, "Order") == 0) {
            Poruchka novaPoruchka;
            int namerenProdukt = -1;

            fgets(novaPoruchka.adres, sizeof(novaPoruchka.adres), stdin);
            novaPoruchka.adres[strcspn(novaPoruchka.adres, "\n")] = 0;

            scanf("%d", &novaPoruchka.nomerProdukt);
            getchar();

            for (int i = 0; i < broiProdukti; i++) {
                if (produkti[i].nomer == novaPoruchka.nomerProdukt) {
                    namerenProdukt = i;
                    break;
                }
            }

            if (namerenProdukt != -1) {
                printf("Client %s ordered %s\n",
                       novaPoruchka.adres,
                       produkti[namerenProdukt].ime);
            } else {
                chakastiPoruchki[broiPoruchki] = novaPoruchka;
                broiPoruchki++;
            }
        }
    }

    return 0;
}
