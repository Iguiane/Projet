#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main (){
///Affichage de RAND_MAX et time	
	srand(time(NULL));
	printf("\n RAND_MAX= %d \ttime = %ld\n",RAND_MAX,time(NULL));
///generer 10  nombres pseudo -aléatoire <RAND_MAX	
	for(int i=0;i<10; i++)
	printf("%d \t", rand());
	
///	Pour generer des nombre entre 1 et 100
	printf("\n Nombre entre 1 et 1OO\n");
	for(int i=0;i<10; i++)
	printf("%f\t",(float)rand() /RAND_MAX);	
    //printf("%d \t",(100*rand() /RAND_MAX));
	
	
	
///generer des nombres entre 1 et 100 :cf .Numerical Recipes
	printf("\n Nombre entre 1 et 1OO\n");
	for(int i=0;i<10; i++)
	printf("%d \t",1+ (int)(100.0*rand() /(RAND_MAX +1.0)));	

	return 0;
	
}
