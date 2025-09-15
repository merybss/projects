#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produit {
    char nom[20];
    int prix;
    int quantite;
};

int main() {
    struct produit p1 = {"fromage", 20, 12};
    struct produit p2 = {"lait", 15, 20};
    struct produit p3 = {"pain", 11, 12};

    printf("%s , %d , %d\n", p1.nom, p1.prix, p1.quantite);
    printf("%s , %d , %d\n", p2.nom, p2.prix, p2.quantite);
    printf("%s , %d , %d\n", p3.nom, p3.prix, p3.quantite);

    return 0;
}
