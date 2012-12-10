#include"kruskal.h"

void deleteTabArete(arete* listeArete){
	free(listeArete);
}

arete* matrixToArete(Matrix m){
	int taille=m->taille;
	int i=0,j=0,k=0;

	arete* areteTrie=malloc((taille*taille)*sizeof(arete));

	int** mat=m->mat;
		for(i=0;i<taille;i++){
			for(j=i+1;j<taille;j++){
				if(mat[i][j]!=0){
					areteTrie[k].depart=i;
					areteTrie[k].arrivee=j;
					areteTrie[k].poids=mat[i][j];
					k++;
				}
			}
		}


	quicksort(areteTrie,0,k-1);


	return areteTrie;
}

tableSommet* vertexToTable(Matrix m){
	int i;
	int taille=m->taille;
	tableSommet* tableEnsemble=malloc(taille*sizeof(str_tableSommet));

	for(i=0;i<taille;i++){
		tableEnsemble[i]=newTable(taille);
	}

	for(i=0;i<taille;i++){
		insertFin(tableEnsemble[i],i);
	}

	return tableEnsemble;
}

Matrix kruskal(Matrix m,bool boolAffiche){
	tableSommet* tableEnsemble=vertexToTable(m);
	arete* areteTrie=matrixToArete(m);
	Matrix ARPM=newMatrix(m->taille);

	int** arbre=ARPM->mat;
	int poidsTotal=0;
	int i=0;
	int nbSommet=m->taille;
	int areteAjouter=0;
	arete areteCourante;

		while(areteAjouter!=nbSommet-1){
			areteCourante=areteTrie[i];
			if(!egauxListeSommet(tableEnsemble[areteCourante.depart],tableEnsemble[areteCourante.arrivee])){
				arbre[areteCourante.depart][areteCourante.arrivee]=areteCourante.poids;
				arbre[areteCourante.arrivee][areteCourante.depart]=areteCourante.poids;
			
				poidsTotal+=areteCourante.poids;
				tableSommet	newEnsemble=unionListeSommet(tableEnsemble[areteCourante.depart],tableEnsemble[areteCourante.arrivee]);
				
				int* sommetdeEnsemble=newEnsemble->tab;
				
				
					deleteTable(tableEnsemble[areteCourante.depart]);
					deleteTable(tableEnsemble[areteCourante.arrivee]);
				for(i=0;i<newEnsemble->nbElements;i++){
					tableEnsemble[sommetdeEnsemble[i]]=newEnsemble;
				}

				areteAjouter++;
			}
			i++;
		}


	deleteTable(tableEnsemble[0]);

	free(tableEnsemble);
	deleteTabArete(areteTrie);

	if(boolAffiche==true)
		printf("%d\n",poidsTotal);

	return ARPM;
}
