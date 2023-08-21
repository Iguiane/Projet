#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main()
{
    char is_leap[257];
	printf("Entrez une annee soit REGULAR ou soit BISSEXTILE:\n::::");
    scanf("%[^\n]", is_leap); fgetc(stdin);
    char year_type[257];
    printf("Entrez une type d' année juif  soit SERIAL , soit PLEINE,soit MANQUANTE\n::::");
    scanf("%[^\n]", year_type);
    int j=0,jours=0,x=0;
    j=(5*29)+(5*30);
   
   
    if(strcmp(is_leap,"REGULAR")==0){
		if(strcmp(year_type,"SERIAL")==0)
			x=29+30;
			
		if(strcmp(year_type,"MANQUANTE")==0)
			x=2*29;
		
		if(strcmp(year_type," PLEINE")==0)
			x=2*30;
	jours=j+x;		
	}	
	else if(!(strcmp(is_leap,"REGULAR")==0)){
		if(strcmp(year_type,"SERIAL")==0)
			x=29+30;
			
		if(strcmp(year_type,"MANQUANTE")==0)
			x=2*29;
		
		if(strcmp(year_type," PLEINE")==0)
			x=2*30;
	jours=j+x+29;
	}
	printf("Le nombre de jours de l' annéé %s %s  est %d",is_leap,year_type,jours);	
        

    


    
  

    return 0;
}
