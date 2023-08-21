#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int* ConvertToTab(int nbre);
int isanJavatra(int nbre);
void AfficherInteger(int nbre);
int main (){
	int nbre=543;	
	
	AfficherInteger(nbre);
	return 0;
	
}
void AfficherInteger(int nbre){
	int ind=isanJavatra( nbre);	
	int* tab=(int*)malloc(ind*sizeof(int));
	tab=ConvertToTab(nbre);
	for(int i=0; i<ind; i++)
		printf("tab[%d]=%d\n",i,*(tab+i));
}
int* ConvertToTab(int nbre){
	int ind=isanJavatra( nbre);	
	int* tab=(int*)malloc(ind*sizeof(int));
	int n=0;
	for(int i=ind-1; i>=0; i--){
		n=nbre/10;
		tab[i]=nbre%10;
		nbre=n;
	}	
	return tab;
}
int isanJavatra(int nbre){
	char* ind=malloc(60);
	int nbr=0;
	sprintf(ind,"%d",nbre);
	nbr=strlen(ind);   //compter le nombre du chiffre
	return nbr;
}		
 
