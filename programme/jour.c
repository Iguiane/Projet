#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char** alloue2DChar(int taille);
void getDate(int jour, int mois,int annee);
void Reglage(char** Slash);
int* IndiceSlash(char* car);
char** SeparerSlash(char* car);
int charToint(char date);
int nbre(int j,char** Slash);
int main (){
	
	char* date=malloc(10);
	
	printf("Entrer la date d'aujourd' hui sous format jour/mois/annee:");
	scanf("%s",date);
	
	char** Slash=alloue2DChar(3);
	Slash=SeparerSlash(date);
	Reglage(Slash);
	return 0;
}
void Reglage(char** Slash){
	int jour=0,mois=0,ans=0;
	jour= nbre(0,Slash);
	mois= nbre(1,Slash);
	ans= nbre(2,Slash);
		
	
	jour+=1;
	
		if(mois==2){
			if(ans%4==0  && ((ans%100)!=0 || ans%400==0)){
				if(jour >29){
					jour=1;
					mois+=1;
				}
			}
			else{
				if(jour>28){	
					jour=1;
					mois+=1;
				}
			}		 
		}
		else if (mois==1 || mois==3 ||	mois==5 || mois==7 || mois==8 || mois==10|| mois==12 ){
			if(jour>31){
				jour=1;
				mois+=1;
			}	
		}
		else{
			if(jour>30){
				jour=1;
				mois+=1;
			}	
		}
		if(mois>12){
			mois=1;
			ans+=1;
		}	
		
	printf("La date de demain %02d/%02d/%02d",jour,mois,ans);
}		
char** alloue2DChar(int taille){
	char** tab;
	tab=(char**)malloc((taille)*sizeof(char*));
	for(int i=0;i<(taille+1); i++){
		tab[i]=malloc(10);
	}
	return tab;
}		 	
int* IndiceSlash(char* car){
	int* indice=malloc(2*sizeof(int));
	int j=0;
	for(int i=0; i<strlen(car); i++){
		if(car[i] == '/'){	
			indice[j]=i;
			j++;
		}	
	}
	
	return indice;
}
char** SeparerSlash(char* car){
	int* indice=(int*)malloc(2*sizeof(int));
	indice=IndiceSlash(car);
	char** tab=NULL;
	tab=alloue2DChar(2);
	for(int i=0; i<indice[0];i++){
			tab[0][i]=car[i];
	}	
	
	for(int j=indice[0]+1,i=0; j<indice[1];i++,j++){
			tab[1][i]=car[j];
	}
		
	for(int j=indice[1]+1 ,i=0; j<strlen(car); i++,j++){
			tab[2][i]=car[j];
	}		
	return tab;	
	
}				
int charToint(char date){
	return ( date-'0');
}
int nbre(int j,char** Slash){
	int nbre=0;
	int puiss=-1;
	for(int i=strlen(Slash[j])-1; i>=0; i--){
		puiss++;
		nbre+=(charToint(Slash[j][i])*pow(10,puiss)); 
	}	
	return nbre;
}	
