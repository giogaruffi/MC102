/* Nome: Giovani Garuffi Rondel
 * RA: 155559
 * Lab 04b - Semanada */
 
 #include <stdio.h>
 
 int main () {
    /* Declaracao de variaveis */
    int D, R, X[100], Y[99], k, i, y = 0, maior, posicao, tamanho, s = 0;
    
    /* Entrada da quantidade de digitos e do numero de digitos que devem ser retirados */  
    scanf("%d %d", &D, &R);
    /* Calculo do tamanho da saida */
    tamanho = D - R;
    
    /* Entrada do valor do numero X */
    for ( i = 0; i < D; i++ ) {
        scanf("%d", &X[i]);
    }
    
    /* Retirada dos maiores valores */
    for ( k = 0; tamanho; k++){
        for ( i = y, maior = -1, posicao = 1; i < D; i++ ){
        /* Verificacao do valor do numero atual em comparacao com os outros, assim como se sua posicao na sequencia permite que ele seja retirado e sobrem numeros para completar a saida */
            if ( maior < X[i] && tamanho <= D - i) {
                maior = X[i];
                posicao = 0;
                y = i;
            }
        }
        /* Se o numero atual eh o maior, seu valor eh retirado do vetor inicial, e o tamanho que falta para completar a saida eh reduzido em 1 */
        if (!posicao) {
            tamanho--;
            X[y] = 0;
        }
        /* O maior numero eh quem entra na sequencia de saida */
        Y[s++] = maior; 
    }
    
    printf("Maior valor: ");
    
    /* Impressao da sequencia de saida */
    for ( i = 0; i < D - R; i++ ){
        printf("%d", Y[i]);  
    }
        
    printf("\n");  
    
    return 0;
 }
