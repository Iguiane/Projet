#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int charTonombre(char car);
long puiss(long nbr1,int nbr2);
int main (){
	char car[]="342721";
	char vir[]= ".";
	//printf("%d\n",vir[0]);
	
	/*printf("%d\n",charTonombre('0'));
	printf("%ld\n",puiss(10,3));
	*/
	
	
	long nbr=0;
	int str=strlen(car);
	for(int i=str-1;i>=0;i--)
		nbr+=charTonombre(car[i])*puiss(10,str-1-i);
	    printf("%ld",nbr);
	    
	return 0;
}
int charTonombre(char car){
	return (car-'0');
}

long puiss(long nbr1,int nbr2){
	long nbr=1;
	for(int i=1;i<=nbr2;i++)
		nbr*=nbr1;
	return nbr;
}
