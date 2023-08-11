#include<stdio.h>
int main (){
//entree de donnee
	int min=0,max=100;
	int coupsDessai=0;
	int choix;
	printf("Pensez a un nombre entre 0 et 100 et je vais deviner\n,pous repondez juste par oui (1)ou non (0)et si le nombre est correct taper 2\n");
	do{
	printf("Est -ce que le nombre est inferieur a %d :",((min +max)/2));
	scanf("%d",&choix);
  	coupsDessai ++;
       if(choix==1){
	max=(min +max)/2;
//	printf("Le nombre est de %d \n",min);
	}

     else  if(choix==0){
	min=(max +min)/2;
//	printf("Le nombre est de %d \n",max);
	}

	else{
	printf("J' ai ton nombre en %d coups \n",coupsDessai);
	break;
	}
	
	
	}
	while(1);
	
	return 0;
}
