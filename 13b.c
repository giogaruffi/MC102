/******************************************
 * Nome: Giovani Garuffi Rondel           *
 * RA: 155559                             *
 * Lab 13b - Fruit Crush Saga - Part III  *
 ******************************************/
 
 #include <stdio.h>

 /* Declaracao de prototipos de funcoes a serem utilizadas */
 int pontuacao(char tabuleiro[][51], int M, int N);
 void jogada(char tabuleiro[][51], int lin, int col, char aux, int *pont_jogada, 
    int M, int N);
 void gravidade(char tabuleiro[][51], int M, int N);

 int main () {
    /* Declaracao de variaveis */
    int M, N, J, y, i, pont_final = 0;
    char tabuleiro[50][51];
    
    /* Entrada dos numeros de linhas e colunas totais e da jogada */
    scanf("%d %d %d", &M, &N, &J);
    
    /* Entrada dos valores do tabuleiro */ 
    for ( y = 0; y < M; y++ ){
        scanf("%s", tabuleiro[y]);
    }   
    
    /* Repeticao das jogadas e calculo da pontuacao final */
    for ( i = 0; i < J; i++ ){    
        pont_final += pontuacao(tabuleiro, M, N);
    }
    
    /* Impressao da pontuacao obtida */
    printf("Score: %d\n", pont_final);
    
    /* Impressao do tabuleiro resultante */
    for ( y = 0; y < M; y++ ){
        printf("%s\n", tabuleiro[y]);
    }            
        
    return 0;
 }
 
 /* Funcao para o calculo da pontuacao de uma jogada e para a alteracao do 
  tabuleiro */
 int pontuacao(char tabuleiro[][51], int M, int N ) {
     int lin, col, pont_jogada = 0;
     char aux;
     
     /* Entrada da posicao da jogada */
     scanf("%d %d", &lin, &col);
     
     /* Ajuste das linhas e colunas para o local correto na matriz */
     lin -= 1;
     col -= 1;
     
     /* Alocar em uma variavel auxiliar o valor da fruta escolhida */
     aux = tabuleiro[lin][col];
     
     /* Caso a jogada seja valida, realiza-la */
     if(aux != '*' && aux != '.'){
        pont_jogada = 1;     
        jogada(tabuleiro, lin, col, aux, &pont_jogada, M, N);
        gravidade(tabuleiro, M, N);
     }
     
     /* Retornar valor da pontuacao da jogada */
     return (pont_jogada*pont_jogada);
 } 

 /* Funcao recursiva responsavel por contar os pontos obtidos */
 void jogada(char tabuleiro[][51], int lin, int col, char aux, int 
*pont_jogada, int M, int N){
     
     /* Altera o valor da fruta igual a jogada inicial */
    tabuleiro[lin][col] = ',';
    
    /* Checa repeticao da fruta escolhida pela direita */
    if((tabuleiro[lin][col+1] == aux) && (col+1 < N)){
         *pont_jogada += 1;
         jogada(tabuleiro, lin, col+1, aux, pont_jogada, M, N);
    }
    /* Checa repeticao da fruta escolhida por baixo */
    if((tabuleiro[lin+1][col] == aux) && lin+1 < M){
         *pont_jogada += 1;
         jogada(tabuleiro, lin+1, col, aux, pont_jogada, M, N);
    }
    /* Checa repeticao da fruta escolhida pela esquerda */
    if((tabuleiro[lin][col-1] == aux) && (col-1 >= 0)){
         *pont_jogada += 1;
         jogada(tabuleiro, lin, col-1, aux, pont_jogada, M, N);
    }
     /* Checa repeticao da fruta escolhida por cima */
    if((tabuleiro[lin-1][col] == aux) && (lin-1 >= 0)){
         *pont_jogada += 1;
         jogada(tabuleiro, lin-1, col, aux, pont_jogada, M, N);
    }
 }
 
 /* Funcao responsavel pela atuacao da gravidade ao fim de cada rodada */
 void gravidade(char tabuleiro[][51], int M, int N){
     int i, j, aux;
     
     for(i=0;i<M;i++){
         for(j=0;j<N;j++){
             /* Encontrando a posicao da fruta retirada, atua a gravidade */
             if(tabuleiro[i][j] == ','){
                 /* Condicao de parada caso haja obstaculo fixo */
                 for (aux = i; aux > 0 && tabuleiro[aux][j] != '*'; aux--){
                     tabuleiro[aux][j] = tabuleiro[aux - 1][j];
                 }
                 if (tabuleiro[aux][j] == '*'){
                     tabuleiro[aux+1][j] = '.';
                 }else{
                 tabuleiro[0][j] = '.';
                 }
             }
         }     
     }
 }
