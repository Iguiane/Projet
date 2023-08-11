#include <stdio.h>
#include <stdlib.h>
int main (){
	FILE *fichier=NULL;
	//
	fichier=fopen("/home/mit/GUIANNA/texte.txt","r");
	
	/*printf("Entez votre nom de famille: ");
	char c[50];
	scanf("%s",c);
	fprintf(fichier,"%s",c);
	*/
	
	//fputs("  habitation :Ankatso \n",fichier);
	
	char c;
	
	while(feof(fichier)!=1){
		c=fgetc(fichier);
		printf("%c",c);
	}
	fclose(fichier);	
	 ///ajout des caractere dns une fichier
	FILE *ajout=NULL;
	ajout=fopen("/home/mit/GUIANNA/texte.txt","a");
	fputs("je n' ai pas d' autre chose à faire que celle là",fichier);
	fclose(ajout);


	return 0;
}
