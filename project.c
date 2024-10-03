#include <stdio.h>
#include <string.h>

#define MAX_RESERVATIONS 100

typedef struct {
    int reference;
    char nom[50];
    char prenom[50];
    char telephone[15];
    int age;
    char statut[10];
    char date[15];
} Reservation;


Reservation reservations[MAX_RESERVATIONS];
int nombre_reservations = 0;
int generer_reference() {
 nombre_reservations + 1;  r le nombre de reservations
}


void ajouter_reservation() {
    if (nombre_reservations >= MAX_RESERVATIONS) {
        printf("Nombre maximum de r�servations atteint.\n");
        return;
    }
    Reservation nouvelle_reservation;
    nouvelle_reservation.reference = generer_reference();

    printf("Nom: ");
    scanf("%s", nouvelle_reservation.nom);
    printf("Prenom: ");
    scanf("%s", nouvelle_reservation.prenom);
    printf("Telephone: ");
    scanf("%s", nouvelle_reservation.telephone);
    printf("age: ");
    scanf("%d", &nouvelle_reservation.age);
    printf("Statut (valide, reporte, annule, traite): ");
    scanf("%s", nouvelle_reservation.statut);
    printf("Date de reservation (JJ/MM/AAAA): ");
    scanf("%s", nouvelle_reservation.date);

    reservations[nombre_reservations] = nouvelle_reservation;
    nombre_reservations++;

    printf("R�servation ajoutee avec succes ! Reference : %d\n", nouvelle_reservation.reference);
}


int rechercher_par_reference(int reference) {
    for (int i = 0; i < nombre_reservations; i++) {
        if (reservations[i].reference == reference) {
            return i;
        }
    }
    return -1;
}

void modifier_reservation() {
    int reference;
    printf("Entrez la reference de la reservation a modifier: ");
    scanf("%d", &reference);

    int index = rechercher_par_reference(reference);
    if (index == -1) {
        printf("R�servation non trouvee.\n");
        return;
    }

    printf("Modifier les informations (laisser vide pour conserver les valeurs actuelles).\n");
    printf("Nom (%s): ", reservations[index].nom);
    scanf("%s", reservations[index].nom);
    printf("Prenom (%s): ", reservations[index].prenom);
    scanf("%s", reservations[index].prenom);
    printf("Telephone (%s): ", reservations[index].telephone);
    scanf("%s", reservations[index].telephone);
    printf("age (%d): ", reservations[index].age);
    scanf("%d", &reservations[index].age);
    printf("Statut (%s): ", reservations[index].statut);
    scanf("%s", reservations[index].statut);
    printf("Date de reservation (%s): ", reservations[index].date);
    scanf("%s", reservations[index].date);

    printf("Reservation modifi�e avec succ�s.\n");
}

void supprimer_reservation() {
    int reference;
    printf("Entrez la r�f�rence de la reservation � supprimer: ");
    scanf("%d", &reference);

    int index = rechercher_par_reference(reference);
    if (index == -1) {
        printf("Reservation non trouvee.\n");
        return;
    }

    for (int i = index; i < nombre_reservations - 1; i++) {
        reservations[i] = reservations[i + 1];
    }
    nombre_reservations--;

    printf("Reservation supprimee avec succes.\n");
}


int main() {
    int choix;

    do {
        printf("\n--- Menu Principal ---\n");
        printf("1. Ajouter une reservation\n");
        printf("2. Modifier une reservation\n");
        printf("3. Supprimer une reservation\n");
        printf("0. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_reservation();
                break;
            case 2:
                modifier_reservation();
                break;
            case 3:
                supprimer_reservation();
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide.\n");
                break;
        }
    } while (choix != 0);

    return 0;
}
