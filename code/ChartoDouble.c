#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char* separerVirgule(int pos ,char* chiffre, char* avant, char* apres);
int puissance(int nbre, int puiss);
//char charTonumber1(char avant);
char charTonumber2(char apres);
float  caractereToNum(int pos,char* chiffre, char* avant, char* apres,float nbre);
int main(){
	int pos=0;
	char avant[20]={0};
	char apres[50]={0};
	char chiffre[20]="12.30";
	float nbre=0;
	 
	separerVirgule(pos , chiffre,  avant,  apres);
	nbre=caractereToNum( pos, chiffre,  avant,  apres,nbre);
	printf("le nombre est %g\n",nbre);

	return 0;
}	


char* separerVirgule(int pos ,char* chiffre, char* avant, char* apres){
	for(int i=0; i<strlen(chiffre); i++){
		if(chiffre[i]=='.')
		pos=i;
	}
	printf("indice où se trouvant le virgule ind= %d\n",pos);
	
	for(int i=0; i<pos; i++){
		avant[i]=chiffre[i];
		printf("avantVirgule[%d]= %c\n",i,avant[i]);
		
	}	
	
	for(int i=pos+1; i<strlen(chiffre); i++){
		apres[i]=chiffre[i];
		printf("apresVirgule[%d]= %c\n",i,apres[i]);
		
	}			
	
	return 0;
}	
int puissance(int nbre, int puiss){
	double coef=1;
	if(puiss==0){
		return 1;
	}
	else{	
		for(int i=0;i<puiss; i++){
		coef*=nbre;
		}
	}		
		return nbre;
}
/*char charTonumber1(char avant){
	return (avant -'0');
}*/	
char charTonumber2(char apres){
	return (apres -'0');
}	

float caractereToNum(int pos,char* chiffre, char* avant, char* apres,float nbre){

	int dim=strlen(chiffre);
	int nbre1=0, nbre2;
	for(int i=0; i<dim; i++){
		if(chiffre[i]=='.')
		pos=i;
	}
	int x=-1;
	for(int i=pos-1; i>=0; i--){
		x+=1;
			nbre1+=charTonumber2(avant[i])* puissance(10,x);	
	}
	//printf("Le nombre avant virgule est =%d\n",nbre1);
			
	printf("\n");
	x=-1;
	for(int i=dim-1; i>pos; i--){
		x+=1;
		nbre2+=charTonumber2(apres[i])*puissance(10,x);
		//printf("%d+=%d\n",nbre2,charTonumber2(apres[i])*puissance(10,x));
	}
	///le nombre apres virgule qui va etre traduit en heure ,minute et seconde
	nbre =(float)(nbre1)+(float)(nbre2*pow(10,-pos));
	//printf("%.3f",nbre);
	return nbre;
}


				
