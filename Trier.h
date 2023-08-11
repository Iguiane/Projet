#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define ligne 10
typedef struct{
	char  etiquette[30];
	char  marque[30];
	char  mac[30];
}PC;
typedef struct{
	char nom[20];
	char prenoms[256];
	char adresse[20];
	char date[20];
	char github[30];
	long int numero;
}Etudiant;	
void Complete_Info(FILE* file,Etudiant info[]);
char** allocation();
///renseignement des PC
void Etiquette_PC(FILE* fic,int taille,PC *machine);
char** recuperation(FILE* fic);
PC Triage_Donnees(PC *machine,FILE*fic);
void ecriture(FILE* fic1,FILE* fic2);
///pour l' information du nom

void triage(FILE* fichier,int taille,int *i,FILE *nouveau);
//void ApresTriage(int i,FILE* fichier,int taille,FILE *nouveau);
