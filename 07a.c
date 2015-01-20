/* Nome: Giovani Garuffi Rondel
 * RA: 155559
 * Lab 07a - The Voice - Blind Auditions */
 
 #include <stdio.h>
 #define MAX_PARTIC 100 
 #define TIMES 4
 
 int main () {
    /* Declaracao de variaveis */
    int escolhas[MAX_PARTIC][TIMES], part, i = 0, encontrado, j, preferencias[MAX_PARTIC][TIMES], times[MAX_PARTIC][TIMES];
    
    /* Leitura do numero de participantes */
    scanf("%d", &part);  
    
    /* Zerar a matriz que mostra os integrantes de cada time */
    for ( i = 0; i < part; i++ ){
        for ( j = 0; j < TIMES; j++ ){
            times[i][j] = 0;
        }
    }
    
    i = 0;
    
    /* Leitura das escolhas dos juizes e da preferencia dos participantes em matrizes separadas */    
    while ( i < part ) {
        for ( j = 0; j < TIMES; j++ ) {
            scanf("%d", &escolhas[i][j]);
        }
        for ( j = 0; j < TIMES; j++ ) {
            scanf("%d", &preferencias[i][j]);
        }
        i++;
    }
   
    /* Alocacao dos participantes aos seus correspondentes times  */
    for ( i = 0; i < part; i++ ){
        for ( j = 0, encontrado = 0; j < TIMES && !encontrado; j++ ){
            if ( escolhas[i][preferencias[i][j] - 1] ){
                encontrado = 1;
                times[i][preferencias[i][j] - 1] = 1;
            }
        }        
    }
    
    /* Impressao dos times definitivos */
    for ( j = 0; j < TIMES; j++ ){
        printf("Time %d:", j + 1);
        for ( i = 0, encontrado = 0; i < part; i++ ){
            if ( times[i][j] ){
                printf(" %d", i + 1);
                encontrado = 1;
            }
        }
        if ( !encontrado ){
            printf(" Nenhum participante");
        }
        printf("\n");
    }
     
    return 0;
 }
