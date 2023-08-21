#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    char S[51];
    int i=0,j=0;
    int* count={0};
    int m=1;
    scanf("%[^\n]", S);
    count=(int*)malloc(10*sizeof(int));
    for( i=0;i<strlen(S);i++){
        for(j=i+1;j<strlen(S);j++){
            if(S[i]==S[j]){
                count[i]++;
                S[j]= ' ';
                
              
            }
        }
       

    }
    
    
    for(int i=0;i<strlen(S);i++){
		if(count[i]!=0 && S[i]!=' ' ){
				printf("Le caractere %c se repete %d\n",S[i],count[i]+1);
				m*=(count[i]+1);
			
		}
	}		
			
    
   printf("Farany %d\n",m);
    return 0;
}
///multiplier le compteur de caractère
