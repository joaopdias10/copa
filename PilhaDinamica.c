#include <stdio.h>
#include <string.h>
#define MAX 50

typedef struct{
    char *time;
    struct nodop *prox;
}nodop;

typedef struct{
     nodop *topo;
}Pilha;

Pilha *criapilha(){
    Pilha *nova = (Pilha*)malloc(sizeof(Pilha));
    nova -> topo = NULL;
    return nova;
}

int pilhavazia(Pilha *p){
    if(p -> topo == NULL){
        return 0;
    }
    return 1;
}

nodop *insere(Pilha *p, char *time){
    nodop *novo = (nodop*)malloc(sizeof(nodop));
    novo -> time = time;
    novo -> prox = p;
    return novo;
}

void pushp(Pilha *p, char *time){
    nodop *novo = (nodop*)malloc(sizeof(nodop));

    int x = strlen(time);
    char* tim = malloc(x);
    strcpy(tim, time);

    novo -> time = tim;
    novo -> prox = p -> topo;
    p -> topo = novo;
    //p -> topo = insere(p, x)
}

char *popp(Pilha *p){
    int aux = p -> topo -> prox;
    char *time = p -> topo -> time;
    free(p -> topo);
    p -> topo = aux;
    return time;
}
