#include <stdio.h>
#include <stdlib.h>
int  entrernombre();
int EntrerNombre();
void entrevalTab(int** tab,int ligne,int col);
void affiche(int** tab,int ligne,int col);
int** allouer2D(int ligne,int col);

int main (){
	int col=0;
	int ligne=0;
	int **tab=NULL;
	ligne=entrernombre();
	col=EntrerNombre();
	tab=allouer2D(ligne,col);
	entrevalTab(tab,ligne,col);
	affiche(tab,ligne,col);
	
	return 0;
}	
int entrernombre(){
	int ligne=0;
	printf("Entrer nbr ligne: ");
	scanf("%d",&ligne);
	return ligne;
}	
int EntrerNombre(){
	int col=0;
	printf("Entrer nbr col: ");
	scanf("%d",&col);
	return col;
}	
int** allouer2D(int ligne,int col){
	int** tab;
	tab=(int**)malloc(ligne* sizeof(int*));
	for(int i=0;i<col;i++){
		*(tab+i)=(int*)malloc(col*sizeof(int));
	}	
	return tab;
}
void entrevalTab(int** tab,int ligne,int col){
	for(int i=0;i<ligne; i++){
	  for(int j=0; j<col; j++){
		  
		printf("tab[%d][%d]=   ",i,j);
		scanf("%d",*(tab+i)+j);
		}
	}
}	

void affiche(int** tab,int ligne,int col){
	for(int i=0;i<ligne; i++){
		for(int j=0; j<col; j++){
			printf("tab[%d][%d]=%d   ",i,j,*(*(tab+i)+j));
		}
	}
}			
