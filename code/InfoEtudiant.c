#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
typedef struct{
	char nom[20];
	char prenom[200];
	char prenoms[20];
	char mention[20];
	char grade[20];
	char adresse[20];
	long int numero;
}Etudiant;	
void Info_Etudiant(Etudiant *info,FILE *fichier);
char** allocation(int taille);
void Triage(FILE *fichier,int taille);
int main (){
	Etudiant info[46];
	FILE *fichier;
	fichier=fopen("Information.csv","a+");
	int a=0;
	
///renseignement de chaque etudiant

	printf("Que voulez-vous faire :\n\t1-acceuillir les renseignements des étudiants\t2-Trier par ordre alphabet les noms des etudiants déjà enregistrées\n[...]:");
	scanf("%d",&a);
	
	if(a==1)
		Info_Etudiant(info,fichier);
	
///triage par alphabet 	
	else{
	Triage(fichier,46);
	}
	fclose(fichier);
	return 0;
}	
void Info_Etudiant(Etudiant *info,FILE *fichier){
	for(int i=0;i<1;i++){
		printf("NOMS: ");
		scanf("%s",info[i].nom);
	
		printf("PRENOMS: ");
		scanf("%s %s",info[i].prenom,info[i].prenoms);
			
		printf("Adresse mail: ");
		scanf("%s",info[i].adresse);
		fprintf(fichier,"%s\t%s %s\t%s\tMISA\tL1",info[i].nom,info[i].prenom,info[i].prenoms,info[i].adresse);
		
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
		nouveau=fopen("Information.csv","w");
		printf("Dans le nouveau fichier\n");   //printf
		for( j=0;j<taille;j++){
				printf("%s\n",enr[j]);
			fprintf(nouveau,"%s",enr[j]);
		}
		fclose(nouveau);


}
///programme initial
