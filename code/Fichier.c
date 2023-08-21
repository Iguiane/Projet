#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (){
	FILE *test;
	test=fopen("presentation","r");
	if(test==NULL){
		exit(1);
	}
/*
 ///recuperation d' un seul caractere
		char m;
		m=fgetc(test);
		printf("%c",m);
		//boucle(1)
		
		for(int i=0;feof(test)!=1;i++){
			m=fgetc(test);
			printf("%c",m);
		}	
		
	
		
		while(feof(test)!=1){
			m=fgetc(test);
			printf("\n%c",m);
		}
		
		///enregistrement fichier dans une variable caractere par caractere
		
		int l=0;
		for(l=0;l<=i; l++)
			printf("%c",car[l]);
		
			
		for(int i=0;i<strlen(car)-1; i++)
			printf("%c",car[i]);

		

	///recuperation chaine de caract par ligne
	
		char ligne[256];
		for(int l=0; l<4;l++){
			fgets(ligne,255,test);
			printf("\n%s\n",ligne);
		}*/
		
		 //enregistrement dans une variable 
		 char enr[34][256];
		 int i=0;
		 for( i=0; feof(test)!=1;i++)
			 fgets(enr[i],255,test);
		int l=0;
		 for(l=0; l<=i ;l++)
		 printf("%s",enr[l]);
	
		///fermeture du fichier
		fclose(test);
		
		
		///ajouter un renseignement d'un autre personne
		FILE *fichier=fopen("presentation","a+");
		char car[250];
		printf("Entrez votre information:");
		scanf("%s",car);
		fprintf(fichier,"%s",car);
		/*fgets(car,60,sdtin);
		 */
		//tsy misy result 
		 char d[34];
		 for(int i=0;i<10;i++)
		 fscanf(fichier,"%c",d);
		 printf("\n");
		 for(int i=1;i<10;i++)
		 printf("%s",d);
		 //tsy misy result
	
		fclose(fichier);
		
			return 0;
}
