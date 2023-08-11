#include <stdio.h> 
#include <stdlib.h> 
 int main(){
 int x=31,i=0;
 int k=0;
    int* tab=(int*)malloc(50*sizeof(int));
    scanf("%d", &x);
    while(x!=0){
        tab[i]=x%2;
         if(tab[i]==1){
            k++;
        }
        x/=2;
        i++;
        
    }
    
    printf("%d",k);    
   return 0;
}
///ompter le nombre de 1 D' une binaire
