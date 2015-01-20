/********************************
 * Autor: Giovani Garuffi Rondel*
 * RA: 155559                   *
 * Laboratorio 12a: CUT++       *
 ********************************/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOMEARQ 101

void gera_csv_reduzido(char fnamein[], char fnameout[]);

int main(int argc, char *argv[]) {
    char fnamein[MAX_NOMEARQ], fnameout[MAX_NOMEARQ];    
    
    strcpy(fnamein, argv[1]);
    strcpy(fnameout, argv[2]);

    gera_csv_reduzido(fnamein, fnameout);

    return 0;
}

void gera_csv_reduzido(char fnamein[], char fnameout[]){
    int i, j, k, l=0, N, num_col = 1, num_lin = 0, *saida;
    char aux, **colunas;
    FILE *in, *out;
        
    /* Le a quantidade de colunas a serem apresentadas ao fim */
    scanf("%d", &N);
    /* Cria matriz de tamanho igual ao numero de colunas a serem retiradas */
    saida = malloc(N*sizeof(int)); 
    
    /* Aloca na matriz os valores das colunas a serem retiradas */
    for(i=0;i<N;i++){
        scanf("%d", &saida[i]);
        saida[i]--;    
    }
    
    /* Abre arquivos de entrada e saida*/
    in = fopen(fnamein, "r");
    out = fopen(fnameout, "w");
    
    /* Conta o numero de colunas e linhas do arquivo de entrada */
    while (fscanf(in, "%c", &aux) != EOF && aux != '\n'){
        if(aux == ',')    
            num_col++;    
    }
    rewind(in);
    while (fscanf(in, "%c", &aux) != EOF){
        if(aux == '\n')    
            num_lin++;    
    }
    rewind(in);        
    
    /*Cria uma matriz auxiliar para a escrita no arquivo de saida*/
    colunas = malloc(num_col*sizeof(char*));
    for(i=0;i<num_col;i++)
        colunas[i] = malloc(501*sizeof(char));
    
    /* Loop que imprime o arquivo csf reduzido */    
    for(k=0;k<num_lin;k++){                
        i=0;
        j=0;
        /* Percorre a linha da matriz e copia os valores para a matriz */
        while(fscanf(in, "%c", &aux) != EOF && aux != '\n'){
            /* Passa para a proxima linha da matriz quando passa para o proximo campo do registro */
            if(aux == ','){
                colunas[i][j] = '\0';     
                i++;
                j=0;
            }else{
                colunas[i][j] = aux;
                j++;
            }
        }
        colunas[i][j] = '\0';
        /* Imprime no arquivo de saida somente as linhas da coluna que correspondem aos campos desejados */
        for(l=0;l<N-1;l++){
            fprintf(out,"%s,", colunas[saida[l]]);
        }
        /* Imprime o ultimo campo sem a virgula */
        fprintf(out,"%s", colunas[saida[l]]);
        fprintf(out,"\n");
    }
   
    /* Desaloca a memoria */
    for(i=0;i<num_col;i++){
        free(colunas[i]);
    }
    free(colunas);        
    free(saida);
    
    /* Fecha os arquivos */
    fclose(in);
    fclose(out);
}
