#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "FilaDinamica.h"
//#include "PilhaDinamica.h"
#include "FilaEstatica.h"
#include "PilhaEstatica.h"

int verifica(int comeco, int potes){//Verifica se a variavel comeco chegou na ultima posição possivel(potes -1) e se chegou voltta pra posição 0
    if(comeco == potes){
        return 0;
    }
    if(comeco != potes){
        return comeco;
    }
}

void espacos(char *confrontos, int x){//Cria os espaços pras partidas
    int i = 0;
    char time[63] = {0};
    sprintf(time, "%s", confrontos);
    for(;time[i] != ' ';i++){
    }
    x = (2*x) - i;
    for(;x > 0;x--){
        printf(" ");
    }
}

void espacamento(char *time, int x){//Cria os espaços pros times
    int y = strlen(time);
    x = 2*x;
    for(;y < x;y++){
        printf(" ");
    }
}

int main(){
    int potes = 0, repetir = 0, espaco = 0, lugar = 3, comeco = 0, parada = 0;
    int n = 0, i = 0, x = 0, y = 0, w = 0, z = 0;
    char aux1[30] = {0};
    char aux2[30] = {0};
    char times[50][30] = {0};
    char partidas[25][63] = {0};

    scanf("%d %d", &n, &potes);

    Pilha *p[potes];
    for(;i < potes;i++){//Cria os potes(pilhas)
        p[i] = criapilha();
    }

    for(i = 0;i < n;i++){
        scanf("%s", &times[i]);
        z = i % potes;
        pushp(p[z], times[i]);
        if(strlen(times[i]) > espaco){//Guarda o tamanho da maior string
            espaco = strlen(times[i]);
        }
    }


    fila *confrontos = criafila();
    fila *classificados = criafila();
    Pilha *eliminados = criapilha();

    for(i = 0;parada < n/2;parada++){//Ciclo pra definir as partidas

        comeco = verifica(comeco, potes);
        x = pilhavazia(p[comeco]);
        for(;x == 0;comeco++){//Verifica se a pilha esta vazia e se esta avança pra proxima
            comeco = verifica(comeco, potes);
            x = pilhavazia(p[comeco]);

        }
        sprintf(aux1, "%s", popp(p[comeco]));
        comeco++;

        comeco = verifica(comeco, potes);
        for(;x == 0;comeco++){//Verifica se a pilha esta vazia e se esta avança pra proxima
            comeco = verifica(comeco, potes);
            x = pilhavazia(p[comeco]);

        }
        sprintf(aux2, "%s", popp(p[comeco]));
        sprintf(partidas[i], "%s x %s", aux1, aux2);
        pushf(confrontos, partidas[i]);
        pushf(classificados, aux1);//Coloca os times na
        pushf(classificados, aux2);//fila classificados
        i++;
        comeco++;
    }

    printf("\nFila inicial:\n");

    for(i = n/2;i > 0;i--){//Printa os confrontos
        sprintf(aux1, "%s", popf(confrontos));
        espacos(aux1, espaco);
        printf("%s \n", aux1);
    }

    printf("\n");
    for(i = 1;i < n/2;i++){//Imprime os dias até a final
        printf("Dia %d:\n", i);

        for(repetir = 0; repetir < 2; repetir++){

            sprintf(aux1, "%s", popf(classificados));
            sprintf(aux2, "%s", popf(classificados));

            srand(time(NULL)+w);
            w++;
            while(x == y){
                x = rand() % 8;
                y = rand() % 8;
            }

            espacamento(aux1, espaco);
            printf("%s %d x %s %d\n", aux1, x, aux2, y);

            if(x > y){
                pushf(classificados, aux1);
                pushp(eliminados, aux2);
            }

            if(y > x){
                pushf(classificados, aux2);
                pushp(eliminados, aux1);
            }
            x = 0;
            y = 0;
        }

        printf("\n");
    }

    //imprime a final
    printf("Grande final:\n");
    sprintf(aux1, "%s", popf(classificados));
    sprintf(aux2, "%s", popf(classificados));

    srand(time(NULL)+w);
    w++;
    while(x == y){
        x = rand() % 8;
        y = rand() % 8;
    }

    espacamento(aux1, espaco);
    printf("%s %d x %s %d\n", aux1, x, aux2, y);

    if(x > y){
        pushp(eliminados, aux2);
        pushp(eliminados, aux1);
    }

    if(y > x){
        pushp(eliminados, aux1);
        pushp(eliminados, aux2);
    }

    //Imprime as colocações
    printf("\n  Campeao: %s", popp(eliminados));
    printf("\n     Vice: %s\n", popp(eliminados));
    for(n = n - 2;n > 0;n--){
        if(lugar < 10){
            printf(" ");
        }
        printf("%do lugar: %s\n", lugar, popp(eliminados));
        lugar++;
    }

    //Liberando memoria
    for(i = 0;i< potes;i++){
        free(p[i]);
    }
    free(confrontos);
    free(classificados);
    free(eliminados);
    return 0;
}
