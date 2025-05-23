#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;              
    struct Node* next;      
} Node;


Node* head = NULL;


Node* dugumOlustur(int veri);
void ekleBasa(int veri);
void arayaEkle(int veri, int pozisyon);
void ekleSona(int veri);
void yazdir();
void listeyiTemizle();

int main() {
    int secim, veri, poz;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Başa Düğüm Ekle\n");
        printf("2. Araya Düğüm Ekle\n");
        printf("3. Sona Düğüm Ekle\n");
        printf("4. Listeyi Yazdır\n");
        printf("5. Çıkış\n");
        printf("Seçiminizi yapın: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Eklenecek veri: ");
                scanf("%d", &veri);
                ekleBasa(veri);
                break;
            case 2:
                printf("Eklenecek veri: ");
                scanf("%d", &veri);
                printf("Pozisyon (0'dan başlar): ");
                scanf("%d", &poz);
                arayaEkle(veri, poz);
                break;
            case 3:
                printf("Eklenecek veri: ");
                scanf("%d", &veri);
                ekleSona(veri);
                break;
            case 4:
                yazdir();
                break;
            case 5:
                printf("Programdan çıkılıyor...\n");
                listeyiTemizle();
                exit(0);
            default:
                printf("Geçersiz seçim!\n");
        }
    }

    return 0;
}

Node* dugumOlustur(int veri) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    if (yeni == NULL) {
        printf("Bellek tahsisi başarısız!\n");
        exit(1);
    }
    yeni->data = veri;
    yeni->next = NULL;
    return yeni;
}

void ekleBasa(int veri) {
    Node* yeni = dugumOlustur(veri);
    yeni->next = head;
    head = yeni;
}


void arayaEkle(int veri, int pozisyon) {
    if (pozisyon < 0) {
        printf("Geçersiz pozisyon!\n");
        return;
    }

    if (pozisyon == 0) {
        ekleBasa(veri);
        return;
    }

    Node* yeni = dugumOlustur(veri);
    Node* temp = head;

    for (int i = 0; i < pozisyon - 1; i++) {
        if (temp == NULL) {
            printf("Pozisyon listeden büyük! Ekleme yapılamadı.\n");
            free(yeni);
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Pozisyon listeden büyük! Ekleme yapılamadı.\n");
        free(yeni);
        return;
    }

    yeni->next = temp->next;
    temp->next = yeni;
}
