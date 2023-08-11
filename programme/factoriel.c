#include <stdio.h>
int factoriel(int n);
int main (){
	int n=0;
	int fact=0;
	printf("Entrez un nombre: ");
	scanf("%d",&n);

	fact=factoriel(n);
	printf("la factorielle de %d est %d\n",n,fact); 
	return 0;
}	
int factoriel(int n){
	if(n==2)
	return 2;
	
	return n*factoriel(n-1);
}	

/*int m=0:
	printf("Entrez un nombre: ");
	scanf("%d",&n);
	if(n>2){
		m=n*(n-1);
		n=m;
	}
	printf("la factorielle de %d \n",m); 
*/	
