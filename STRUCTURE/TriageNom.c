#include <stdio.h>
#include "Trier.h"
int main (){
	FILE *fichier;
	FILE *nouv;
	fichier=fopen("Information.csv","r+");
	nouv=fopen("Mommer.csv","w+");
	int i=0;
	int taille=0;
	taille =45;
/*	if(feof(fichier)!=1){
		printf("On arrive pas à ecrire le fichier\n");
	}
*/
	ApresTriage(i, fichier,taille,nouv);
	fclose(fichier);
	fclose(nouv);
	return 0;
}
