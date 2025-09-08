#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nom[25],prenom[25],sexe[25],email[25];
    int age;

    printf("entrer votre nom: \n");
    scanf("%s" , nom);
    printf("entrer votre prenom: \n");
    scanf("%s",  prenom);
     printf("entrer votre sexe: \n");
    scanf("%s",  sexe);
    printf("entrer votre age: \n");
    scanf("%d" ,& age);
    printf("entrer votre email: \n");
    scanf("%s" , email);

    return 0;
}
