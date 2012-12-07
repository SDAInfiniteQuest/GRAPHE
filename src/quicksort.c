#include"quicksort.h"



void echanger(arete* tab,int i,int j){
	arete tmp=tab[i];
	tab[i]=tab[j];
	tab[j]=tmp;
}

void quicksort(arete* tab,int debut,int fin){
	
	if(debut>=fin)
		return;
	else{
		int pivot=tab[debut]->poids;
		int gauche=debut+1,droite=fin;

		while(gauche<droite){
			if(tab[gauche]->poids<=pivot)
				gauche++;
			else
				echanger(tab,gauche,fin-1);
			}
		echanger(tab,gauche-1,debut);
		quicksort(tab,debut,gauche-1);
		quicksort(tab,droite-1,fin);
	}
}

