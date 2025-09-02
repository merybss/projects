#include <stdio.h>
#include <stdlib.h>

int main()
{
    float kmh,ms;
    printf("entrer la vitesse en km/h: \n");
    scanf("%f",&kmh);
    ms = kmh * 0.27778;
    printf("la distance en m/s est: %2.f\n",ms);
    return 0;
}
