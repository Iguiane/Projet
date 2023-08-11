#include <stdio.h>
int main (){
	int tab[5];
	int i,k;
	int compteur[5]={0};
	for (i=0;i<5;i++){
	printf("tab[%d]= ",i);
	scanf("%d",tab+i);
	}

	for(i=0;i<5;i++){
	  for( k=i+1;k<5;k++){

		if(tab[i]==tab[k]){
		compteur[i]++;
		tab[k]=0;
	        }
	   }
        }
	for(i=0;i<5;i++){
        	if(compteur[i]!=0 && tab[i]!=0){
        	printf("%d  se repete %d fois\n",tab[i]	,compteur[i]+1);
        	}
	}

	
	return 0;
}

