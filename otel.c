#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 10

// Müþteri yapýsý
struct Customer {
    char name[50];
    int roomNumber;
};

// Oteli temsil eden yapý
struct Hotel {
    struct Customer reservations[MAX_ROOMS];
};

// Otel fonksiyonlarý
void displayMenu() {
    printf("\n1. Rezervasyon Yap\n");
    printf("2. Rezervasyonlari Goster\n");
    printf("3. Rezervasyon Iptal Et\n");
    printf("4. Cikis\n");
    printf("Seciminizi yapiniz: ");
}

void makeReservation(struct Hotel *hotel, int *numReservations) {
    if (*numReservations < MAX_ROOMS) {
        printf("\nMusteri Adi: ");
        scanf("%s", hotel->reservations[*numReservations].name);

        printf("Oda Numarasi: ");
        scanf("%d", &hotel->reservations[*numReservations].roomNumber);

        (*numReservations)++;
        printf("Rezervasyon yapildi.\n");
    } else {
        printf("Uzgunuz, otel dolu.\n");
    }
}

void displayReservations(struct Hotel hotel, int numReservations) {
	int i;
    printf("\nRezervasyonlar:\n");

    for ( i = 0; i < numReservations; i++) {
        printf("Musteri: %s, Oda No: %d\n", hotel.reservations[i].name, hotel.reservations[i].roomNumber);
    }
}

void cancelReservation(struct Hotel *hotel, int *numReservations) {
	int i,j;
    int roomNumber;
    printf("\nIptal edilecek rezervasyonun oda numarasini girin: ");
    scanf("%d", &roomNumber);

    int found = 0;
    for ( i = 0; i < *numReservations; i++) {
        if (hotel->reservations[i].roomNumber == roomNumber) {
            found = 1;

            // Ýptal edilen rezervasyonu listeden çýkar
            for (j = i; j < *numReservations - 1; j++) {
                hotel->reservations[j] = hotel->reservations[j + 1];
            }

            (*numReservations)--;
            printf("Rezervasyon iptal edildi.\n");
            break;
        }
    }

    if (!found) {
        printf("Belirtilen oda numarasina sahip rezervasyon bulunamadi.\n");
    }
}

int main() {
    struct Hotel hotel;
    int numReservations = 0;

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                makeReservation(&hotel, &numReservations);
                break;
            case 2:
                displayReservations(hotel, numReservations);
                break;
            case 3:
                cancelReservation(&hotel, &numReservations);
                break;
            case 4:
                printf("Programdan cikiliyor...\n");
                break;
            default:
                printf("Gecersiz secim. Lütfen tekrar deneyin.\n");
        }
    } while (choice != 4);

    return 0;
}
