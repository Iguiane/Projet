#include <stdio.h>
#include <stdlib.h>
int  EntrezLigne();
int  EntrezColonne();
int** Allocation(int ligne,int colonne);
int** EntrezValeur(int ligne, int colonne);
int** alouerDet(int l ,int c);
int** Remplissage(int l ,int c);
int Determinant(int l, int c);
int main (){
	int ligne=0,colonne=0;
	
	ligne=EntrezLigne();
	colonne=EntrezColonne();
	//Remplissage(ligne , colonne);
	 Determinant( ligne,  colonne);
	
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
int** alouerDet(int l ,int c){
	int ligne=0,colonne=0;
	ligne=l;
	colonne=c+2;
	int** mat=Allocation( ligne, colonne);
	return mat;
}
int** Remplissage(int l ,int c){
	int colonne=0;
	int** tab=Allocation( l, c);
	colonne=c+2;
	int** mat=Allocation( l, colonne);
	tab=EntrezValeur( l, c);
	for(int i=0; i<l; i++){
		for(int j=0; j<colonne ;j++){
			mat[i][j]=tab[i][j%3];
		}
	}
	
	return mat;		
			
	
}
/*int det2( int ** matrice){
	//int** matrice=Allocation(2,2);
	int det=0;
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			det=(matrice[i][j]*matrice[i+1][j+1])- (matrice[i+1][j]*matrice[i][j+1]);
		}
	}
	return det;		
		
}
*/
int Determinant(int l, int c){
	int colonne=0;
	int somme=0;
	colonne=c+2;
	int** mat=Allocation( l, colonne);
	mat=Remplissage(l , c);
	int deter=0;

	printf("eto\n");
	
	///affichage
		for(int i=0; i<3; i++){
				for(int j=0; j<5; j++){
					printf("%d\t",mat[i][j]);
				}
				printf("\n");
		}		
	///fin affichage
	
	/*
		int n=1;
		for(int i=0; i<3;i++){
			for(int j=0; j<5; j++){
				n*=mat[i][j];	
			}
		}
		
		int k=1;
		for(int i=0; i<3;i++){
			for(int j=1; j<5; j++){
					k*=mat[i][j];
			}
		}			
		
		int m=1;
		for(int i=0; i<3;i++){
			for(int j=2; j<5; j++){
					m*=mat[i][j];
			}
		}
		printf("s=%d",n+m+k);
		*/
		
		///akambana ho iray
		int s=0, n=1;
	
	
		
			/*for(int i=0; i<3;i++){
				for(int j=0; j<3;j++){
					while(j<5){
						
						n*=mat[i][j];	
						j++;
						printf("%d ici n\n",n);
					}
					s+=n;printf("%d ici s\n",s);
				}	
				
			}*/
			int k=0,i=3;	
			while(k<3 && i<=5){
				int l=0,c=k;
				while(l<3 && c<i){
					n*=mat[l][c];
					l++;c++;	
				}
				s+=n;;
				n=1;
				k++;
				i++;
			}
			
		printf("s=%d\n",s);	
		
		int v=1,S=0;
		 int j=0,m=2;
		 while(j<3 && m<=5){
			 int l=0,c=m;
			 while(l<3 && c>=j){
				 	v*=mat[l][c];
					l++;c--;	
			}
			S+=v;
				v=1;
				j++;
				m++;
			}
			printf("S=%d\n",S);
	deter=s-S;
	printf("%d",deter);
				 
//mbola tsy mety diagonale ray ihany no azony
/*
		int m=1;
		 int v=0;
		for(int i=2; i>=0; i--){
			for(int  j=0; j<5; j++){
				while(i>=0 && j<5){
			    m*=mat[i][j];
				i--;
				j++;
				printf("\nm=%d",m);
				v+=m;
			}	
			}		
		}
	printf("v= %d",v);
*/
	
	return somme;		
	
}
