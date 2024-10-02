#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100

// Structures pour stocker les informations sur les livres
char titles[MAX_BOOKS][TITLE_LENGTH];
char authors[MAX_BOOKS][AUTHOR_LENGTH];
float prices[MAX_BOOKS];
int quantities[MAX_BOOKS];
int book_count = 0;

// Fonction pour ajouter un livre au stock
void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Le stock est plein, impossible d'ajouter plus de livres.\n");
        return;
    }
    printf("Entrez le titre du livre : ");
    scanf(" %[^\n]", titles[book_count]);
    printf("Entrez l'auteur du livre : ");
    scanf(" %[^\n]", authors[book_count]);
    printf("Entrez le prix du livre : ");
    scanf("%f", &prices[book_count]);
    printf("Entrez la quantité en stock : ");
    scanf("%d", &quantities[book_count]);
    book_count++;
    printf("Livre ajouté avec succès.\n");
}

// Fonction pour afficher tous les livres disponibles
void display_books() {
    if (book_count == 0) {
        printf("Aucun livre en stock.\n");
        return;
    }
    printf("\nListe des livres disponibles :\n");
    for (int i = 0; i < book_count; i++) {
        printf("Titre : %s | Auteur : %s | Prix : %.2f | Quantité : %d\n",
               titles[i], authors[i], prices[i], quantities[i]);
    }
}

// Fonction pour rechercher un livre par son titre
void search_book() {
    char title[TITLE_LENGTH];
    printf("Entrez le titre du livre à rechercher : ");
    scanf(" %[^\n]", title);

    for (int i = 0; i < book_count; i++) {
        if (strcmp(titles[i], title) == 0) {
            printf("Livre trouvé : Titre : %s | Auteur : %s | Prix : %.2f | Quantité : %d\n",
                   titles[i], authors[i], prices[i], quantities[i]);
            return;
        }
    }
    printf("Livre non trouvé.\n");
}

// Fonction pour mettre à jour la quantité d'un livre
void update_quantity() {
    char title[TITLE_LENGTH];
    printf("Entrez le titre du livre à mettre à jour : ");
    scanf(" %[^\n]", title);

    for (int i = 0; i < book_count; i++) {
        if (strcmp(titles[i], title) == 0) {
            printf("Entrez la nouvelle quantité : ");
            scanf("%d", &quantities[i]);
            printf("Quantité mise à jour avec succès.\n");
            return;
        }
    }
    printf("Livre non trouvé.\n");
}

// Fonction pour supprimer un livre du stock
void delete_book() {
    char title[TITLE_LENGTH];
    printf("Entrez le titre du livre à supprimer : ");
    scanf(" %[^\n]", title);

    for (int i = 0; i < book_count; i++) {
        if (strcmp(titles[i], title) == 0) {
            // Décaler les livres restants
            for (int j = i; j < book_count - 1; j++) {
                strcpy(titles[j], titles[j + 1]);
                strcpy(authors[j], authors[j + 1]);
                prices[j] = prices[j + 1];
                quantities[j] = quantities[j + 1];
            }
            book_count--;
            printf("Livre supprimé avec succès.\n");
            return;
        }
    }
    printf("Livre non trouvé.\n");
}

// Fonction pour afficher le nombre total de livres en stock
void display_total_books() {
    int total = 0;
    for (int i = 0; i < book_count; i++) {
        total += quantities[i];
    }
    printf("Nombre total de livres en stock : %d\n", total);
}

// Fonction principale
int main() {
    int choice;
    do {
        printf("\nMenu :\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher tous les livres\n");
        printf("3. Rechercher un livre\n");
        printf("4. Mettre à jour la quantité d'un livre\n");
        printf("5. Supprimer un livre\n");
        printf("6. Afficher le nombre total de livres en stock\n");
        printf("7. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_book(); break;
            case 2: display_books(); break;
            case 3: search_book(); break;
            case 4: update_quantity(); break;
            case 5: delete_book(); break;
            case 6: display_total_books(); break;
            case 7: printf("Au revoir !\n"); break;
            default: printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choice != 7);

    return 0;
}
