/*addition matrice carres*/

#include <stdio.h>
#include <stdlib.h>
void getTaille(int *ligne, int *col);

int** allou2D(int ligne,int col, int** tab);
void getTab(int ligne,int col, int** tb);

int** alloutb(int ligne,int col,int** tb);
void getTB(int ligne,int col ,int** tb);

int** allouT(int ligne,int col,int** T);
int** AddMat(int ligne,int  col,int** tab, int** tb, int** T);

void Affichage(int ligne,int col,int** tab,int** tb ,int** T);
int main (){
	int ligne=0;
	int** tab=NULL;
	int** tb=NULL;
	int** T=NULL;
	int col=0;
	
	getTaille(&ligne, &col);
	
	tab=allou2D(ligne,col, tab);
	getTab(ligne,col, tab);
	
	tb=alloutb(ligne,col , tb);
	getTB(ligne,col , tb);
	
	T=allouT(ligne,col, T);
	AddMat(ligne, col,tab,tb,T);
	
	Affichage(ligne, col, tab,tb ,T);
	return 0;
}	
void getTaille(int *ligne, int *col){	
	printf("Entrer la taille du tableau: ");
	scanf("%d", ligne);
	*col=*ligne;
}	
int** allou2D(int ligne,int col, int** tb){

	tb=(int**)malloc(ligne* sizeof(int*));
	for(int i=0; i<col; i++){
		*(tb +i)=(int*)malloc(col* sizeof(int));
	}
	return tb;
}

void getTab(int ligne,int col, int** tab){
	for(int i=0; i<ligne; i++){
		for(int j=0; j<col; j++){
			printf("tab[%d][%d]= ",i,j);
			scanf("%d",*(tab+i)+j);
		}
	}
}		
			
		
int** alloutb(int ligne,int col,int** tb){
	tb=(int**)malloc(ligne* sizeof(int*));
	for(int i=0; i<col; i++){
		*(tb +i)=(int*)malloc(col* sizeof(int));
	}
	return tb;
}	

void getTB(int ligne,int col ,int** tb){
	for(int i=0; i<ligne; i++){
		for(int j=0; j<col; j++){
			printf("tb[%d][%d]= ",i,j);
			scanf("%d",*(tb+i)+j);
		}
	}
	
}	


int** allouT(int ligne,int col,int** T){
	T=(int**)malloc(ligne* sizeof(int*));
	for(int i=0; i<col; i++){
		*(T +i)=(int*)malloc(col* sizeof(int));
	}
	return T;
}
int** AddMat(int ligne,int col,int** tab, int** tb, int** T){
	int i=0,j=0;
	for( i=0; i<ligne; i++){
		for(j=0; j<col; j++){
			T[i][j]=tab[i][j]+tb[i][j];
		
		printf("T[%d][%d]= %d \t",i,j,*(*(T+i)+j));
	   }
	}
	printf("\n");
	return T;
}			
void Affichage(int ligne,int col,int** tab,int** tb ,int** T){
	printf("Voici le resultat du calcul matriciel\n");
	for(int i=0; i<ligne; i++){
		for(int j=0; j<col; j++){
			printf(" %d\t",*(*(tab+i)+j));
			
		}
		printf("\n");
	}
	
	printf("\n+\n");
	
	for(int i=0; i<ligne; i++){
		for(int j=0; j<col; j++){
			printf(" %d\t",*(*(tb+i)+j));
			
		}
		printf("\n");
	}

	printf(" \n =");
	
	for(int i=0; i<ligne; i++){
		for(int j=0; j<col; j++){
			printf(" %d\t",*(*(T+i)+j));
			
		}
		printf("\n");
	}
}	
	


