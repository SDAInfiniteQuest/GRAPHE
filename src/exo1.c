#include"matrix.h"
#include<time.h>
#include"table.h"
#include"quicksort.h"
#include"kruskal.h"
#include<unistd.h>
#include<ctype.h>

int main(int argc,char** argv){
	char c;
	bool oriente=false;
	bool complet=true;
	char* tvalue=NULL;
	int taille=15;
	bool BoolAffiche=true;
	bool resultat=true;
	while((c=getopt(argc,argv,"oncpsrt:"))!=-1){
		switch(c)
		{
		case 'o':
			oriente=true;
			break;
		case 'n':
			break;
		case 'c':
			break;
		case 'r':
			resultat=false;
			break;
		case 'p':
			complet=false;
			break;
		case 't':
			tvalue=optarg;
			break;
		case 's':
			BoolAffiche=false;
			break;
		case '?':
			printf("usage: -s desactiver l'affichage  -o:graphe oriente -n: graphe non oriente -c:graphe complet -p:graphe partielle -t:taille a specifier\n");
		 default:
			abort();
		}
	}
	
	if(tvalue!=NULL)
		taille=atoi(tvalue);

	srand(time(NULL));
	Matrix m;

	if(complet==true)	
		m=grapheComplet(taille,oriente);
	else
		m=graphePartiel(taille,oriente);
	
	if(BoolAffiche==true){
		affichage(m);
		printf("\n");
	}

	Matrix ARPM=kruskal(m,oriente,resultat);
	
	if(BoolAffiche==true){
		printf("\n");
		affichage(ARPM);	
		printf("\n");
	}

	deleteMatrix(m);
	deleteMatrix(ARPM);
return 0;	

}
