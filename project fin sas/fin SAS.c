#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXTE 2000
#define MAX_MOTS 500

// ===== Structure =====
typedef struct {
    char mot[50];
    int occurrences;
    int longueur;
} EntreeDictionnaire;

typedef struct {
    EntreeDictionnaire mots[MAX_MOTS];
    int mot_count;
} Dictionnaire;

// ===== Nettoyage du texte =====
void nettoyer_texte(char *texte) {
    for (int i = 0; texte[i] != '\0'; i++) {
        unsigned char c = texte[i];
        if (isupper(c)) texte[i] = tolower(c);
        if (ispunct(c)) texte[i] = ' ';
    }
}

// ===== Ajouter un mot =====
void ajouter_mot(Dictionnaire *dico, char *mot) {
    for (int i = 0; i < dico->mot_count; i++) {
        if (strcmp(dico->mots[i].mot, mot) == 0) {
            dico->mots[i].occurrences++;
            return;
        }
    }
    strcpy(dico->mots[dico->mot_count].mot, mot);
    dico->mots[dico->mot_count].occurrences = 1;
    dico->mots[dico->mot_count].longueur = strlen(mot);
    dico->mot_count++;
}

// ===== Analyser texte =====
void analyser_texte(Dictionnaire *dico, char *texte) {
    nettoyer_texte(texte);
    char *mot = strtok(texte, " \t\n");
    while (mot != NULL) {
        ajouter_mot(dico, mot);
        mot = strtok(NULL, " \t\n");
    }
}

// ===== Affichage dictionnaire =====
void afficher_dictionnaire(Dictionnaire *dico) {
    for (int i = 0; i < dico->mot_count; i++) {
        printf("%s (occurrences: %d, longueur: %d)\n",
               dico->mots[i].mot,
               dico->mots[i].occurrences,
               dico->mots[i].longueur);
    }
}

// ===== Recherche exacte =====
void recherche_exacte(Dictionnaire *dico, char *mot) {
    for (int i = 0; i < dico->mot_count; i++) {
        if (strcmp(dico->mots[i].mot, mot) == 0) {
            printf("Mot trouvé : %s (occurrences: %d, longueur: %d)\n",
                   dico->mots[i].mot,
                   dico->mots[i].occurrences,
                   dico->mots[i].longueur);
            return;
        }
    }
    printf("Mot '%s' non trouvé.\n", mot);
}

// ===== Recherche partielle =====
void recherche_partielle(Dictionnaire *dico, char *chaine) {
    int trouve = 0;
    for (int i = 0; i < dico->mot_count; i++) {
        if (strstr(dico->mots[i].mot, chaine) != NULL) {
            printf("%s (occurrences: %d)\n", dico->mots[i].mot, dico->mots[i].occurrences);
            trouve = 1;
        }
    }
    if (!trouve) printf("Aucun mot contenant '%s'\n", chaine);
}

// ===== Tris =====
void trier_alphabetique(Dictionnaire *dico) {
    for (int i = 0; i < dico->mot_count - 1; i++)
        for (int j = 0; j < dico->mot_count - i - 1; j++)
            if (strcmp(dico->mots[j].mot, dico->mots[j+1].mot) > 0) {
                EntreeDictionnaire tmp = dico->mots[j];
                dico->mots[j] = dico->mots[j+1];
                dico->mots[j+1] = tmp;
            }
}

void trier_frequence(Dictionnaire *dico) {
    for (int i = 0; i < dico->mot_count - 1; i++)
        for (int j = 0; j < dico->mot_count - i - 1; j++)
            if (dico->mots[j].occurrences < dico->mots[j+1].occurrences) {
                EntreeDictionnaire tmp = dico->mots[j];
                dico->mots[j] = dico->mots[j+1];
                dico->mots[j+1] = tmp;
            }
}

void trier_longueur(Dictionnaire *dico) {
    for (int i = 0; i < dico->mot_count - 1; i++)
        for (int j = 0; j < dico->mot_count - i - 1; j++)
            if (dico->mots[j].longueur > dico->mots[j+1].longueur) {
                EntreeDictionnaire tmp = dico->mots[j];
                dico->mots[j] = dico->mots[j+1];
                dico->mots[j+1] = tmp;
            }
}

