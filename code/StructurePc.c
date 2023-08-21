#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ligne 10

typedef struct{
	char  etiquette[30];
	char  marque[30];
	char  mac[30];
}PC;
char** allocation();
char** recuperation(FILE* fic);
PC Triage_Donnees(PC *machine,FILE*fic1);
void ecriture(FILE*fic1,FILE*fic2);
int main(){ 
	FILE* fic1=fopen("CaracteristiquePc.csv","r");
	FILE* fic2=fopen("Caracteristique.csv","w+");
	
	ecriture(fic1,fic2);
	fclose(fic1);
	fclose(fic2);
	return 0;
} 
char** allocation(){
	char** tab=NULL;
	tab=(char**)malloc(ligne*sizeof(char*));
	for(int i=0;i<ligne;i++)
		tab[i]=(char*)malloc(255*sizeof(char));
	return tab;

}


char** recuperation(FILE* fic){	
	char** tab=NULL;
	tab=allocation(ligne);
	int i=0;
	for( i=0;feof(fic)!=1;i++){	
		fgets(tab[i],255,fic);
	}
	
	
	
	return tab;
}
PC Triage_Donnees(PC *machine,FILE*fic){
	char** donnees=NULL;
	
	donnees=recuperation(fic);
	for(int j=0;j<ligne;j++){
		sscanf(donnees[j],"%[^,],%[^,],%[^,]",machine[j].marque,machine[j].etiquette,machine[j].mac);
	}
	
	for( int k=0;k<ligne;k++){
		for( int j=k+1;j<ligne;j++){
			if(strcmp(machine[k].etiquette,machine[j].etiquette)>0){
				PC tmp=machine[j];
				machine[j]=machine[k];
				machine[k]=tmp;
			}
		}
	}
	
	
	
	return *machine;
}
void ecriture(FILE* fic1,FILE* fic2){
	PC computer[34];
	Triage_Donnees(computer,fic1);
	for(int j=0;j<ligne;j++){
		printf("%s  %s  %s",computer[j].marque,computer[j].etiquette,computer[j].mac);
		fprintf(fic2,"%s\t%s\t%s",computer[j].marque,computer[j].etiquette,computer[j].mac);
	}	
	
}
