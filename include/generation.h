#include<stdio.h>
#include<stdlib.h>

#ifndef __GENERATION_H
#define __GENERATION_H

typedef struct matrix {
	int **mat;
	int taille; 
}str_matrix,*Matrix;

Matrix newMatrix(int taille);
Matrix grapheComplet(int taille);
Matrix graphePartiel(int taille);
Matrix remplirComplet(Matrix m);
Matrix remplirPartiel(Matrix m);
void deleteMatrix(Matrix m);
void affichage(Matrix m);
#endif
