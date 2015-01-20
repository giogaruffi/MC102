/* Nome: Giovani Garuffi Rondel
 * RA: 155559
 * Lab 06a - Fruit Crush Saga - Part I */
 
 #include <stdio.h>
 
 int main () {
    /* Declaracao de variaveis */
    int M, N, I, J, i, j, pontuacao = 1;
    char tabuleiro[50][51];
    
    /* Entrada dos numeros de linhas e colunas totais e da jogada */
    scanf("%d %d %d %d", &M, &N, &I, &J);
    
    /* Entrada dos valores do tabuleiro */ 
    for ( j = 0; j < M; j++ ){
        scanf("%s", tabuleiro[j]);
    }   
    
    /* Ajuste das variaveis I e J para o local correto na matriz */
    I -= 1;
    J -= 1;
    
    /* Checagem de repeticoes da fruta escolhida por baixo */
    i = I + 1;
    while (tabuleiro[i][J] == tabuleiro[I][J] && i < M){
        pontuacao++;
        tabuleiro[i][J] = 'X';
        i++;
    }
        
    /* Checagem de repeticoes da fruta escolhida por cima */        
    i = I - 1;
    while (tabuleiro[i][J] == tabuleiro[I][J] && i >= 0){
        pontuacao++;
        tabuleiro[i][J] = 'X';
        i--;
    }
        
    /* Checagem de repeticoes da fruta escolhida pela direita */    
    j = J + 1; 
    while (tabuleiro[I][j] == tabuleiro[I][J] && j < N){
        pontuacao++;
        tabuleiro[I][j] = 'X';
        j++;    
    }
        
    /* Checagem de repeticoes da fruta escolhida pela esquerda */    
    j = J - 1;
    while (tabuleiro[I][j] == tabuleiro[I][J] && j >= 0){
        pontuacao++;
        tabuleiro[I][j] = 'X';
        j--;   
    }
    /* Alteracao da fruta escolhida para 'X' */
    tabuleiro[I][J] = 'X';
    
    /* Calculo e impressao da pontuacao obtida */
    printf("Score: %d\n", pontuacao*pontuacao);
    
    /* Impressao do tabuleiro resultante */
    for ( j = 0; j < M; j++ ){
        printf("%s\n", tabuleiro[j]);
    }            
        
    return 0;
 }
