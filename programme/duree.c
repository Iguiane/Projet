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
    char duration[257];
    int av=0,ap=0;
    int time=0;
    scanf("%s", duration);
    sscanf(duration,"%d:%d",&av,&ap);
    time=(av*60)+ap;
    
    // Write an answer using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("%d",time);

    return 0;
}
