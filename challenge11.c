#include <stdio.h>
#include <stdlib.h>

int main()
{
    float largeur,longeur;
    float S,P;
    printf("entrer la largeur du rectangle: ");
    scanf("%f",&largeur);
    printf("entrer la longeur du rectangle: ");
    scanf("%f",&longeur);
    S=largeur*longeur;
    P=(largeur+longeur)/2;
    printf("la largeur du rectangle est: %.2f \n",P);
    printf("la longeur du rectangle est: %.2f \n",S);
    return 0;
}
