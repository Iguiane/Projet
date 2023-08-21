#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main (){
	char mpd[20];
	strcat(mpd,getpass("Entrée le mot de passe: "));
	printf("%s",mpd);
	
	
	
	return 0;
}	
	
