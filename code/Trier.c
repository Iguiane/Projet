#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Trier.h"
#define ligne 10
void Complete_Info(FILE* file,Etudiant info[]){
	for(int i=0;i<1;i++){
		printf("NOMS: ");
		scanf("%s",info[i].nom);
	///gerer une espace
		
		printf("PRENOMS: ");
		getchar();
		fgets(info[i].prenoms,255,stdin);
		info[i].prenoms[strcspn(info[i].prenoms,"\n")]='\0';
		///*******///
		printf("Adresse mail: ");
		scanf("%s",info[i].adresse);
		
		printf("Date de naissance: ");
		scanf("%s",info[i].date);
		
		
		printf("Adresse github: ");
		scanf("%s",info[i].github);
		
		fprintf(file,"%s\t%s\t%s\t%s\t%s\tMISA\tL1",info[i].nom,info[i].prenoms,info[i].adresse,info[i].date,info[i].github);
		
		system("clear");

	}
	
}
char** allocation(int taille){
	char** tab=NULL;
	tab=(char**)malloc(taille*sizeof(char*));
	for(int i=0;i<taille;i++)
		tab[i]=(char*)malloc(255*sizeof(char));
	return tab;

}
///renseignement des PC
void Etiquette_PC(FILE* fic,int taille,PC *machine){
	for(int i=0;i<taille;i++){
		
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
///pour l' information du nom
void triage(FILE* fichier,int taille,int *i,FILE *nouveau){
		char** enr=allocation(taille);
		
		printf("\nDans le tableau\n");
		for( (*i)=0;feof(fichier)!=1;(*i)++){
			fgets(enr[*i],255,fichier);
			printf("%s",enr[(*i)]);
		}

///triage
	char tmp[255];
	for(int j=0;j<*i-1;j++){
		for(int k=j+1;k<*i-1;k++){
			if(strcmp(enr[j],enr[k])>0){
				strcpy(tmp,enr[k]);
				strcpy(enr[k],enr[j]);
				strcpy(enr[j],tmp);

			}
		}
	}
	char nom[50]="",prenom[50]="",email[50]="",git[50]="",mention[50]="",grade[50]="";
	for(int j=0;j<*i;j++){
		sscanf(enr[j],"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", nom,prenom,email,git,mention,grade);
		//printf("%s\t%s\t%s\t%s\t%s\t%s",nom,prenom,email,git,mention,grade);
		fprintf(nouveau,"%s\t%s\t%s\t%s\t%s\t%s\n",nom,prenom,email,git,mention,grade);
	}
	///misy espace
	//return enr;
		
}
/*void ApresTriage(int i,FILE* fichier,int taille,FILE *nouveau){
	char** enr=allocation(taille);
	enr=triage(fichier, taille,&i);
	char nom[50]="",prenom[50]="",email[50]="",git[50]="",mention[50]="",grade[50]="";
		
	for(int j=0;j<i;j++){
		sscanf(enr[j],"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", nom,prenom,email,git,mention,grade);
		printf("%s\t%s\t%s\t%s\t%s\t%s\n",nom,prenom,email,git,mention,grade);
		fprintf(nouveau,"%s\t%s\t%s\t%s\t%s\t%s\n",nom,prenom,email,git,mention,grade);
	}
}
*/	
