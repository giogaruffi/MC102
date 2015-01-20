/* Nome: Giovani Garuffi Rondel
* RA: 155559
* Lab 09a - Oliver Queen is alive! */

#include <stdio.h>

/* Definir tamanho maximo do labirinto */
#define MAX 30

int main () {
    /* Declaracao de variaveis */
    int i, j, labirinto[MAX][MAX], D, T, x = 0, y = 0, posicao, tempo = 0, sentido = 4;
    
    /* Entrada do tamanho do labirinto e do tempo maximo */
    scanf("%d %d", &D, &T);
    
    /* Entrada do labirinto */
    for ( i = 0; i < D; i++ ){
        for ( j = 0; j < D; j++ ){
            scanf("%d", &labirinto[i][j]);
        }
    }
    
    /* Inicializacao da posicao como a primeira do labirinto */
    posicao = labirinto[0][0];
    
    /* Caminho trilhado pelo labirinto */
    while ( tempo < T && x < D && y < D){
        /* Alteracao dos valores das posicoes recem pisadas */
        if ( posicao == 0 ){
            labirinto[y][x] = 1;
        } else if ( posicao == 1 ){
            labirinto[y][x] = 2;
            /* Incremento do sentido do movimento (giro no sentido anti-horario) */
            sentido--;
        } else if ( posicao == 2 ){    
            labirinto[y][x] = 0;
            /* Alteracao do sentido de movimento (giro no sentido horario) */
            sentido++;
        } else if ( posicao == 3 ){
            /* Caso pise em uma armadilha */
            printf("Oliver morre\n");
            return 0;
        } else if ( posicao == 4 ){
            /* Caso encontre o dispositivo */
            printf("Oliver destroi o dispositivo em %d segundos\n", tempo);
            return 0;
        }      
        /* Movimentacao de acordo com o sentido atual */            
        if  ( sentido % 4 == 0 || sentido % 4 == 4 ){
            posicao = labirinto[y][++x];
        } else if ( sentido % 4 == 1 || sentido % 4 == -1 ){
            posicao = labirinto[++y][x];               
        } else if ( sentido % 4 == 2 || sentido % 4 == -2 ){
            posicao = labirinto[y][--x];
        } else if ( sentido % 4 == 3 || sentido % 4 == -3 ){
            posicao = labirinto[--y][x];
        }
        /* Incremento do tempo passado apos cada passo */
        tempo++;
    }        
    
    /* Verificacao se houve encontro com as paredes */
    if ( x >= D || y >= D || x < 0 || y < 0){
        printf("Oliver morre\n");
        return 0;
    }
    /* Verificacao se o tempo limite nao foi ultrapassado */
    if ( tempo >= T ){
        printf("Oliver nao chega ao dispositivo a tempo\n");
        return 0;
    }
    return 0;
}
