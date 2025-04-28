#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define ROUGE "\x1b[31m"
#define VERT "\x1b[32m"
#define JAUNE "\x1b[33m"
#define BLEU "\x1b[34m"
#define RESET "\x1b[0m"


// Définition de la structure Contact
struct Contact {
  char nom[50];
  char telephone[20];
  char email[50];
};

// Tableau pour stocker les contacts
struct Contact contacts[MAX_CONTACTS];
int totalContacts = 0;

// Ajouter un contact
void ajouterContact() {
  if (totalContacts >= MAX_CONTACTS) {
    printf("La liste de contacts est pleine.\n");
    return;
  } else
    printf("Entrez le nom : ");
  scanf("%s", contacts[totalContacts].nom);
  printf("Entrez le numéro de téléphone : ");
  scanf("%s", contacts[totalContacts].telephone);
  printf("Entrez l'adresse email : ");
  scanf("%s", contacts[totalContacts].email);

  totalContacts++;
  printf(VERT "Le contact a été bien ajouté !\n" RESET);

}

// Rechercher un contact par nom
void rechercherContact() {
    char nomRecherche[50];
    int trouve = 0;

    printf("Entrez le nom à rechercher : ");
    scanf("%s", nomRecherche);

    for (int i = 0; i < totalContacts; i++) {
        if (strcmp(contacts[i].nom, nomRecherche) == 0) {
            printf("Contact trouvé :\n");
            printf("Nom : %s\n", contacts[i].nom);
            printf("Téléphone : %s\n", contacts[i].telephone);
            printf("Email : %s\n", contacts[i].email);
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf(ROUGE "Aucun contact trouvé avec ce nom.\n" RESET);
    }
}

// Afficher tous les contacts
void afficherContacts() {
  if (totalContacts == 0) {
    printf(ROUGE"Aucun contact à afficher.\n" RESET);
    return;
  } else
    printf(VERT"\nListe des contacts :\n" RESET);
  for (int i = 0; i < totalContacts; i++) {
    printf("\nContact %d\n", i + 1);
    printf("Nom : %s\n", contacts[i].nom);
    printf("Téléphone : %s\n", contacts[i].telephone);
    printf("Email : %s\n", contacts[i].email);
  }
}

// Supprimer un contact
void supprimerContact() {
    char nom[50];
    int trouve = 0;

    printf("Entrez le nom du contact à supprimer : ");
    scanf("%s", nom);

    for (int i = 0; i < totalContacts; i++) {
        if (strcmp(contacts[i].nom, nom) == 0) {
            for (int j = i; j < totalContacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            totalContacts--;
            trouve = 1;
            printf("Contact supprimé avec succès.\n");
            break;
        }
    }

    if (!trouve) {
        printf(ROUGE "Aucun contact trouvé avec ce nom.\n" RESET);
    }
}


// Modifier un contact
void modifierContact() {
    char nom[50];
    int trouve = 0;

    printf("Entrez le nom du contact à modifier : ");
    scanf("%s", nom);

    for (int i = 0; i < totalContacts; i++) {
        if (strcmp(contacts[i].nom, nom) == 0) {
            printf("Nouveau nom : ");
            scanf("%s", contacts[i].nom);
            printf("Nouveau téléphone : ");
            scanf("%s", contacts[i].telephone);
            printf("Nouvel email : ");
            scanf("%s", contacts[i].email);
            printf(VERT "Contact modifié avec succès.\n" RESET);
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf(ROUGE "Aucun contact trouvé avec ce nom.\n" RESET);
    }
}


// Menu principal
int main() {
  int choix;

  do {
    printf(JAUNE "\n----- Gestionnaire de Contacts -----\n" RESET);
    printf(BLEU "1. Ajouter un contact\n" RESET);
    printf(BLEU "2. Rechercher un contact\n" RESET);
    printf(BLEU "3. Afficher tous les contacts\n" RESET);
    printf(BLEU "4. Supprimer un contact\n" RESET);
    printf(BLEU "5. Modifier un contact\n" RESET);
    printf(BLEU "0. Quitter\n" RESET);
    printf("Votre choix : ");
    scanf("%d", &choix);

    switch (choix) {
    case 1:
      ajouterContact();
      break;
    case 2:
      rechercherContact();
      break;
    case 3:
      afficherContacts();
      break;
    case 4:
      supprimerContact();
      break;
    case 5:
      modifierContact();
      break;
    case 0:
      printf("Au revoir !\n");
      break;
    default:
      printf("Choix invalide. Veuillez réessayer.\n");
    }

  } while (choix != 0);

  return 0;
}