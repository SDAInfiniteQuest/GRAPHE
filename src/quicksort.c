#include"quicksort.h"



void echanger(arete* tab,int i,int j){
	int ptmp=tab[i].poids;
	int dtmp=tab[i].depart;
	int atmp=tab[i].arrivee;

	tab[i].poids=tab[j].poids;
	tab[i].depart=tab[j].depart;
	tab[i].arrivee=tab[j].arrivee;

	tab[j].poids=ptmp;
	tab[j].depart=dtmp;
	tab[j].arrivee=atmp;
}

void echangerSommet(int* tab,int i,int j){
	int tmp=tab[i];
	tab[i]=tab[j];
	tab[j]=tmp;
}

void quicksort(arete* tab,int debut,int fin){
	int i;

	if(debut<fin){
		int pivot=tab[fin].poids;
		int elementAechanger=debut;

		for(i=debut;i<fin;i++){
			if(tab[i].poids<pivot){
				echanger(tab,i,elementAechanger);
				elementAechanger++;
			}
		}
		echanger(tab,elementAechanger,fin);
		quicksort(tab,debut,elementAechanger-1);
		quicksort(tab,elementAechanger+1,fin);
	}
}

void quicksortSommet(int* tab,int debut,int fin){
	int i;

	if(debut<fin){
		int pivot=tab[fin];
		int elementAechanger=debut;

		for(i=debut;i<fin;i++){
			if(tab[i]<pivot){
				echangerSommet(tab,i,elementAechanger);
				elementAechanger++;
			}
		}
		echangerSommet(tab,elementAechanger,fin);
		quicksortSommet(tab,debut,elementAechanger-1);
		quicksortSommet(tab,elementAechanger+1,fin);
	}
}

