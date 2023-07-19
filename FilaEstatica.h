#ifndef FilaEstatica
#define FilaEstatica
#include "FilaEstatica.c"

fila *criafila();

void pushf(fila *f, char *time);

char *popf(fila *f);

int filavazia(fila *f);

#endif
