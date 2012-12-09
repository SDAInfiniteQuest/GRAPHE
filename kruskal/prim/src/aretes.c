#include "aretes.h"
#include <stdio.h>
#include <stdlib.h>

arete creerArete(S s,S d,Nat l)
{
	arete a;
	a=(arete) malloc(sizeof(strArete));
	a->s=s;
	a->d=d;
	a->l=l;
	return a;
}

Bool egArete(arete a1, arete a2)
{
	if((a1->s==a2->s)&&(a1->d==a2->d)) return 1;
	else return 0;
}

void supArete(arete a)
{
	free(a);
}
