#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("entrer le nombre entier x: ");
    scanf("%d",&x);
    if(x>0)
    {
        printf("donc x est pair",x);
    }else{
        printf("donc x est impair",x);
    }
    return 0;
}
