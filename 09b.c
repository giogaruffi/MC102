/* Nome: Giovani Garuffi Rondel
* RA: 155559
* Lab 09b - Concurso Publico para Professor da UNICAMP */

 #include <stdio.h>
 /* Definir numero maximo de concorrentes */
 #define MAX 30
 
 /* Funcao responsavel pelo retorno do indice da maior nota */
 int indiceMaior(double notas[5][MAX], int K, int i) {
    int l, max = 0;
    
    /* Compara as notas ao longo da matriz */
    for ( l = 0; l < K; l++ ){
        if (notas[i][max] < notas[i][l])
            max = l;
    }
    /* Zerar o maior valor para nao ser considerado mais que uma vez */
    notas[i][max] = 0.0;
    /* Retorna o indice da maior nota recebida */     
    return max;
 }
 /* Funcao responsavel pelo retorno da posicao que recebeu mais votos */
 int ordenaCandidatos(int escolhas[2][MAX], int K, double media[MAX]) {
    int l, max = 0;
    
    /* Compara o numero de votos de cada posicao */
    for ( l = 0; l < K; l++ ){
        if (escolhas[1][max] < escolhas[1][l]){
            max = l;
        /* Primeiro criterio de desempate - Maior media*/
        } else if (escolhas[1][max] == escolhas[1][l]){
            if ( media[max] < media[l] ){
                max = l;
            /* Segundo criterio de desempate - Ordem de inscricao */
            } else if ( media[max] == media[l] ) {
                if ( l < max ){
                    max = l;
                }
            }
        }  
    }
    /* Zerar o maior valor para nao ser considerado mais que uma vez */
    escolhas[1][max] = 0;
    /* Retorna a posicao a ser considerada na classificacao */
    return max;
 } 
 /* Funcao responsavel pela ordenacao da classificacao final */
 void classificacao(int escolhas[2][MAX], int ordem[5][MAX], int K, int n, double media[MAX]){
    int i, j, k, aux;
        /* Zerar a segunda linha da matriz escolhas */
        for ( j = 0; j < K; j++ )
            escolhas[1][j] = 0;
        /* Contar escolhas de cada Membro */
        for ( i = 0; i < 5; i++ )
            escolhas[1][ordem[i][0] - 1]++; 
        /* Alocar na primeira linha da matriz a classificacao final */
        escolhas[0][n] = ordenaCandidatos(escolhas, K, media) + 1;
        /* Atualizacao da lista de preferencia */
        for ( i = 0; i < 5; i++ ){
            for ( j = 0; j < K; j++ ){
                if ( ordem[i][j] == escolhas[0][n] ){
                    for ( k = j; k < K - 1; k++ ){
                        aux = ordem[i][k];
                        ordem[i][k] = ordem[i][k + 1];
                        ordem[i][k + 1] = aux;
                    }
                }
            }
        }
 }
 int main () {
    /* Declaracao de variaveis */
    int K, i, j, n, ordem[5][MAX], escolhas[2][MAX];
    double notas[5][MAX], media[MAX];
    
    /* Entrada do numero de canditados */
    scanf("%d", &K);
    
    /* Entrada do valor das notas de cada candidato */
    for ( i = 0; i < 5; i++ )
        for ( j = 0; j < K; j++ )
            scanf("%lf", &notas[i][j]);
    
    /* Calculo da nota media de cada candidato */        
    for ( j = 0; j < K; j++ ){
        media[j] = (notas[0][j] + notas[1][j] + notas[2][j] + notas[3][j]+ notas[4][j])/5;
    }
    
    /* Impressao das medias calculadas de cada candidato */
    printf("Nota Media:");
    for ( j = 0; j < K; j++ ){
        printf(" %.1f", media[j]);
    }
    printf("\n\n");   
    
    /* Alocacao da ordem de preferencia de cada Membro da banca */
    for ( i = 0; i < 5; i++ ){
        for ( j = 0; j < K; j++ ){
            ordem[i][j] = indiceMaior(notas, K, i) + 1;
        }
    }
    
    /* Impressao das preferencias de cada Membro da banca */  
    printf("Preferencia:\n");
    for ( i = 0; i < 5; i++ ){
        printf("Membro %d:", i + 1);
        for ( j = 0; j < K; j++ ){
            printf(" %d", ordem[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    /* Determinacao da classificacao final */
    for ( n = 0; n < K; n++ ){
        classificacao(escolhas, ordem, K, n, media);    
    }
    /* Alocacao do ultimo colocado */
    escolhas[0][n] = ordem[0][0];
    
    /* Impressao da classificacao final */
    printf("Classificacao:");         
    for ( j = 0; j < K; j++ ){
        printf(" %d", escolhas[0][j]);
    }
    printf("\n");
        
    return 0;
 }
