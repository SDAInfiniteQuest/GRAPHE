#ifndef __LISTE_H
#define __LISTE_H

typedef bool int;

#define false 0
#define true 1

typedef struct {
	int depart;
	int arrivee;
	int poids;
}str_arete,*arete;

typedef struct ListeSommet{
	struct* Liste suivant;	
	int sommet;
}str_ListeSommet,*ListeSommet;

typedef struct ListeArete{
	struct* ListeArete suivant;	
	arete a;
}str_ListeArete,*ListeArete;

typedef struct{
	int taille;
	ListeArete debutA;
	ListeSommet debutS;
}str_teteListe,*teteListe;


teteListe newListe();
teteListe insertSortArete(teteListe l,int depart,int arrivee,int poids);
teteListe insertSortSommet(teteListe l,int sommet);
arete depilerListeArete(teteListe l);
teteListe unionListeSommet(teteListe l1,teteListe l2);
bool egauxListeSommet(teteListe l1,teteListe l2);
void deleteListe(teteListe l);
#endif
