#include"matrix.h"
#include"table.h"
#include"quicksort.h"

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

Matrix remplirComplet(Matrix m,bool oriente){
	int i,j;
	int taille=m->taille;
	int** mat=m->mat;		//On economise une accession par tour de boucle;

	if(oriente==false){
		for(i=0;i<taille;i++){
			for(j=i;j<taille;j++){
				mat[i][j]=rand()%taille+1;
				mat[j][i]=mat[i][j];
			}
		}
	}else if(oriente==true){
		for(i=0;i<taille;i++){
			for(j=0;j<taille;j++){
				mat[i][j]=rand()%taille+1;
			}
		}	
	}

return m;
}

Matrix remplirPartiel(Matrix m,bool oriente){
	
	int i,j;
	int taille=m->taille;
	int** mat=m->mat;		//On economise une accession par tour de boucle;
	
	tableSommet Vide=newTable(taille);
	
	insertFin(Vide,rand()%taille);
if(oriente==false){
	while(Vide->nbElements!=taille){
		for(i=0;i<taille;i++){
			for(j=i;j<taille;j++){
				if(i!=j){
					if(rand()%2){
						mat[i][j]=rand()%taille+1; //graphe non oriente
						mat[j][i]=mat[i][j];

						if(estDans(Vide,i)){
							if(!estDans(Vide,j)){
								insertFin(Vide,i);
							}
						}else if(estDans(Vide,j)){
							if(!estDans(Vide,i)){
								insertFin(Vide,j);
							}
						}

						if(Vide->nbElements==taille){
							deleteTable(Vide);
							return m;
						}
					}
				}
			}
		}
	}
}
else if(oriente==true){
	while(Vide->nbElements!=taille){
		for(i=0;i<taille;i++){
			for(j=0;j<taille;j++){
				if(i!=j){
					if(rand()%2){
						mat[i][j]=rand()%taille+1; //graphe oriente

						if(estDans(Vide,i)){
							if(!estDans(Vide,j)){
								insertFin(Vide,i);
							}
						}else if(estDans(Vide,j)){
							if(!estDans(Vide,i)){
								insertFin(Vide,j);
							}
						}

						if(Vide->nbElements==taille){
							deleteTable(Vide);
							return m;
						}
					}
				}
			}
		}
	}
}
	deleteTable(Vide);

	return m;

}

void deleteMatrix(Matrix m){
	int i;

	int taille=m->taille;
	int** mat=m->mat;

	for(i=0;i<taille;i++){
		free(mat[i]);
	}
	
	free(m->mat);
	free(m);
}	

Matrix graphePartiel(int taille,bool oriente){
	Matrix m=newMatrix(taille);
	remplirPartiel(m,oriente);
	
	return m;
}

Matrix grapheComplet(int taille,bool oriente){
	Matrix m=newMatrix(taille);
	remplirComplet(m,oriente);
	
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

