#include<stdio.h>
int solution(int* statue);
 


int main (){
	int statue[4]={2,3,6,8};
	 solution( statue);
	
	
	return 0;
}	


int solution(int* statue) {
    int min=0,max=0;
    for(int i=0,j=i+1;i<4 && j<4;i++,j++){
        if(statue[i]>statue[j]){
            int tmp;
            tmp=statue[j];
            statue[j]=statue[i];
            statue[i]=tmp;
        }    
    }
    min=statue[0];
    printf("min=%d\n",min);
    for(int i=0,j=i+1;i<4 && j<4;i++,j++){
        if(statue[i]>statue[j]){
            int tmp;
            tmp=statue[j];
            statue[j]=statue[i];
            statue[i]=tmp;
        }    
    }
    max=statue[3];
    printf("max=%d\n",max);
    int j=0,k=0;
    for( j=0,k=0;j<4;j++){
        if((statue[j]>min && statue[j]<=max)){
            k++;
        }
    
    }  
    printf("l y a %d manquant ",k);
    return k;  

}
