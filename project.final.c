#include <stdio.h>
#include <string.h>

#define max_reservations 100

typedef struct {
    char nom[50];
    char prenom[50];
    char telephone[15];
    int age;
    char statut[20];
    int reference;
    char date[20];
} reservation;

reservation reservations[max_reservations];
int compteur_reservations = 0;

void ajouter_reservation(char* nom, char* prenom, char* telephone, int age, char* statut, char* date) {
    if (compteur_reservations < max_reservations) {
        strcpy(reservations[compteur_reservations].nom, nom);
        strcpy(reservations[compteur_reservations].prenom, prenom);
        strcpy(reservations[compteur_reservations].telephone, telephone);
        reservations[compteur_reservations].age = age;
        strcpy(reservations[compteur_reservations].statut, statut);
        reservations[compteur_reservations].reference = compteur_reservations + 1;
        strcpy(reservations[compteur_reservations].date, date);
        compteur_reservations++;
    }
}

void modifier_reservation(int reference, char* nom, char* prenom, char* telephone, int age, char* statut, char* date) {
    for (int i = 0; i < compteur_reservations; i++) {
        if (reservations[i].reference == reference) {
            strcpy(reservations[i].nom, nom);
            strcpy(reservations[i].prenom, prenom);
            strcpy(reservations[i].telephone, telephone);
            reservations[i].age = age;
            strcpy(reservations[i].statut, statut);
            strcpy(reservations[i].date, date);
            return;
        }
    }
}

void supprimer_reservation(int reference) {
    for (int i = 0; i < compteur_reservations; i++) {
        if (reservations[i].reference == reference) {
            reservations[i] = reservations[compteur_reservations - 1];
            compteur_reservations--;
            return;
        }
    }
}

void afficher_reservation(int reference) {
    for (int i = 0; i < compteur_reservations; i++) {
        if (reservations[i].reference == reference) {
            printf("nom: %s\n", reservations[i].nom);
            printf("prenom: %s\n", reservations[i].prenom);
            printf("telephone: %s\n", reservations[i].telephone);
            printf("age: %d\n", reservations[i].age);
            printf("statut: %s\n", reservations[i].statut);
            printf("date: %s\n", reservations[i].date);
            return;
        }
    }
    printf("reservation non trouvee.\n");
}

int main() {
    int choix;
    char nom[50], prenom[50], telephone[15], statut[20], date[20];
    int age, reference;

    while (1) {
        printf("1. ajouter une reservation\n");
        printf("2. modifier une reservation\n");
        printf("3. supprimer une reservation\n");
        printf("4. afficher une reservation\n");
        printf("5. quitter\n");
        printf("choix: ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1:
                printf("nom: "); fgets(nom, 50, stdin); nom[strcspn(nom, "\n")] = '\0';
                printf("prenom: "); fgets(prenom, 50, stdin); prenom[strcspn(prenom, "\n")] = '\0';
                printf("telephone: "); fgets(telephone, 20, stdin); telephone[strcspn(telephone, "\n")] = '\0';
                printf("age: "); scanf("%d", &age);
                getchar(); // pour consommer
                printf("statut: "); fgets(statut, 20, stdin); statut[strcspn(statut, "\n")] = '\0';
                printf("date: "); fgets(date, 20, stdin); date[strcspn(date, "\n")] = '\0';
                ajouter_reservation(nom, prenom, telephone, age, statut, date);
                break;
            case 2:
                printf("reference: "); scanf("%d", &reference);
                getchar();
                printf("nom: "); fgets(nom, 50, stdin); nom[strcspn(nom, "\n")] = '\0';
                printf("prenom: "); fgets(prenom, 50, stdin); prenom[strcspn(prenom, "\n")] = '\0';
                printf("telephone: "); fgets(telephone, 20, stdin); telephone[strcspn(telephone, "\n")] = '\0';
                printf("age: "); scanf("%d", &age);
                getchar();
                printf("statut: "); fgets(statut, 20, stdin); statut[strcspn(statut, "\n")] = '\0';
                printf("date: "); fgets(date, 20, stdin); date[strcspn(date, "\n")] = '\0';
                modifier_reservation(reference, nom, prenom, telephone, age, statut, date);
                break;
            case 3:
                printf("reference: "); scanf("%d", &reference);
                supprimer_reservation(reference);
                break;
            case 4:
                printf("reference: "); scanf("%d", &reference);
                afficher_reservation(reference);
                break;
            case 5:
                return 0;
            default:
                printf("choix invalide.\n");
        }
    }

    return 0;
}
