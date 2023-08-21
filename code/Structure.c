#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int size;
	char  etiquette[30];
	char  marque[30];
	char  mac[30];
}PC;
void Etiquette_PC(FILE* fic,PC taille,PC *machine);
int main(){ 
	FILE* fic;
	fic=fopen("CaracteristiquePc.csv","a+");
	//fprintf(fic,"ETIQUETTE \t MARQUE \t ADRESSE MAC");
	PC machine[12];
	PC taille;
	taille.size=1;
	Etiquette_PC(fic,taille,machine);
	/*for(int i=0;i<taille.size;i++){
		
		printf("Entrez le marque de votre ordi: ");
		scanf("%s",machine[i].marque);
		fprintf(fic,"%s\t",machine[i].marque);
		
		printf("Entrez l'etiquette: ");
		scanf("%s",machine[i].etiquette);
		fprintf(fic,"\n%s\t",machine[i].etiquette);
		

		printf("Entrez l' adresse mac: ");
		scanf("%s",machine[i].mac);
		printf("\n");
		fprintf(fic,"%s\n",machine[i].mac);

	}*/
	fclose(fic);
	return 0;
}
//struture 1
 
void Etiquette_PC(FILE* fic,PC taille,PC *machine){
	for(int i=0;i<taille.size;i++){
		
		printf("Entrez le marque de votre ordi: ");
		scanf("%s",machine[i].marque);
		fprintf(fic,"%s\t",machine[i].marque);
		
		printf("Entrez l'etiquette: ");
		scanf("%s",machine[i].etiquette);
		fprintf(fic,"%s\t",machine[i].etiquette);
		

		printf("Entrez l' adresse mac: ");
		scanf("%s",machine[i].mac);
		
		fprintf(fic,"%s\n",machine[i].mac);
		
	}
	
	
}
