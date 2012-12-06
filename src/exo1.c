#include"generation.h"
#include<time.h>


int main(){
	srand(time(NULL));
	
	Matrix m=grapheComplet(5);
	affichage(m);
	deleteMatrix(m);
	Matrix s=graphePartiel(5);
	affichage(s);
	deleteMatrix(s);
	
return 0;	
}
