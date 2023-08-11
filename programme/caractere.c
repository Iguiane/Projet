#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (){
	int n=0;
	char* nom=malloc(50);
	printf("entrez un n:");scanf("%d",&n);
	int k=0;
	while(n<k){
		
	 for(int j=0;j<50; j++)
			scanf("%c",(nom+j));
	k++;
					
	}
	
 /*nom=(char**)malloc(n*sizeof(char*));
	for(int i=0; i<n;i++){
		nom[i]=(char*)malloc(50*sizeof(char));
	}	 
	
	for(int j=0;j<n; j++)
			scanf("%s",nom[j]);	
				
	for(int j=0;j<n; j++){
		//for(int i=j+1;i<n; i++){
			if(strlen(nom[j])>strlen(nom[j+1])){
				
				char* tmp;
				tmp=nom[j+1];
				nom[j+1]=nom[j];
				nom[j]=tmp;
			  printf("\t%s\n",nom[j]);
			}
		//}
	}			
*/
	return 0;

}
//mbola tsy mety
