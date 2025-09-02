#include <stdio.h>
#include <stdlib.h>



    #include <stdio.h>

int main() {
    float a, b; // variables pour stocker les nombres saisis


    printf("Entrez le premier nombre : ");
    scanf("%f", &a);

    printf("Entrez le deuxieme nombre : ");
    scanf("%f", &b);

    // Afficher les résultats
    printf("\n--- Resultats ---\n");
    printf("%.2f + %.2f = %.2f\n", a, b, a + b);
    printf("%.2f - %.2f = %.2f\n", a, b, a - b);
    printf("%.2f * %.2f = %.2f\n", a, b, a * b);

    // Vérifier la division par zéro
    if (b != 0) {
        printf("%.2f / %.2f = %.2f\n", a, b, a / b);
    } else {
        printf("Erreur : division par zero impossible.\n");
    }

    return 0;
}
