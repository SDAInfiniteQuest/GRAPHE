#ifndef __aretes_h_
#define __aretes_h_

#include "base.h"

typedef struct 
{
	S s;
	S d;
	Nat l;
} strArete, *arete;

arete creerArete(S s,S d,Nat l);
Bool egArete(arete a1,arete a2);
void supArete(arete a);

#endif
