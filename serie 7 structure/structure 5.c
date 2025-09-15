#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct livre{
    char titre[50];
    char auteur[50];
    int annee;
};
 struct livre initialiser_livre(char *titre,char *auteur,int annee){

    struct livre book;
    strcpy(book.titre,titre);
    strcpy(book.auteur,auteur);
    book.annee=annee;
    return book;
};
int main()
{
    //remplissage
   struct livre mon_livre = initialiser_livre("mon_code","meri",2025);

    // affichage
    printf("le titre: %s\n",mon_livre.titre);
    printf("l'auteur: %s\n",mon_livre.auteur);
    printf("l'annee: %d\n",mon_livre.annee);

    return 0;
}
