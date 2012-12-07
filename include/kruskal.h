#ifndef _KRUSKAL_H
#define _KRUSKAL_H
#include"quicksort.h"
#include"generation.h"
#include"liste.h"


arete* matrixToArete(Matrix m);
teteListe* vertexToListe(Matrix m); 
Matrix kruskal(Matrix m);

#endif
