#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int charToint(char date);
char** alloue2DChar(int taille);
int* position_Slash(char* date);
char** SeparerSlash(char* date);
char** separerVirgule(int ligne, char** slash);
float charToDouble(int ligne, char** slash);
int CharTOInt (int ligne,char** slash);
float Secondaire(char** slash);
char* ConversionDate(char** slash);

int main (){
	char date[20]="12.5/05.4/2023";
	char** slash=alloue2DChar(3);

	slash=SeparerSlash(date);

	separerVirgule(0, slash);
	
	printf("\nnkns");
	charToDouble(0, slash);
	
	 CharTOInt (2, slash);
	 
	 Secondaire(slash);
	 ConversionDate(slash);
	return 0;
}	

int charToint(char date){
	return ( date-'0');
}	
char** alloue2DChar(int taille){
	char** tab;
	tab=(char**)malloc((taille)*sizeof(char*));
	for(int i=0;i<(taille); i++){
		tab[i]=malloc(10);
	}
	return tab;
}
int* position_Slash(char* date){
	int* pos=(int*)malloc(2*sizeof(int));
	for(int i=0,k=0; i<strlen(date);i++){
		if(date[i]=='/'){
		pos[k]=i;
		k++;
		}	
	}
	return pos;
}		
char** SeparerSlash(char* date){
	char** slash=NULL;
	slash=alloue2DChar(3);
	int* pos=position_Slash(date);
	
	for(int i=0; i<pos[0];i++){
			slash[0][i]=date[i];
	}
	
	
	for(int j=pos[0]+1,i=0; j<pos[1];i++,j++){
			slash[1][i]=date[j];	
	}
		
	for(int j=pos[1]+1 ,i=0; j<strlen(date); i++,j++){
			slash[2][i]=date[j];
	}		
	

	return slash;	
	
}			
int trouverVIrgule(int ligne,char** slash){
	int vir=0;
	for(int i=0; i<strlen(slash[ligne]); i++){
		if(slash[ligne][i]=='.' || slash[ligne][i]==',')
		vir=i;
	}
	return vir;
}		
char** separerVirgule(int ligne, char** slash){
	int vir=trouverVIrgule(ligne, slash);
	char** Virgule=alloue2DChar(2);
	for(int i=0;i<vir; i++){
		Virgule[0][i]=slash[ligne][i];
	}
	for(int i=vir+1,j=0;i<strlen(slash[ligne]);j++, i++){
		Virgule[1][j]=slash[ligne][i];
	}
	return Virgule;
}
float charToDouble(int ligne, char** slash){
	int x=-1;
	int tp=0,tmp=0;
	float nbre=0.0;
	char** virgule=alloue2DChar(2);
		virgule=separerVirgule(ligne,slash);
	int vir=0;
		vir=trouverVIrgule(ligne, slash);
		
	for(int i=strlen(virgule[0])-1; i>=0; i--){
		x++;
		tp+=charToint(virgule[0][i])*pow(10,x);
	}

	for(int i=strlen(virgule[1])-1; i>=0; i--){
		x++;
		tmp+=charToint(virgule[1][i])*pow(10,x);
	}	
	nbre=tp+(tmp*pow(10,-vir-1));


	return nbre;
}	

int CharTOInt (int ligne,char** slash){
	int nbre=0;
	int x=-1;
	for(int i=strlen(slash[ligne])-1; i>=0;i--){
		x++;
		nbre+=charToint(slash[ligne][i])*pow(10,x);
	}
//	printf("nbre=%d",nbre);//printf
	return nbre;
}	
float Secondaire(char** slash){
	float seconde=0;
	float jour=0,mois=0;
	//int annee=0;
	jour=charToDouble(0,slash)*(24*60*60);
	mois=charToDouble(1,slash)*(31*24*60*60);
	//annee=CharTOInt (2,slash);
	
	///si mois n' a pas de virgule
	/*jour=charToDouble(0,slash)*(24*60*60);
	mois=charToInt(1,slash)*(31*24*60*60);
	annee=CharTOInt (2,slash);
	*/
	
	seconde=jour+mois;
	return seconde;
}
char* ConversionDate(char** slash){
	char* heu=malloc(20);
	float sec=Secondaire( slash);
	int seconde=0,minute=0,heure=0,jour=0,mois=0,annee=0;
	annee=CharTOInt (2,slash);
	int min=0,h=0,j=0;
	
	min=(int)sec/60;
	seconde=(int)sec%60;
	
	h=min/60;
	minute=min%60;
	
	j=h/24;
	jour=h%24;
	
	mois=j/31;
	jour=j%31;
	
	annee=CharTOInt (2,slash);
	sprintf(heu," %d/%d/%d  %d:%d:%d\n",jour,mois,annee,heure,minute,seconde);;
	printf("%s",heu);
	return heu;
	
}
//mety2 ratsy
