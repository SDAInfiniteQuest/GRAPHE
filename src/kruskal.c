#include"kruskal.h"


listeArete matrixToArete(Matrix m){
	int taille=m->taille;
	int k=0;

	arete* areteTrie=malloc(taille*taille*sizeof(str_arete));
	int** mat=m->mat;
	for(i=0;i<taille;i++){
		for(j=i;j<taille;j++){
			if(mat[i][j]!=0){
				areteTrie[k]->depart=i;
				areteTrie[k]->arrivee=j;
				areteTrie[k]->poids=mat[i][j];
				k++;
			}
		}
		quicksort(areteTrie,0,k+1);
		ListeArete a=malloc(sizeof(str_listeArete));
		a->liste=areteTrie;
		a->taille=k+1;
	}
}

teteListe* vertexToListe(Matrix m){
	int taille=m->taille;
	teteListe* listeEnsemble=malloc(taille*sizeof(str_teteListe));

	int** mat=m->mat;

	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			if(mat[i][j]!=0 && i!=j){
				insertSort(listeEnsemble[i]->debutS);
			}
		}
	}
return listeEnsemble
}

Matrix kruskal(Matrix m){
	teteListe* listeEnsemble=vertexToListe(m);
	arete* areteTrie=matrixToArete(m);
	Matrix ARPM=newMatrix(taille);
	
	int poidsTotal;
	int i=0;
	int nbSommet=m->taille;
	int areteAjouter=0;
	bool premierTour=true;
	arete areteCourante;

	while(areteAjouter!=nbSommet-1){
		areteCourante=areteTrie[i];
		if(!egauxListeSommet(listeEnsemble[areteCourante->depart],listeEnsemble[areteCourante->arrivee])){
			ARPM->mat[areteCourante->depart][areteCourante->arrivee]=areteCourante->poids;
			poidsTotal+=areteCourante->poids;
			teteListe newEnsemble=UnionListeSommet(listeEnsemble[areteCourante->depart],listeEnsemble[areteCourante->arrivee]);
			
			free(listeEnsemble[areteCourante->depart]);
			if(premierTour){
				free(listeEnsemble[areteCourante->arrivee]);
			}

			listeEnsemble[areteCourante->depart]=newEnsemble;
			listeEnsemble[areteCourante->arrivee]=newEnsemble;

			areteAjouter++;
		}
		i++;
	}
	printf("%d",poidsTotal);
	return ARPM;
}
