#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "FilaDinamica.h"
//#include "PilhaDinamica.h"
#include "FilaEstatica.h"
#include "PilhaEstatica.h"

void espacos(char *confrontos, int x){
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

void espacamento(char *time, int x){
    int y = strlen(time);
    x = 2*x;
    for(;y < x;y++){
        printf(" ");
    }
}

int main(){
    int potes = 0, linhas = 0, resto = 0, dois = 0, espaco = 0, lugar = 3;
    int n = 0, x = 0, y = 0, i = 0, k = 0, j = 0, m = 0, w = 0, z = 0;
    char aux1[30] = {0};
    char aux2[30] = {0};
    char times[50][30] = {0};
    char inverter[50][30] = {0};
    char partidas[25][63] = {0};

    scanf("%d %d", &n, &potes);

    for(;i < n;i++){
        scanf("%s", &times[i]);
        if(strlen(times[i]) > espaco){
            espaco = strlen(times[i]);
        }
    }

    fila *confrontos = criafila();
    fila *classificados = criafila();
    Pilha *eliminados = criapilha();

    if(n > (potes + 1) && potes > 2){//Aqui define como sera o sorteio

        linhas = n / potes;
        if(n % potes != 0){
            resto = n % potes;
        }

        for(;linhas > 1;linhas = linhas - 2){//Escolhi trabalhar com linhas, já que o padrão do sorteio sempre envolve 2 linhas

            sprintf(partidas[i], "%s x %s", times[k], times[k + 1]);
            sprintf(inverter[m + 1], "%s", times[k]);
            sprintf(inverter[m], "%s", times[k + 1]);

            for(j = 2 + k;j < (k + potes + 1);j++){//Aqui é um for pra juntar os times do pote em questão com o proximo timdo proximo pote
                i++;
                m = m + 2;
                sprintf(partidas[i], "%s x %s", times[j + potes - 1], times[j]);
                sprintf(inverter[m + 1], "%s", times[j + potes - 1]);
                sprintf(inverter[m], "%s", times[j]);
            }
            k = k + 2 * potes;//Essa parte é importante pra "subir" duas linhas caso tenha mais linhas, como em 16 times e 4 potes
        }



        if(linhas == 1){//Aqui se trata do resto, caso sobre 1 linhas completa
            if((resto + potes) != potes && resto > 1){//Esse if é pra separar casos como 12 times e 4 potes, onde sobra uma linha completa
                if(k != 0){//Feito para verificar se teve lihas anteriores
                    i++;
                    j = 0;
                    m = m + 2;
                }

                resto = n - (resto + potes);
                sprintf(partidas[i], "%s x %s", times[resto], times[resto + 1]);
                sprintf(inverter[m + 1], "%s", times[resto]);
                sprintf(inverter[m], "%s", times[resto + 1]);

                for(j = 2 + k;j < (k + potes - 1);){
                    if(n > j + potes - 1){//Esse if foi feito pra separar casos onde sobra 1 linha e 2 ou mais resto, caso seja algo como 12 times e 10 potes
                        m = m + 2;
                        sprintf(partidas[i], "%s x %s", times[j + potes - 1], times[j]);
                        sprintf(inverter[2*i + 1], "%s", times[j + potes - 1]);
                        sprintf(inverter[2*i], "%s", times[j]);
                        i++;
                        j++;
                    }

                    else{
                        m = m + 2;
                        sprintf(partidas[i], "%s x %s", times[j], times[j + 1]);
                        sprintf(inverter[m + 1], "%s", times[j]);
                        sprintf(inverter[m], "%s", times[j + 1]);
                        i++;
                        j = j + 2;
                    }
                }
                m = m + 2;
                sprintf(partidas[i], "%s x %s", times[potes + k - 1], times[potes + k]);
                sprintf(inverter[m + 1], "%s", times[potes + k - 1]);
                sprintf(inverter[m], "%s", times[potes + k]);
            }

            else{//Caso sobre 1 linha completa e/ou 1 elemento em uma linha incompleta
                resto = n - (resto + potes);
                for(;resto < n;resto = resto + 2){
                        i++;
                        m = m + 2;
                        sprintf(partidas[i], "%s x %s", times[resto], times[resto + 1]);
                        sprintf(inverter[m + 1], "%s", times[resto]);
                        sprintf(inverter[m], "%s", times[resto + 1]);;
                    }
            }
        }
        if(linhas == 0 && resto != 0){//Caso sobre 1 linha imcompleta com um numero par de elementos
            resto = n - resto;
            for(;resto < n; resto = resto + 2){
                i++;
                m = m + 2;
                sprintf(partidas[i], "%s x %s", times[resto], times[resto + 1]);
                sprintf(inverter[m + 1], "%s", times[resto]);
                sprintf(inverter[m], "%s", times[resto + 1]);
            }
        }
    }

    else{
        k = n - 1;
        for(;k >= 0;k = k - 2){
            sprintf(partidas[i], "%s x %s", times[k - 1], times[k]);
            sprintf(inverter[m + 1], "%s", times[k - 1]);
            sprintf(inverter[m], "%s", times[k]);
            i++;
            m = m + 2;
            }
        i--;
        }

    for(;i >= 0;i--){//Coloca as partidas no fila confrontos
        pushf(confrontos, partidas[i]);
    }

    for(i = (n - 1);i >= 0;i--){//Coloca os times na fila classificados
        pushf(classificados, inverter[i]);
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

        for(dois = 0; dois < 2; dois++){

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
    printf("\n Campeao: %s", popp(eliminados));
    printf("\n    Vice: %s\n", popp(eliminados));
    for(n = n - 2;n > 0;n--){
        printf("%do lugar: %s\n", lugar, popp(eliminados));
        lugar++;
    }

    //free(all);
}

