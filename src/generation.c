#include "generation.h"

/*c'est toujours des matrice carrees, on peut virer le champ nb_row et nb_columns
et les remplacer par taille.On peut ausi paralleliser les allocation/remplissage,mem pas
besoin de mutex.
*/
Matrix newMatrix(int taille){
	int i;

	Matrix m=NULL;
	m=malloc(sizeof(str_matrix));
	m->mat= malloc((taille*sizeof(int*)));
			
	for (i=0;i<taille;i++)
		m->mat[i]=calloc(sizeof(int),taille);

	m->taille=taille;

	return m;
}

Matrix remplirComplet(Matrix m){
	int i,j;
	int taille=m->taille;
	int** mat=m->mat;		//On economise une accession par tour de boucle;

	for(i=0;i<taille;i++){
		for(j=i;j<taille;j++){
			mat[i][j]=rand()%30+1;
			mat[j][i]=mat[i][j];
		}
	}

return m;
}

Matrix remplirPartiel(Matrix m){
	
	int i,j;
	int arete=0;
	int degreSortant;
	int taille=m->taille;
	int** mat=m->mat;		//On economise une accession par tour de boucle;
	
	for(i=0;i<taille;i++){
		for(j=i;j<taille;j++){
			if(rand()%2){
				mat[i][j]=rand()%30+1; //graphe non oriente
				mat[j][i]=mat[i][j];
				degreSortant+=1;
			}
		}

		if(degreSortant==0){
			while((arete=rand()%j)!=i){}    //la diagonale ne nous interresse pas
			
			mat[i][arete]=rand()%30;
			mat[arete][i]=mat[i][arete];
		}
		degreSortant=0;

	}

return m;	
}

void deleteMatrix(Matrix m){
	int i;

	int taille=m->taille;
	int** mat=m->mat;

	for(i=0;i<taille;i++){
		free(mat[i]);
	}

	free(m);
}	

Matrix graphePartiel(int taille){
	Matrix m=newMatrix(taille);
	remplirPartiel(m);
	
	return m;
}

Matrix grapheComplet(int taille){
	Matrix m=newMatrix(taille);
	remplirComplet(m);
	
	return m;
}

void affichage(Matrix m){
	int i,j;	
	int taille=m->taille;

	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			printf(" %d",m->mat[i][j]);
		}
		printf("\n");
	}	
}

