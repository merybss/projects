#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    printf("entrer le caractere: \n");
    scanf("%c",&c);
    switch(c){
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':

    printf(" %c est un voyelle \n",c) ;
     break;
        default:
    printf("%c n'est pas un voyelle \n",c );
             }




    return 0;
}
