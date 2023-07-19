#include <stdio.h>
#include <string.h>
#define MAX 60

typedef struct{
    char *v[MAX];
    int topo;
}Pilha;

Pilha *criapilha(){
    Pilha *novo = (Pilha*)malloc(sizeof(Pilha));
    novo -> topo = -1;
    return novo;
}

void pushp(Pilha *p, char *time){
    p -> topo++;

    int x = strlen(time);
    char* tim = malloc(x);
    strcpy(tim, time);

    p -> v[p -> topo] = tim;
}

char *popp(Pilha *p){
    p -> topo--;
    return p -> v[p -> topo + 1];
}

int pilhavazia(Pilha *p){
    if(p -> topo == -1){
        return 0;
    }
    return 1;
}
