#include <stdio.h>
#include <stdlib.h>


struct point{
   int x;
   int y;
};

int main()

{

    struct point dimension;
    struct point*ptr=&dimension;

     ptr->x=5;
     ptr->y=2;

   //afficher les resulats
   printf("x: %d\n",ptr->x);
   printf("y: %d\n",ptr->y);
    return 0;
}
