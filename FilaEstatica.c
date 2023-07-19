#include <stdio.h>
#include <string.h>
#define MAX 60

typedef struct{
    char *v[MAX];
    int inicio, fim;
    int tam;
}fila;

fila *criafila(){
    fila *f = (fila*)malloc(sizeof(fila));
    f -> inicio = f -> fim = 0;
    f -> tam = 0;
    return f;
}

void pushf(fila *f, char *time){

    int x = strlen(time);
    char* tim = malloc(x);
    strcpy(tim, time);

    f -> v[f -> fim] = tim;
    f -> fim = (f -> fim + 1) % MAX;
    f -> tam++;
}

char *popf(fila *f){
    char *time = f -> v[f -> inicio];
    f -> inicio = (f -> inicio + 1) % MAX;
    f -> tam--;
    return time;
}

int filavazia(fila*f){
    if(f -> tam == 0){
        return 1;
    }
    return 0;
}
