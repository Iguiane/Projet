
#include <stdio.h>
#include <stdlib.h>
void getDim(int* ligne);
int** alloue(int ligne, int** pasc);
void remplissage(int ligne ,int** pasc);
void affichage(int ligne ,int**  pasc);

int main (){
	int ligne=0;
	int** Pasc=NULL;
	getDim(&ligne);
	Pasc=alloue(ligne,Pasc);
	remplissage(ligne , Pasc);	
	affichage(ligne , Pasc);
	
	return 0;
}	
void getDim(int *ligne){
	
	printf("Entrer le degrée du puissance: ");
	scanf("%d",ligne);
	*ligne=*ligne+1;
	
}	
int** alloue(int ligne,int** pasc){
	pasc=(int**)malloc(ligne+1* sizeof(int*));
	
	for(int i=0; i<ligne; i++){
		*(pasc+i)=(int*)malloc(ligne+1* sizeof(int));
	}
	return pasc;
}		
void remplissage(int ligne ,int** pasc){
	for(int i=1; i< ligne; i++){
		for(int j=0; j<ligne; j++){
			if(j==0){
				pasc[i][j]=1;
			}
			else if(i>1  && j>0){	
				pasc[i][j]=pasc[i-1][j-1] +pasc[i-1][j];
			}
		}
	}
}		
void affichage(int ligne ,int**  pasc){
	int li=0, col=0;
	printf("On va calculer la combnaison de nCp tel que n>p vous le savez !!!");
	printf("Entrez n tel que  n soit inferieur ou egale au degrée du puissance:  ");
	scanf("%d",&li);
	printf("Entrez p : ");
	scanf("%d",&col);
	printf("La combinaison de %dC%d est: ",li,col);
	
	
	for(int i=1; i<ligne; i++){
		for(int j=0; j<i; j++){
			if(i==(li+1) && j==col)
			printf("%d \t",pasc[i][j]);
		}
		//printf("\n");
	}
	


}			
			
