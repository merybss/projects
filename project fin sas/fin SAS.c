#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//structures
struct mot{
    char valeur[50];     // le mot
    int occurrences;     // combien de fois il apparaît
    int longueur;        // longueur du mot
    int positions[2000]; // positions dans le texte
    int nombre_position; //nombre de position
};
//declaration du dictionnaire;
struct mot mot_dictionnaire[100];
int nbmots = 0;
//=====fonctions=====//
    //fonction pour mettre en minuscule
 void nettoyage_texte(char*texte){
       for(i=0;texte[i]!<'\0';i++){
         if(isupper(unsigned char(texte[i])))
        texte[i]=islower(texte[i])
       }

   //remplacer les ponctuation par espace
    if(ispunct(unsigned char(texte[i]))){
        texte[i]=' ';

     //fonction decoupage des mots
     void decoupage_texte(char*texte)
        char*mot=strtok(texte," \t\n");
    while(mot!=NULL){
        mot=strtok(NULL, " \t\n");
    }
    
void ajouter_mot(char*mot,int position){
    for(i=0;i<nbmots;i++){
       if(strcmp(mot_dictinnaire.valeur,mot)=0) {
        mot_dictionnaire[i].occurrence++;
        mot_dictionnaire[i].position[mot_dictionnaire[i].nombre_position++]=position;
        return;
       }
    }
//si on a nouveau mot
strcpy(mot_dictionnaire[nbmots].valeur,mot);
mot_dictionnaire[nmots].occurrence=1;
mot_dictionnaire[nmots].longeur=strlen(mot);
mot_dictionnaire[nmots].positions[0]=position;
mot_dictionnaire[nmots].nombre_position=1
}
void afficher_dictionnaire(){
printf("\n----dictionnaire----\n");
for(i=0;i<nbmots;i++){
    printf("%s : %d occurence(s),longeur=%d,postions=",
                mot_dictionnaire[i].valeur,
                mot_dictionnaire[i].occurences,
                mot_dictionnaire[i].longeur);
                
 for(int j=0;j<mot_dictionnaire[i].nombre_position;j++)               
   printf("%d",mot_dictionnaire[i].position[j]);
   printf("\n"); 
}
}



void ajouter_mot

int main()
{
    char texte[2000];  // tableau pour stocker le texte

    printf("tapez votre texte : ");
    fgets(texte, sizeof(texte), stdin);



/*//===== Main =====//
int main() {
    char texte[2000];  // tableau pour stocker le texte

    printf("Tapez votre texte :\n");
    fgets(texte, sizeof(texte), stdin);

    nettoyage_texte(texte);   // mise en minuscules + nettoyage ponctuation
    decoupage_texte(texte);   // remplir le dictionnaire

    afficher_dictionnaire();  // afficher le dictionnaire

    return 0;/*

}
    return 0;
}

}
