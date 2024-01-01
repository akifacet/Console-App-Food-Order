#include <stdio.h>

#define MENU_SIZE 10
#define MAX_NAME_LENGTH 50

struct Urun {
    char ad[MAX_NAME_LENGTH];
    double fiyat;
};

struct Urun yemekler[MENU_SIZE] = {
    {"Patlican Musakka", 20.0},
    {"Zeytinyagli Sarma", 15.0},
    {"Hunkar Begendi", 25.0},
    {"Kuzu Tandir", 30.0},
    {"Iskender", 28.0},
    {"Ali Nazik Kebap", 22.0},
    {"Ciger Sis", 18.0},
    {"Beyti Kebap", 26.0},
    {"Kumpir", 12.0},
    {"Kuzu Guvec", 32.0}
};

struct Urun icecekler[MENU_SIZE] = {
    {"Ayran", 3.0},
    {"Kola", 5.0},
    {"Fanta", 5.0},
    {"Turk Kahvesi", 8.0},
    {"Demleme Cay", 4.0},
    {"Meyve Suyu", 6.0},
    {"Limonata", 4.0},
    {"Sahlep", 7.0},
    {"Soguk Su", 1.0},
    {"Soguk Kahve", 10.0}
};

struct Urun tatlilar[MENU_SIZE] = {
    {"Kunefe", 10.0},
    {"Kadayif", 8.0},
    {"Tulumba", 6.0},
    {"Baklava", 12.0},
    {"Revani", 7.0},
    {"Asure", 15.0},
    {"Sutlac", 9.0},
    {"Firin Helva", 10.0},
    {"Keskul", 8.0},
    {"Kazandibi", 11.0}
};

void menuyuYazdir(struct Urun menu[], int menuBoyutu) {
    for (int i = 0; i < menuBoyutu; i++) {
        printf("%d. %s: %.2f TL\n", i + 1, menu[i].ad, menu[i].fiyat);
    }
}

void siparisAl(struct Urun menu[], int menuBoyutu, double* toplamTutar) {
    int secim, adet;

    menuyuYazdir(menu, menuBoyutu);

    printf("Seciminizi yapin (1-%d): ", menuBoyutu);
    scanf_s("%d", &secim);

    if (secim < 1 || secim > menuBoyutu) {
        printf("Geçersiz secim! Lutfen tekrar deneyin.\n");
        return;
    }

    printf("Adet girin: ");
    scanf_s("%d", &adet);

    if (secim == 2 && adet >= 10) {
        *toplamTutar += adet * menu[secim - 1].fiyat * 0.8;
    }
    else if (secim == 1 && adet >= 5) {
        *toplamTutar += adet * menu[secim - 1].fiyat * 0.9;
    }
    else if (secim == 3 && adet >= 3) {
        *toplamTutar += adet * menu[secim - 1].fiyat * 0.95;
    }
    else {
        *toplamTutar += adet * menu[secim - 1].fiyat;
    }

    printf("%d adet %s sepete eklendi. Toplam tutar: %.2f TL\n", adet, menu[secim - 1].ad, *toplamTutar);
}

void odemeYap(double toplamTutar) {
    printf("\nOdeme Yontemini Seciniz:\n");
    printf("1. Kart\n");
    printf("2. Nakit\n");

    int odemeSecim;
    scanf_s("%d", &odemeSecim);

    switch (odemeSecim) {
    case 1:
        printf("Toplam tutar %.2f TL. Kart ile odeme yapiliyor.\n", toplamTutar);
        break;
    case 2:

        toplamTutar *= 0.8;
        printf("Toplam tutar %.2f TL. Nakit ile odeme yaptiginiz icin yuzde yirmi indirim uygulandi. Yeni tutar: %.2f TL\n", toplamTutar / 0.8, toplamTutar);
        break;
    default:
        printf("HATA!\n");
        break;
    }
}

int main() {
    double toplamTutar = 0;

    while (1) {
        printf("\nTURK EV YEMEKLERI MENU\n");
        printf("1. Yemekler\n");
        printf("2. Icecekler\n");
        printf("3. Tatlilar\n");
        printf("4. Siparisi Tamamla\n");
        printf("0. Cikis\n");

        int secim;
        printf("Lutfen secim yapin: ");
        scanf_s("%d", &secim);

        switch (secim) {
        case 1:
            siparisAl(yemekler, MENU_SIZE, &toplamTutar);
            break;
        case 2:
            siparisAl(icecekler, MENU_SIZE, &toplamTutar);
            break;
        case 3:
            siparisAl(tatlilar, MENU_SIZE, &toplamTutar);
            break;
        case 4:
            printf("Siparisiniz tamamlandi. Toplam Tutar: %.2f TL\n", toplamTutar);
            odemeYap(toplamTutar);
            return 0;
        case 0:
            printf("Programdan cikiliyor.\n");
            return 0;
        default:
            printf("HATA!\n");
            break;
        }
    }

    return 0;
}
