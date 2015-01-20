/* Nome: Giovani Garuffi Rondel
 * RA: 155559
 * Lab 07b - Modern Word Search */
 
 #include <stdio.h>
 
 /* Definir tamanhos maximos das entradas */
 #define TAM_MATRIZ 50
 #define TAM_PALAVRA 26
 
 /* Funcao responsavel por verificar a existencia de caracteres do tipo especial */
 int especiais(char tabela[][TAM_MATRIZ + 1], int linha, int coluna, char lambda[], int posicao){

    /* Se o caracter for '#', considere todas as vogais */
    if ( tabela[linha][coluna] == '#' && (lambda[posicao] == 'a' || lambda[posicao] == 'e' || lambda[posicao] == 'i' || lambda[posicao] == 'o' || lambda[posicao] == 'u') ){
        return 1;
    }
    
    /* Se o caracter for '%', considere todas as consoantes */
    if ( tabela[linha][coluna] == '%' && !(lambda[posicao] == 'a' || lambda[posicao] == 'e' || lambda[posicao] == 'i' || lambda[posicao] == 'o' || lambda[posicao] == 'u') ){
        return 1;
    }
    
    /* Se o caracter for '_', considere todas as letras */
    if ( tabela[linha][coluna] == '_' ){
        return 1;
    }
    
    return 0;
 }
 
 int main () {
    /* Declaracao de variaveis */
    int N, M, i, s, k, j, l, marcador, marcador2, contagem = 0, igual = 0, tamanho = 0;
    char lambda[TAM_PALAVRA], tabela[TAM_MATRIZ][TAM_MATRIZ + 1], resultado[TAM_MATRIZ][TAM_MATRIZ + 1];
    
    /* Entrada dos tamanhos do caca-palavras e da palavra a ser procurada */
    scanf("%d %d %s", &N, &M, lambda);
    
    /* Alteracao dos componentes da tabela de saida para "ponto" */
    for ( k = 0; k < N; k++ ){
        for ( j = 0; j < M; j++ ){
            resultado[k][j] = '.';
        }
    }          
    
    /* Calculo do tamanho da palavra a ser procurada */
    while ( lambda[tamanho] ){
        tamanho++;
    }
    
    /* Entrada do caca-palavras */
    for ( i = 0; i < N; i++ ){
        scanf("%s", tabela[i]);
    }
    
    /* Verificacao de repeticoes da palavra na horizontal */
    for ( j = 0, k = 0, l = 0; k < N; k++ ){
        for ( j = 0; j < M; j++ ){
            marcador = j;
            l = 0;
            contagem = 0;
            while ( especiais(tabela, k, marcador, lambda, l) || (tabela[k][marcador] == lambda[l]) ){
                marcador++;
                l++;
                contagem++;
                if (contagem == tamanho){
                    igual++;
                    for ( s = j; s < j + tamanho; s++ ){
                        resultado[k][s] = tabela[k][s];
                    }
                }
            }
        }
    }
    
    /* Verificacao de repeticoes da palavra na vertical */    
    for ( j = 0, k = 0, l = 0; j < M; j++ ){
        for ( k = 0; k < N; k++ ){
            marcador2 = k;
            l = 0;
            contagem = 0;
            while ( especiais(tabela, marcador2, j, lambda, l) || (tabela[marcador2][j] == lambda[l]) ){
                marcador2++;
                l++;
                contagem++;
                if (contagem == tamanho){
                    igual++;
                    for ( i = k; i < k + tamanho; i++ ){
                        resultado[i][j] = tabela[i][j];
                    }
                }
            }
        }
    }
    
    /* Verificacao de repeticoes da palavra na diagonal */    
    for ( j = 0, k = 0, l = 0; k < N; k++ ){
        for ( j = 0; j < M; j++ ){
            marcador = j;
            marcador2 = k;
            l = 0;
            contagem = 0;
            while ( especiais(tabela, marcador2, marcador, lambda, l) || (tabela[marcador2][marcador] == lambda[l]) ){
                marcador2++;
                marcador++;
                l++;
                contagem++;
                if (contagem == tamanho){
                    igual++;
                    for ( i = k, s = j; i < k + tamanho; i++, s++ ){
                        resultado[i][s] = tabela[i][s];
                    }
                }
            }
        }
    }  
    
    /* Impressao da palavra procurada e do numero de vezes que foi encontrada */
    printf("%s %d\n", lambda, igual);
    
    /* Impressao da tabela resultante, que soh contem as posicoes das palavras encontradas */
    for ( k = 0; k < N; k++ ){
        for ( j = 0; j < M; j++ ){
            printf("%c", resultado[k][j]);
        }
        printf("\n");
    }    
    
    return 0;
 }
