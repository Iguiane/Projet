#include <stdio.h>
int main (){
	char A[20]="AB";
	char R;
	R=2*A[1]-A[0];
	if(R>'Z'){
	R-=26;
	}
	printf("R=%c",R);

	return 0;
}
//sujet coding game TEst 
