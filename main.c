#include <stdio.h>
#include <stdlib.h>

#define MAX_TACHES 10


struct Tache {
    char description[100];
    int estComplete;
};


void ajouterTache(struct Tache listeTaches[], int *nombreTaches) {
    if (*nombreTaches < MAX_TACHES) {
        printf("Entrez la description de la tâche : ");
        scanf(" %[^\n]", listeTaches[*nombreTaches].description);
        listeTaches[*nombreTaches].estComplete = 0;
        (*nombreTaches)++;
        printf("Tâche ajoutée avec succès.\n");
    } else {
        printf("La liste de tâches est pleine.\n");
    }
}


void afficherListeTaches(struct Tache listeTaches[], int nombreTaches) {
    if (nombreTaches == 0) {
        printf("La liste de tâches est vide.\n");
    } else {
        printf("Liste de tâches :\n");
        for (int i = 0; i < nombreTaches; i++) {
            printf("%d. %s [%s]\n", i + 1, listeTaches[i].description,
                   listeTaches[i].estComplete ? "Complète" : "Non complète");
        }
    }
}


void marquerTacheComplete(struct Tache listeTaches[], int nombreTaches) {
    int choix;

    afficherListeTaches(listeTaches, nombreTaches);

    if (nombreTaches == 0) {
        return;
    }

    printf("Entrez le numéro de la tâche à marquer comme complète : ");
    scanf("%d", &choix);

    if (choix >= 1 && choix <= nombreTaches) {
        listeTaches[choix - 1].estComplete = 1;
        printf("La tâche a été marquée comme complète.\n");
    } else {
        printf("Numéro de tâche invalide.\n");
    }
}

int main() {
    struct Tache listeTaches[MAX_TACHES];
    int nombreTaches = 0;
    int choix;

    while (1) {
        printf("\nMenu :\n");
        printf("1. Ajouter une tâche\n");
        printf("2. Afficher la liste des tâches\n");
        printf("3. Marquer une tâche comme complète\n");
        printf("4. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterTache(listeTaches, &nombreTaches);
                break;
            case 2:
                afficherListeTaches(listeTaches, nombreTaches);
                break;
            case 3:
                marquerTacheComplete(listeTaches, nombreTaches);
                break;
            case 4:
                printf("Au revoir !\n");
                exit(0);
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    }

    return 0;
}
