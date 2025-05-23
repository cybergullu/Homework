#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URUN 100
#define MAX_AD 50

typedef struct {
    int kod;
    char ad[MAX_AD];
    float fiyat;
    int aktif; // 1 = aktif, 0 = silinmiş
} Urun;

Urun urunler[MAX_URUN];
int urun_sayisi = 0;
int urun_kodu_sayaci = 1000;

void urunEkle() {
    if (urun_sayisi >= MAX_URUN) {
        printf("Ürün limiti aşıldı!\n");
        return;
    }

    Urun yeni;
    yeni.kod = urun_kodu_sayaci++;
    printf("Ürün adı: ");
    scanf(" %[^\n]", yeni.ad);
    printf("Fiyatı: ");
    scanf("%f", &yeni.fiyat);
    yeni.aktif = 1;

    urunler[urun_sayisi++] = yeni;
    printf("Ürün eklendi. Kod: %d\n", yeni.kod);
}

void urunleriListele() {
    printf("\n--- Ürün Listesi ---\n");
    for (int i = 0; i < urun_sayisi; i++) {
        if (urunler[i].aktif) {
            printf("Kod: %d | Ad: %s | Fiyat: %.2f\n", urunler[i].kod, urunler[i].ad, urunler[i].fiyat);
        }
    }
}

void urunGuncelle() {
    int kod;
    printf("Güncellenecek ürün kodu: ");
    scanf("%d", &kod);

    for (int i = 0; i < urun_sayisi; i++) {
        if (urunler[i].kod == kod && urunler[i].aktif) {
            printf("Yeni ürün adı: ");
            scanf(" %[^\n]", urunler[i].ad);
            printf("Yeni fiyat: ");
            scanf("%f", &urunler[i].fiyat);
            printf("Ürün güncellendi.\n");
            return;
        }
    }
    printf("Ürün bulunamadı.\n");
}

void urunSil() {
    int kod;
    printf("Silinecek ürün kodu: ");
    scanf("%d", &kod);

    for (int i = 0; i < urun_sayisi; i++) {
        if (urunler[i].kod == kod && urunler[i].aktif) {
            urunler[i].aktif = 0;
            printf("Ürün silindi.\n");
            return;
        }
    }
    printf("Ürün bulunamadı.\n");
}

int main() {
    int secim;

    do {
        printf("\n--- Ürün Yönetimi ---\n");
        printf("1. Ürün Ekle\n");
        printf("2. Ürünleri Listele\n");
        printf("3. Ürün Güncelle\n");
        printf("4. Ürün Sil\n");
        printf("0. Çıkış\n");
        printf("Seçiminiz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1: urunEkle(); break;
            case 2: urunleriListele(); break;
            case 3: urunGuncelle(); break;
            case 4: urunSil(); break;
            case 0: printf("Çıkılıyor...\n"); break;
            default: printf("Geçersiz seçim!\n");
        }
    } while (secim != 0);

    return 0;
}
