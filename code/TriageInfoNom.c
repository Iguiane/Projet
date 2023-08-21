#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#define  ETUDIANT  45
char** allocation(int taille);
void Triage(FILE *fichier,int taille);
int main (){
	FILE *fichier;
	fichier=fopen("/home/mit/GUIANNA/Information.csv","r+");

	if(feof(fichier)!=1){
		printf("On arrive pas à ecrire le fichier\n");
	}

	Triage( fichier,ETUDIANT); //soit  43  nbre des etudiants
	fclose(fichier);
	return 0;
}
char** allocation(int taille){
	char** tab=NULL;
	tab=(char**)malloc(taille*sizeof(char*));
	for(int i=0;i<taille;i++)
		tab[i]=(char*)malloc(255*sizeof(char));
	return tab;

}
void Triage(FILE* fichier,int taille){
		int i=0,j=0;
		char** enr=allocation(taille);
		FILE *nouveau;

		for( i=0;feof(fichier)!=1;i++){
			fgets(enr[i],255,fichier);
		}

		printf("Dans le tableau\n");
		for( j=0;j<taille;j++){
			printf("%s\n",enr[j]);  //printf
		}
///triage
		char tmp[255];
		for(int i=0;i<taille;i++){
			for(int j=i+1;j<taille;j++){
				if(strcmp(enr[i],enr[j])>0){
					strcpy(tmp,enr[j]);
					strcpy(enr[j],enr[i]);
					strcpy(enr[i],tmp);

				}
			}
		 }

		nouveau=fopen("/home/mit/GUIANNA/Information.csv","w");
		printf("Dans le nouveau fichier\n");   //printf
		for( j=0;j<taille;j++){
				printf("%s\n",enr[j]);
			fprintf(nouveau,"%s",enr[j]);
		}
		fclose(nouveau);


}
