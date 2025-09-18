// Un mini moteur de recherche qui analyse un texte saisi par l’utilisateur.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MOT 20
#define TAILLE_TEXTE 2000
#define MAX_POS 200
#define MAX_MOTS 500

typedef struct {
    char mot[TAILLE_MOT];      // le mot
    int occurrences;           // nombre de présence du mot
    int longueur;              // longueur du mot
    int positions[MAX_POS];    // positions dans le texte
    int nbPositions;           // combien de positions enregistrées
} Mot;

Mot dictionnaire[MAX_MOTS];
int nbMots = 0;

// Prototypes des fonctions
void ajouterMot(char ajoute[], int position);
void analyserTexte(char texte[]);
void afficherDictionnaire(void);
void rechercherExact(char cherche[]);
void rechercherPartiel(char partiel[]);
void triAlpha();
void triFreq();
void triLongueur();
// Vérifier si un caractère est une lettre
int estLettre(char c){
    return ( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') );
}
// Analyser un texte et extraire les mots
void analyserTexte(char texte[]){
    char mot[TAILLE_MOT];
    int pos = 1;
    int i = 0, j = 0;

    while(texte[i] != '\0'){  // tant qu’on n’a pas atteint la fin du texte
        if(estLettre(texte[i])){
            if(texte[i] >= 'A' && texte[i] <= 'Z')
                mot[j++] = texte[i] + 32; // convertir majuscule → minuscule
            else
                mot[j++] = texte[i];
        } else {
            if(j > 0){
                mot[j] = '\0';
                ajouterMot(mot, pos++);
                j = 0;
            }
        }
        i++;
    }

    if(j > 0){
        mot[j] = '\0';
        ajouterMot(mot, pos++);
    }
}

// Ajouter un mot au dictionnaire
void ajouterMot(char ajoute[], int position){
    int i = 0;
    if(strlen(ajoute) == 0)
        return;

    while(i < nbMots){
        if(strcmp(dictionnaire[i].mot, ajoute) == 0){
            dictionnaire[i].occurrences++;
            dictionnaire[i].positions[dictionnaire[i].nbPositions++] = position;
            return;
        }
        i++;
    }
    strcpy(dictionnaire[nbMots].mot, ajoute);
    dictionnaire[nbMots].occurrences = 1;
    dictionnaire[nbMots].longueur = strlen(ajoute);
    dictionnaire[nbMots].positions[0] = position;
    dictionnaire[nbMots].nbPositions = 1;
    nbMots++;
}

// Afficher le dictionnaire
void afficherDictionnaire(){
    int i,j;
    for(i=0;i<nbMots;i++){
        printf("%s | occurrences = %d | longueur = %d | positions = ",
               dictionnaire[i].mot, dictionnaire[i].occurrences, dictionnaire[i].longueur);
        for(j=0;j<dictionnaire[i].nbPositions;j++){
            printf("%d ", dictionnaire[i].positions[j]);
        }
        printf("\n");
    }
}
// Recherche exacte
void rechercherExact(char cherche[]){
    int i,j;
    for(i=0;i<nbMots;i++){//on parcourt tous les mots uniques du dictionnaire.
        if(strcmp(dictionnaire[i].mot, cherche) == 0){
            printf("mot = %s | occurrences = %d | longueur = %d | positions = ",
                   dictionnaire[i].mot, dictionnaire[i].occurrences, dictionnaire[i].longueur);
            for(j=0;j<dictionnaire[i].nbPositions;j++){//pour afficher toute les positions
                printf("%d ", dictionnaire[i].positions[j]);
            }
            printf("\n");
            return;
        }
    }
    printf("Mot introuvable !\n");
}

// Recherche partielle
void rechercherPartiel(char partiel[]){
    int i, trouve = 0;//au moins un mot contient la sous chaine
    for(i=0;i<nbMots;i++){
        if(strstr(dictionnaire[i].mot, partiel) != NULL){
            printf("%s | occurrences = %d | longueur = %d\n",
                   dictionnaire[i].mot, dictionnaire[i].occurrences, dictionnaire[i].longueur);
            trouve = 1;
        }
    }
    if(!trouve) printf("Aucun mot trouvé contenant '%s'\n", partiel);
}

// Tri alphabétique
void triAlpha() {
    int i, j;
    Mot temp;
    for(i = 0; i < nbMots - 1; i++) {//parcourut chaque mot au dictionnaire
        for(j = i + 1; j < nbMots; j++) {//compare avec tout les mots situe apres i
            if(strcmp(dictionnaire[i].mot, dictionnaire[j].mot) > 0) {
                temp = dictionnaire[i];
                dictionnaire[i] = dictionnaire[j];
                dictionnaire[j] = temp;
            }
        }
    }
}

// Tri par fréquence
void triFreq() {
    int i, j;
    Mot temp;
    for(i = 0; i < nbMots - 1; i++) {
        for(j = i + 1; j < nbMots; j++) {
            if(dictionnaire[i].occurrences < dictionnaire[j].occurrences) {
                temp = dictionnaire[i];
                dictionnaire[i] = dictionnaire[j];
                dictionnaire[j] = temp;
            }
        }
    }
}

// Tri par longueur
void triLongueur(){
    int i, j;
    Mot temp;
    for(i = 0; i < nbMots - 1; i++) {
        for(j = i + 1; j < nbMots; j++) {
            if(dictionnaire[i].longueur > dictionnaire[j].longueur) {
                temp = dictionnaire[i];
                dictionnaire[i] = dictionnaire[j];
                dictionnaire[j] = temp;
            }
        }
    }
}

// Fonction principale
int main(){
    char texte[TAILLE_TEXTE], saisie[TAILLE_MOT];
    int choix, s;

    while(1){
        printf("\n===== Mini Moteur de Recherche =====\n");
        printf("1. Entrer et analyser un texte\n");
        printf("2. Afficher le dictionnaire\n");
        printf("3. Rechercher un mot exact\n");
        printf("4. Rechercher une sous-chaine\n");
        printf("5. Trier les mots\n");
        printf("6. Quitter\n");   // le menu a changé
        printf("Choix : ");
        scanf("%d", &choix);
        getchar(); // supprimer le retour chariot

        switch(choix){
            case 1:
                printf("Entrer un texte (max 2000 caracteres) :\n");
                fgets(texte, TAILLE_TEXTE, stdin);
                nbMots = 0;
                analyserTexte(texte);
                printf("Texte analysé avec succès !\n");
                break;
            case 2: afficherDictionnaire();
                break;
            case 3:
                printf("Entrer le mot : ");
                scanf("%s", saisie);
                rechercherExact(saisie);
                break;
            case 4:
                printf("Entrer la sous-chaine : ");
                scanf("%s", saisie);
                rechercherPartiel(saisie);
                break;
            case 5:
                printf("Trier par : 1-Alphabet 2-Frequence 3-Longueur : ");
                scanf("%d", &s);
                if(s==1) triAlpha();
                else if(s==2) triFreq();
                else if(s==3) triLongueur();
                printf("Tri effectué !\n");
                break;
            case 6: exit(0);   // quitter directement
        }
    }
}
