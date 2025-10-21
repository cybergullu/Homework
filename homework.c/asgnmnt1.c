//AD:AKİF
//SOYAD:GÜLLÜ
//NUMARA:242503057
//SINIF:2.SINIF
//Öğrenim Türü:ÖRGÜN
#include <stdio.h>
#include <stdlib.h>

#define MAX 50 
#define HEDEF_ISLEM 20 


struct Stack {
    int items[MAX];
    int top;
};


void initStack(struct Stack *s);
int  isFull(struct Stack *s);
int  isEmpty(struct Stack *s);
void push(struct Stack *s, int value);
int  pop(struct Stack *s);
int  peek(struct Stack *s);
void display(struct Stack *s);
int  menu();


void initStack(struct Stack *s) {
    s->top = -1;
}


int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}


int isEmpty(struct Stack *s) {
    return s->top == -1;
}


void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("  Yigin dolu! Push yapilamadi.\n");
        return;
    }
    s->items[++(s->top)] = value;
    printf(" %d yigina eklendi (Push)\n", value);
}


int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("  Yigin bos! Pop yapilamadi.\n");
        return -1;
    }
    int val = s->items[(s->top)--];
    printf(" %d yigindan cikarildi (Pop)\n", val);
    return val;
}


int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("  Yigin bos! Peek yapilamadi.\n");
        return -1;
    }
    printf(" Ustteki eleman (Peek): %d\n", s->items[s->top]);
    return s->items[s->top];
}


void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf(" Yigin bos!\n");
        return;
    }
    printf("\n Yigin durumu (top -> bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n\n");
}


int menu() {
    int secim;
    printf("|~~~~~~~~~~~~|~ YIGIN MENUSU ~|~~~~~~~~~~~~|\n");
    printf("1. Push (Eleman Ekle)\n");
    printf("2. Pop (Eleman Sil)\n");
    printf("3. Peek (Ustteki Elemani Gor)\n");
    printf("4. Yigini Goster\n");
    printf("5. Cikis\n");
    printf("Seciminizi yapin: ");
    scanf("%d", &secim);
    return secim;
}


int main() {
    struct Stack s;
    initStack(&s);

    printf("\n=== YIGIN ISLEMLERI BASLADI ===\n\n");

    int sayac = 0; 

    while (1) {
        int secim = menu();
        int veri;

        switch (secim) {
        case 1:
            printf("Eklenecek sayiyi girin: ");
            scanf("%d", &veri);
            push(&s, veri);
            sayac++;
            break;
        case 2:
            pop(&s);
            sayac++;
            break;
        case 3:
            peek(&s);
            sayac++;
            break;
        case 4:
            display(&s);
            sayac++;
            break;
        case 5:
            printf("\n🔸 Toplam yapilan islem sayisi: %d\n", sayac);
            if (sayac < HEDEF_ISLEM)
                printf(" En az %d islem yapmaniz gerekiyordu!\n", HEDEF_ISLEM);
            else
                printf(" Yeterli sayida islem yapildi. Program sonlandiriliyor...\n");
            printf("Cikis yapildi...\n");
            return 0;
        default:
            printf("  Gecersiz secim! Tekrar deneyin.\n");
        }

        printf("🔹 Simdiye kadar yapilan toplam islem sayisi: %d\n\n", sayac);

        if (sayac >= HEDEF_ISLEM) {
            printf("Tebrikler! %d islem tamamlandi.\n", HEDEF_ISLEM);
        }
    }
}

