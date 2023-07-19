#ifndef PilhaDinamica
#define PilhaDinamica
#include "PilhaDinamica.c"

Pilha *criapilha();

void pushp(Pilha *p, char *time);

char *popp(Pilha *p);

int pilhavazia(Pilha *p);

#endif
