/* Nome: Giovani Garuffi Rondel
 * RA: 155559
 * Lab 05a - Caça ao Tesouro */
 
 #include <stdio.h>
 
 int main () {
    /* Declaracao de variaveis */
    int N, i, repeticao[100], atual = 0, posicao = 1, dica[100];
    
    /* Entrada do tamanho da trilha */
    scanf("%d", &N);
    
    /* Entrada dos valores de cada posicao na trilha */
    for ( i = 0; i < N; i++ )
        scanf("%d", &dica[i]);
    /* Zerar vetor contador de repeticoes */
    for ( i = 0; i < N; i++ )
        repeticao[i] = 0;
    
    /* Caminhar pela trilha */
    while ( dica[posicao - 1] != posicao && repeticao[atual] != 2 ) {
        posicao = dica[atual];
        atual = posicao - 1;
        repeticao[atual]++;        
    }
    /* Se em algum momento o valor da posicao eh igual a posicao, o tesouro foi encontrado na posicao */
    if ( dica[posicao - 1] == posicao ) {
        printf("Tesouro existe em %d\n", posicao);
    }
    /* Se a repeticao somou 2, entao a trilha entrou em loop e nao ha tesouro */
    if (repeticao[atual] == 2) {
        printf("Nao existe tesouro\n");
    }
    
    return 0;
 }        
