#include <stdio.h>
#include <stdlib.h>

int main()


{
    int T;
    printf("entrer la temperature de l'eau : ");
    scanf("%d",&T);

    if (T <= 0){
        printf("l'eau est Solide (glace)");
    }

    else if (T > 0 && T < 100){
        printf("l'eau est Liquide (eau)");
    }

    else {
        printf("l'eau est Gaz (vapeur)");
        }

    return 0;
}
