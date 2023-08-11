#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
char* solution(char * inputString);
int main(){
	char inputString[10]="dda";
	//char* sol=malloc(7);
	solution(inputString);
	
	 
	return 0;
}	
char* solution(char* inputString){
    char* a=malloc(10);

            for(int i=0;i<strlen(inputString);i++){
                if(inputString[i]==inputString[strlen(inputString)-1-i]){
                        strcpy(a,"true");  
                        
                }
                else{
                       strcpy(a,"false");
                }
            }
           printf("%s",a);
     
    return 0;
}