// ===== Statistiques =====
void statistiques_globales(Dictionnaire *dico) {
    if (dico->mot_count == 0) { printf("Vide.\n"); return; }

    int total = 0, somme = 0;
    char mot_long[50], mot_court[50], mot_freq[50];
    int max_long = dico->mots[0].longueur, min_long = dico->mots[0].longueur, max_occ = dico->mots[0].occurrences;

    strcpy(mot_long, dico->mots[0].mot);
    strcpy(mot_court, dico->mots[0].mot);
    strcpy(mot_freq, dico->mots[0].mot);

    for (int i = 0; i < dico->mot_count; i++) {
        total += dico->mots[i].occurrences;
        somme += dico->mots[i].longueur;
        if (dico->mots[i].longueur > max_long) { max_long = dico->mots[i].longueur; strcpy(mot_long, dico->mots[i].mot); }
        if (dico->mots[i].longueur < min_long) { min_long = dico->mots[i].longueur; strcpy(mot_court, dico->mots[i].mot); }
        if (dico->mots[i].occurrences > max_occ) { max_occ = dico->mots[i].occurrences; strcpy(mot_freq, dico->mots[i].mot); }
    }

    printf("\n=== Statistiques ===\n");
    printf("Total mots: %d\n", total);
    printf("Mots uniques: %d\n", dico->mot_count);
    printf("Longueur moyenne: %.2f\n", (float)somme/dico->mot_count);
    printf("Mot le plus long: %s\n", mot_long);
    printf("Mot le plus court: %s\n", mot_court);
    printf("Mot le plus frequent: %s\n", mot_freq);
}

// ===== Palindrome =====
int est_palindrome(char *mot) {
    int len = strlen(mot);
    for (int i = 0; i < len/2; i++)
        if (mot[i] != mot[len-1-i]) return 0;
    return 1;
}

void afficher_palindromes(Dictionnaire *dico) {
    printf("\n=== Palindromes ===\n");
    for (int i = 0; i < dico->mot_count; i++) {
        if (est_palindrome(dico->mots[i].mot))
            printf("%s\n", dico->mots[i].mot);
    }
}

// ===== Anagramme simplifié =====
void trier_lettres(char *mot, char *sorted) {
    strcpy(sorted, mot);
    int n = strlen(sorted);
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (sorted[j] > sorted[j+1]) {
                char tmp = sorted[j];
                sorted[j] = sorted[j+1];
                sorted[j+1] = tmp;
            }
}

void afficher_anagrammes(Dictionnaire *dico) {
    printf("\n=== Anagrammes ===\n");
    char sorted1[50], sorted2[50];
    for (int i = 0; i < dico->mot_count; i++) {
        for (int j = i+1; j < dico->mot_count; j++) {
            if (strlen(dico->mots[i].mot) == strlen(dico->mots[j].mot)) {
                trier_lettres(dico->mots[i].mot, sorted1);
                trier_lettres(dico->mots[j].mot, sorted2);
                if (strcmp(sorted1, sorted2) == 0)
                    printf("%s <-> %s\n", dico->mots[i].mot, dico->mots[j].mot);
            }
        }
    }
}

// ===== Nuage de mots =====
void nuage_de_mots(Dictionnaire *dico) {
    printf("\n=== Nuage de mots ===\n");
    for (int i = 0; i < dico->mot_count; i++) {
        printf("%s ", dico->mots[i].mot);
        for (int j = 0; j < dico->mots[i].occurrences; j++) printf("*");
        printf("\n");
    }
}

// ===== MAIN =====
int main() {
    char texte[MAX_TEXTE];
    Dictionnaire dico = {0};
    int choix;
    do {
        printf("\n=== MENU ===\n");
        printf("1. Saisir texte et analyser\n");
        printf("2. Afficher dictionnaire\n");
        printf("3. Recherche exacte\n");
        printf("4. Recherche partielle\n");
        printf("5. Trier alphabetiquement\n");
        printf("6. Trier par frequence\n");
        printf("7. Trier par longueur\n");
        printf("8. Statistiques globales\n");
        printf("9. Palindromes\n");
        printf("10. Anagrammes\n");
        printf("11. Nuage de mots\n");
        printf("12. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);
        getchar(); // enlever le \n

        if (choix == 1) {
            printf("Entrez votre texte:\n");
            fgets(texte, MAX_TEXTE, stdin);
            dico.mot_count = 0;
            analyser_texte(&dico, texte);
        }
        else if (choix == 2) afficher_dictionnaire(&dico);
        else if (choix == 3) {
            char mot[50]; printf("Mot exact: "); scanf("%s", mot);
            recherche_exacte(&dico, mot);
        }
        else if (choix == 4) {
            char partiel[50]; printf("Mot partiel: "); scanf("%s", partiel);
            recherche_partielle(&dico, partiel);
        }
        else if (choix == 5) trier_alphabetique(&dico);
        else if (choix == 6) trier_frequence(&dico);
        else if (choix == 7) trier_longueur(&dico);
        else if (choix == 8) statistiques_globales(&dico);
        else if (choix == 9) afficher_palindromes(&dico);
        else if (choix == 10) afficher_anagrammes(&dico);
        else if (choix == 11) nuage_de_mots(&dico);

    } while (choix != 12);

    return 0;
}
