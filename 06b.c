/* Nome: Giovani Garuffi Rondel
 * RA: 155559
 * Lab 06b - Fruit Crush Saga - Part II */


 
 #include <stdio.h>
 
 int main () {
    /* Declaracao de variaveis */
    int M, N, J, f, x, y, X, Y, i, loop, pontuacao, pont_final = 0;
    char tabuleiro[50][51], jogada;
    
    /* Entrada dos numeros de linhas e colunas totais e da jogada */
    scanf("%d %d %d", &M, &N, &J);
    
    /* Entrada dos valores do tabuleiro */ 
    for ( y = 0; y < M; y++ ){
        scanf("%s", tabuleiro[y]);
    }   
    
    for ( i = 0; i < J; i++ ){ 
    
        /* Zerar pontuacao para a contagem de cada jogada */
        pontuacao = 0;

        /* Entrada da posicao da jogada */
        scanf("%d %d", &X, &Y);
    
        /* Ajuste das variaveis X e Y para o local correto na matriz */
        Y -= 1;
        X -= 1;
   
         /* Ajuste da posicao de inicio de verificacao vertical */
        jogada = tabuleiro[X][Y];
        x = X;
        while (tabuleiro[x][Y] == jogada && x < M){
            x++;
        }
        x--;
        
        /* Checagem de repeticoes da fruta escolhida na mesma coluna */   
        loop = 0;
        while (tabuleiro[x][Y] == jogada && tabuleiro[x][Y] != '.'){
            pontuacao++;
            for ( f = x; f > 0; f-- ){
                tabuleiro[f][Y] = tabuleiro[f - 1][Y];
            }
            tabuleiro[loop][Y] = '.';
            loop++;
        }
       
        /* Checagem de repeticoes da fruta escolhida pela direita */    
        y = Y + 1; 
        while (tabuleiro[X][y] == jogada && y < N && tabuleiro[X][y] != '.'){
            pontuacao++;
            for ( f = X; f > 0; f-- ){
                tabuleiro[f][y] = tabuleiro[f - 1][y];
            }
            tabuleiro[0][y] = '.';
            y++;    
        }
        
        /* Checagem de repeticoes da fruta escolhida pela esquerda */    
        y = Y - 1;
        while (tabuleiro[X][y] == jogada && y >= 0 && tabuleiro[X][y] != '.'){
            pontuacao++;
            for ( f = X; f > 0; f-- ){
                tabuleiro[f][y] = tabuleiro[f - 1][y];
            }
            tabuleiro[0][y] = '.';
            y--;   
        }
                    
        /* Calculo da pontuacao final a cada jogada */
        pont_final += pontuacao*pontuacao;
    
    }
    
    /* Calculo e impressao da pontuacao obtida */
    printf("Score: %d\n", pont_final);
    
    /* Impressao do tabuleiro resultante */
    for ( y = 0; y < M; y++ ){
        printf("%s\n", tabuleiro[y]);
    }            
        
    return 0;
 }
