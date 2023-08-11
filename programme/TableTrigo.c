#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RAD  (3.14/180)
int main (){
	FILE *table=NULL;
	table=fopen("Trigonometrie.csv","w+");
	fprintf(table," DEGRÉS \t SINUS \t TANGENTES \t COTANGENTES \t COSINUS\n ");
	for(int i=0,k=89;i<46 && k>44;i++){
		float sinus=0,cosinus=0,tangente=0,cotangente=0;
		
		sinus=sin(i*RAD);
		tangente=tan(i*RAD);
		cotangente=1/tangente;
		cosinus=cos(i*RAD);
		fprintf(table,"%d \t %.3f \t %.3f \t %.3f \t %.3f \t %d\n ",i,sinus,tangente,cotangente,cosinus,k);
		k--;
	}	
	fprintf(table,"\t COSINUS \t COTANGENTES \t TANGENTES \t SINUS\t DEGRÉS \n ");
	fclose(table);
	return 0;
}
///EFA VITA
