#include <stdio.h>
int main (){
	FILE *fichier;
	FILE *affichage;
	fichier=fopen("/etc/passwd","r");
	affichage=fopen("Affiche.csv","w");
	
	if(fichier==NULL){
		printf("Votre fichier est vide");
	}
	
	char enr[255];
	int UID=0,GID=0;
	char user[40],rep[40],shell[30];
	
	int i=0;
	for(i=0;feof(fichier)!=1;i++){
		fgets(enr,255,fichier);
		sscanf(enr,"%[^:]:%*[^:]:%d:%d:%*[^:]:%[^:]:%[^:]",user,&UID,&GID,rep,shell);
			
	
		if(UID>=1000 && UID<=1500 && GID>=1000 && GID<1500){
			printf("%s      %d   %s     %s\n",user,UID,rep,shell);
			fprintf(affichage,"%s      %d   %s     %s\n",user,UID,rep,shell);
		}	
					
	}
	
	fclose(affichage);
	fclose(fichier);
	
	int l=0;
		 for(l=0; l<=i ;l++)
		 
		 printf("  **** %s\n",enr);
		 
		
	return 0;
}
