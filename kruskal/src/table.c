#include"table.h"


tableSommet newTable(int taille){
	tableSommet t=malloc(sizeof(str_tableSommet));
	t->tab=malloc(taille*sizeof(int));
	t->nbElements=0;
	t->tailleMax=taille;
	return t;
}

bool estDans(tableSommet t,int sommet){
	int i;
	int taille=t->nbElements;
	int* table=t->tab;

	for(i=0;i<taille;i++){
		if(table[i]==sommet)	
			return true;
		}
		
	return false;
}

tableSommet insertFin(tableSommet t,int sommet){
	
	t->tab[t->nbElements]=sommet;
	t->nbElements++;
	
	return t;
}

tableSommet unionListeSommet(tableSommet t1,tableSommet t2){
	int parcT1=0,parcT2=0;
	int tailleT1=t1->nbElements;
	int tailleT2=t2->nbElements;
	tableSommet sommetUni=newTable(t1->tailleMax);

	int* table1=t1->tab;
	int* table2=t2->tab;

		while((parcT1!=tailleT1)&&(parcT2!=tailleT2)){
			if(table1[parcT1]>table2[parcT2]){
				insertFin(sommetUni,table2[parcT2]);
				parcT2++;
			}
			else if(table1[parcT1]<table2[parcT2]){
				insertFin(sommetUni,table1[parcT1]);
				parcT1++;
			}
			else{
				insertFin(sommetUni,table1[parcT1]);
				parcT1++;
				parcT2++;
			}
		}

		if(parcT1==tailleT1 && parcT2==tailleT2)
			return sommetUni;
		else if(parcT1==tailleT1){
			while(parcT2!=tailleT2){
				insertFin(sommetUni,table2[parcT2]);
				parcT2++;
			}
		}
		else{ 
			while(parcT1!=tailleT1){
				insertFin(sommetUni,table1[parcT1]);
				parcT1++;
			}
		}

return sommetUni;
}



bool egauxListeSommet(tableSommet t1,tableSommet t2){
	
	if(t1->nbElements!=t2->nbElements)
		return false;
	

	if(t1->tab[t1->nbElements-1]!=t2->tab[t2->nbElements-1])
		return false;


	int* table1=t1->tab;
	int* table2=t2->tab;
	int taille=t1->nbElements-1;
	int parcT1=0;
	int parcT2=0;
	
	while(parcT1!=taille){
		if(table1[parcT1]!=table2[parcT2])
			return false;
		
		parcT1++;
		parcT2++;
	}
return true;
}

tableSommet copieTable(tableSommet t){
	
	int taille=t->nbElements;
	int i=0;
	tableSommet copie=newTable(t->tailleMax);
	
	int* aRemplir=copie->tab;
	int* aCopier=t->tab;

	for(i=0;i<taille;i++){
		aRemplir[i]=aCopier[i];
	}
	
	copie->nbElements=taille;
	return copie;
}

void deleteTable(tableSommet t){

	free(t->tab);
	free(t);
}
