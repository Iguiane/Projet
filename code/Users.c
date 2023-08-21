#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	FILE *fichier;
	FILE *affichage,*affiche;
	fichier=fopen("/etc/passwd","r");
	affichage=fopen("Afficher.txt","w+");
	affiche=fopen("Affiche.csv","w+");
	
	if(fichier==NULL){
		printf("Votre fichier est vide");
		exit(1);
	}
	if(affichage==NULL){
		printf("Votre fichier est vide");
		exit(1);
	}
	fprintf(affiche,"USERS\tINFO.USERS\tMOT DE PASSE\n");
	char enr[255];
	int UID=0,GID=0;
	char user[100],rep[100],shell[100];
	
	int i=0;
	char a[256],b[256];
	while(!feof(fichier)){
		fgets(enr,255,fichier); 
		sscanf(enr,"%[^:]:%*[^:]:%d:%d:%*[^:]:%[^:]:%[^:]",user,&UID,&GID,rep,shell);
		sscanf(enr,"%*[^:]:%*[^:]:%[^:]:%[^:]:%*[^:]:%*[^:]:%*[^:]",a,b);
		if(UID>=1000 && UID<=2000 && GID>=1000 && GID<2000){
			if(!feof(fichier)){
				printf("%s :%s :%s :%s",user,a,rep,shell);
				//fprintf(affichage,"%s :%s :%s :%s",user,a,rep,shell);
				fprintf(affichage,"%s\t:%s\t:%s",user,rep,shell);
				fprintf(affiche,"%s\t%s@mit.mg\t%d\n",user,user,rand());

			}
			i++;
			
		}
			
							
	}
		
	fclose(fichier);	
	fclose(affichage);
	fclose(affiche);
	
	return 0;
}
