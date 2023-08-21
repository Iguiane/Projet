#include <stdio.h>
#include "Trier.h"
int main(){ 
	FILE* fic1=fopen("CaracteristiquePc.csv","r");
	FILE* fic2=fopen("Caracteristique.csv","w+");  //nouveau fichier apres triage
	
///info PC
	//PC machine[50]; 
	//int taille;
	//Etiquette_PC(fic1, taille,machine);
///trier les infos deja existés
	ecriture(fic1,fic2);
	fclose(fic1);
	fclose(fic2);
	

 

	return 0;
} 

