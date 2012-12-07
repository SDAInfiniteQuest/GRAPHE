#include"liste.h"


teteListe newListe{
	teteListe l=malloc(sizeof(str_teteListe));
	//l->debutA=NULL;
	l->debutS=NULL;
	l->finS=NULL;
	l->taille=0;	
	return l;
}

/*
teteListe insertSortArete(teteListe l,int depart,int arrivee,int poids){
	arete a=malloc(sizeof(str_arete));	
	a->depart=depart;
	a->arrivee=arrivee;
	a->poids=poids;

	ListeArete la=malloc(sizeof(str_ListeArete));
	la->a=a;
	la->suivant=NULL;

	if(l->debutA==NULL)
		l->debutA=la;
	else{
		ListeArete courante=l->debutA;
		if(courante->poids>poids){
			a->suivant=courante;
			l->debutA=a;
			l->taille++;
			return l;
		}
		else{
			ListeArete precedent;
			while(courante->suivant!=NULL){
				if(courante->suivant->poids>poids){
					a->suivant=courante->suivant;
					courante->suivant=a;
					l->taille++;
					return l;
				}
				precedent=courante;
				courante=courante->suivante;
			}
			if(courante->poids>poids){
				precedent->suivant=a;
				a->suivant=courante;
				l->taille++;
				return l;
			}
			else{
				courante->suivant=a;
				a->suivant=NULL;
				l->taille++;
				return l;
			}
		}
	} 
}
*/

teteListe insertSortSommet(teteListe l,int sommet){

	ListeSommet ls=malloc(sizeof(str_ListeSommet));
	ls->sommet=sommet;
	ls->suivant=NULL;

	if(l->debutS==NULL)
		l->debutS=ls;
		l->finS=ls;
	else{
		ListeSommet courante=l->debutS;
		if(courante->sommet>sommet){
			ls->suivant=courante;
			l->debutS=ls;
			l->taille++;
			return l;
		}
		else{
			ListeSommet precedent;
			while(courante->suivant!=NULL){
				if(courante->suivant->sommet>sommet){
					ls->suivant=courante->suivant;
					courante->suivant=ls;
					l->taille++;
					return l;
				}
				precedent=courante;
				courante=courante->suivante;
			}
			if(courante->sommet>sommet){
				precedent->suivant=ls;
				ls->suivant=courante;
				l->taille++;
				return l;
			}
			else{
				courante->suivant=ls;
				ls->suivant=NULL;
				l->finS=ls;
				l->taille++;
				return l;
			}
		}
	} 
}


/*
arete depilerListeArete(teteListe l){

	arete a=l->debutA->a;
	l->debutA=l->debutA->suivant;
	return arete;
}

*/
teteListe insertFin(teteListe l,int sommet){
	
	ListeSommet ls=malloc(sizeof(str_ListeSommet));
	ls->sommet=sommet;
	ls->suivant=NULL;

	l->finS->suivant=ls;
	l->finS=ls;
	
	return l;
}

teteListe unionListeSommet(teteListe l1,teteListe l2){

	teteListe sommetUni=newListe();

	ListeSommet liste1=l1->debutS;
	ListeSommet liste2=l2->debutS;

		while(liste1!=NULL||liste2!=NULL){
			if(liste1->sommet>liste2->sommet){
				insertSortSommet(sommetUni,liste2->sommet);
				liste2=liste2->suivant;
			}
			else if(liste1->sommet<liste2->sommet){
				insertSortSommet(sommetUni,liste1->sommet);
				liste1=liste1->suivant;
			}
			else{
				insertSortSommet(sommetUni,liste1->sommet);
				liste1=liste1->suivant;
				liste2=liste2->suivant;
			}
		}

		if(liste1==NULL && liste2==NULL)
			return sommetUni;
		else if(liste1==NULL){
			while(liste2!=NULL){
				insertFin(sommetUni,liste2->sommet);
				liste2=liste2->suivant;
			}
		}
		else{ 
			while(liste2!=NULL){
				insertFin(sommetUni,liste2->sommet);
				liste2=liste2->suivant;
			}
		}
return sommetUni;
}



bool egauxListeSommet(teteListe l1,teteListe l2){
	
	if(l1->taille!=l2->taille)
		return false;
	
	if(l1->debutS->sommet!=l2->debutS->sommet)
		return false;

	if(l1->finS->sommet!=l2->finS->sommet)
		return false;


	ListeSommet liste1=l1->debutS;
	ListeSommet liste2=l2->debutS;
	
	while(liste1!=NULL){
		if(liste1->sommet!=liste2->sommet)
			return false;

		liste1=liste1->suivant;
		liste2=liste2->suivant;
	}
return true;
}



void deleteListe(teteListe l){

	if(l->debutS!=NULL){
		ListeSommet tmp;
		ListeSommet liste=l->debutS;

		while(liste!=NULL){
			tmp=liste->suivant;
			free(liste);
			liste=tmp;
		}
	free(l);
	}
	/*
	else if(l->debutA!=NULL){
		ListeArete tmp;
		ListeArete liste=l->debutA;

		while(liste!=NULL){
			tmp=liste->suivant;
			free(liste->a);
			free(liste);
			liste1=tmp;
		}
		free(l);		
	}
	*/
}
