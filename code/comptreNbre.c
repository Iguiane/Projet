#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int N;
    scanf("%d", &N); fgetc(stdin);
    for (int i = 0; i < N; i++) {
        char ROW[257];
        scanf("%[^\n]", ROW); fgetc(stdin);

    int x=0;
        for(int i=0;i<strlen(ROW);i++){
            if(isdigit(ROW[i]))
                    x+=1;
        }      
            
         printf("%d\n",x);    
        
    } 
   

    return 0;
}
