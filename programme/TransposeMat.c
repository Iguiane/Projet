#include <stdio.h>
#include <stdlib.h>
int  EntrezLigne();
int  EntrezColonne();
int** Allocation(int ligne,int colonne);
int** EntrezValeur(int ligne, int colonne);
int** Transposition(int ligne, int colonne);
int main (){
	int ligne=0,colonne=0;
	
	ligne=EntrezLigne();
	colonne=EntrezColonne();
	
	Transposition(ligne,  colonne);

	
	return 0;
}
int  EntrezLigne(){
		int l=0;
		printf("Entrez le nombre de lignes:");
		scanf("%d",&l);
		return l;
}
int  EntrezColonne(){
		int l=0;
		printf("Entrez le nombre de colonnes:");
		scanf("%d",&l);
		return l;
}
int** Allocation(int ligne,int colonne){
		int** mat=NULL;
		mat=(int**)malloc(ligne*sizeof(int*));
		for(int i=0; i<ligne; i++){
			*(mat+i)=(int*)malloc(colonne*sizeof(int));
		}
		return mat;	
	
}

int** EntrezValeur(int ligne, int colonne){
	int** mat=Allocation( ligne, colonne);
	for(int i=0; i<ligne; i++){
		for(int j=0; j<colonne; j++){
				printf("mat[%d][%d]= ",i,j);
				scanf("%d", &(*(*(mat+i)+j)));
		}
	}
	return mat;
}		
int** Transposition(int ligne, int colonne){
	int** tab=Allocation( ligne, colonne);
	int** mat=Allocation(colonne,ligne);
	
	tab= EntrezValeur( ligne,  colonne);
	

	
	for(int i=0 ;i <colonne; i++){
		for(int j=0; j<ligne ;j++){
			
			mat[i][j]=tab[j][i];
			
		}
	}
	for(int i=0 ;i<ligne; i++){
		for(int j=0; j<colonne;j++){
			printf("%d\t",tab[i][j]);
		}
		printf(" \n");
	}
	
	printf("\n");	
	printf("LA TRANSPOSÉE DE CETTE MATRICE EST:  \n");
	for(int i=0 ;i<colonne; i++){
		for(int j=0; j<ligne ;j++){
			printf("%d\t",mat[i][j]);
		}
		printf(" \n");
	}
	
	return mat;		
		
}


