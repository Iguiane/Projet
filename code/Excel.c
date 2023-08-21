#include <stdio.h>
#include <stdlib.h>
int main (){
	FILE *fic=fopen("POINT.csv","w+");
	float debut=2.0,fin=27.0;
	float y=0,i=0;
	float ecart=0.0;
	float n=0.0;
	
	y=2*(i*i)+i-4;
	printf("Entrez la division de votre intervale:");scanf("%f",&n);
	
	ecart=(fin-debut)/n;
	for(i=debut ;i<fin;i+=ecart){
		y=(2*i*i)+i-4;
		fprintf(fic,"%f \t %f\n",i,y);
	}	
	fclose(fic);

	return 0;
}
