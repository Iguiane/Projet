#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
typedef struct{
	char nom[20];
	char prenoms[256];
	char adresse[20];
	char github[30];
	long int numero;
}Etudiant;	
void Complete_Info(FILE* file,Etudiant info[]);
int main (){
	Etudiant info[46];
	FILE *fichier;
	
	fichier=fopen("/home/mit/GUIANNA/Information.csv","a+");
	Complete_Info(fichier,info);
	fclose(fichier);

	return 0;
}

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
		
		printf("Adresse github: ");
		scanf("%s",info[i].github);
		
		fprintf(file,"%s\t%s\t%s\t%s\tMISA\tL1",info[i].nom,info[i].prenoms,info[i].adresse,info[i].github);
		
		system("clear");

	}
	
	
	
	
	//fprintf(file,"NOM\t PRENOMS\tMENTION\t GRADE \t NUMERO DE CLASSE\t ADRESSE\n");
	/*for(int i=0;i<3;i++){
		printf("NOMS: ");
		scanf("%s",info[i].nom);
		fprintf(file,"%s\t",info[i].nom);
		
		printf("PRENOMS: ");
		scanf("%s %s",info[i].prenom,info[i].prenoms);

		fprintf(file,"%s %s\t",info[i].prenom,info[i].prenoms);
		
		printf("MENTION: ");
		scanf("%s",info[i].mention);
		fprintf(file,"%s\t",info[i].mention);
		
		printf("GRADE: ");
		scanf("%s",info[i].grade);
		fprintf(file,"%s\t",info[i].grade);

		
		printf("Adresse: ");
		scanf("%s",info[i].adresse);
		fprintf(file,"%s\t",info[i].adresse);
		
		printf("Numéro de classe: ");
		scanf("%ld",&info[i].numero);
		fprintf(file,"%ld\n",info[i].numero);
		
		system("clear");

	}	
	*/
	
}
///recuperation des  données
