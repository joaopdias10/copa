#include <stdio.h>
#include <string.h>

typedef struct{
    char *time;
    struct nodof *prox;
}nodof;

typedef struct{
    int tam;
    nodof *inicio;
    nodof *fim;
}fila;

fila *criafila(){
    fila *f = (fila*)malloc(sizeof(fila));
    f -> inicio = NULL;
    f -> fim = NULL;
    f -> tam = 0;
    return f;
}

void pushf(fila *f, char *time){
    nodof *novo = (nodof*)malloc(sizeof(nodof));

    int x = strlen(time);
    char* tim = malloc(x);
    strcpy(tim, time);

    novo -> time = tim;
    novo -> prox = NULL;

    if(f -> fim != NULL){
        f -> fim -> prox = novo;
    }
    f -> fim = novo;
    if(f -> inicio == NULL){
        f -> inicio = novo;
    }
    f -> tam++;
}

char *popf(fila *f){
    char *time = f -> inicio -> time;
    nodof *aux = f -> inicio -> prox;
    free(f -> inicio);
    f -> inicio = aux;
    if(f -> inicio == NULL){
        f -> fim = NULL;
    }
    f -> tam--;
    return time;
}

int filavazia(fila *f){
    if(f -> inicio == NULL)
    {
        return 0;
    }
    return 1;
}
