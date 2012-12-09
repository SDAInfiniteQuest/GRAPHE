#ifndef __ensemble_h_
#define	__ensemble_h_

#include "base.h"

typedef struct 
{
	Nat taille;
	Bool *e;
} *ens,strEns;

ens vide();
ens plein();
ens ins(ens,S);
ens	del(ens,S);
Bool estDans(S, ens);
Bool estVide(ens);
Nat card(ens);
ens uni(ens,ens);
ens inter(ens,ens);
ens supe(ens);

#endif
