#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int* ConvertToTab(int nbre);
int isanJavatra(int nbre);
char* caractere(int nbre);
int ascii(char car);
int CharTOInt (int nbre);
int CharToNb(int ligne,int nbre);
int main (){
int nbre=543;	
	isanJavatra(nbre);
	 ConvertToTab(nbre);
	
}
int* ConvertToTab(int nbre){
	int ind=isanJavatra( nbre);	
	
	printf("\n%d",ind); //printf
	int* tab=(int*)malloc(ind*sizeof(int));
	int fin=0;
	fin=CharToNb(0,nbre);  ///
	
	return tab;
	
}
int isanJavatra(int nbre){
	char* ind=malloc(60);
	int nbr=0;
	
	sprintf(ind,"%d",nbre);
	nbr=strlen(ind);
	return nbr; ///nombre de chiffre
}		
 char* caractere(int nbre){
	char* car=malloc(60);
	sprintf(car,"%d",nbre);
	return car;

}
int ascii(char car){
	return (car-'0');
}
int CharToNb(int ligne,int nbre){               ///utile pour convertir les caracteres en entiers
	int be=0;
	int puiss=-1;
	char* tab=malloc(30);
	
	tab=caractere(nbre);
	for(int i=strlen(tab); i>=0; i--) {
		puiss+=1;
		
		be+=ascii(tab[ligne])* pow(10,puiss);
		
	}
	return be;
}
