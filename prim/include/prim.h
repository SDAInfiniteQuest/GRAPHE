#ifndef __prim_h_
#define __prim_h_

#include "listeAretes.h"
#include "graphe.h"
#include "sous_ensemble.h"

S sommetSuiv(listeAretes l,foret f);
listeAretes majl(listeAretes l,ens e,graphe g,S x);
foret prim(graphe g,S x);

#endif
