#include <stdio.h>
#include <stdlib.h>



    #include <stdio.h>

int main() {
    float a, b, c;   // les trois nombres
    float moyenne;   // résultat

    // Saisie des trois nombres
    printf("Entrez le premier nombre : ");
    scanf("%f", &a);

    printf("Entrez le deuxieme nombre : ");
    scanf("%f", &b);

    printf("Entrez le troisieme nombre : ");
    scanf("%f", &c);

    // Calcul de la moyenne pondérée
    moyenne = (a * 2 + b * 3 + c * 5) / (2 + 3 + 5);

    // Affichage du résultat
    printf("\n--- Resultat ---\n");
    printf("La moyenne ponderee est : %.2f\n", moyenne);

    return 0;
}


