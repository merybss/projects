#include <stdio.h>
#include <stdlib.h>



int main() {
    float rayon, volume;
    const float PI = 3.14159;


    printf("Entrez le rayon de la sphere : ");
    scanf("%f", &rayon);


    volume = (4.0 / 3.0) * PI * pow(rayon, 3);

    printf("Le volume de la sphere de rayon %.2f est : %.2f\n", rayon, volume);

    return 0;
}



