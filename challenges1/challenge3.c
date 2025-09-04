#include <stdio.h>
#include <stdlib.h>

int main()
{
     float km,y;
   printf("entrer la distance en km: \n");
    scanf("%f",&km);
    y = km *1093.61;
    printf("la distance en yard est: %2.f\n",y);

    return 0;
}
