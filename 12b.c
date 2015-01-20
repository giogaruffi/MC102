/*************************************
 * Autor: Giovani Garuffi Rondel     *
 * RA: 155559                        *
 * Laboratorio 12b: Whiteworse       *
 *************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Tamanho maximo do nome do titular */
#define MAXNOME 21
/* Tamanho maximo do nome dos arquivos de entrada/saida */
#define MAXNOMEARQ 101
/* Numero maximo de contas */
#define MAXCONTAS 20
/* Numero maximo de transacoes */
#define MAXTRANS 40
/* Valor da taxa de deposito em conta com saldo negativo */
#define TAXA 5.00

/* Conta
 * ag = numero da agencia
 * cc = numero da conta corrente
 * titular = Nome do titular da conta
 * saldo = Saldo da conta
 */
struct Conta {
    int ag;
    int cc;
    char titular[MAXNOME];
    double saldo;
};

typedef struct Conta Conta;

/* Transacao
 * tipo - 'D' para Depositos e 'S' para Saques
 * ag - Numero da agencia
 * cc - Numero da conta corrente
 * valor - Valor da operacao
 */
struct Transacao {
    char tipo;
    int ag;
    int cc;
    double valor;
};

typedef struct Transacao Transacao;

/* Funcoes responsaveis pelo calcula das alteracoes do saldo */
void deposito (Transacao transacoes[], int i, Conta contas[], int j, Transacao validas[]);
void saque (Transacao transacoes[], int i, Conta contas[], int j, Transacao validas[]);

int main(int argc, char **argv) {
    /* Nome do arquivo binario com as contas */
    char nomeArqConta[MAXNOMEARQ];
    /* Nome do arquivo binario com as transacoes */
    char nomeArqTrans[MAXNOMEARQ];
    /* Nome do arquivo binario de saida */
    char nomeArqSaida[MAXNOMEARQ];
    FILE *arqConta, *arqTrans, *arqSaida;
    /* Numeros de contas e transacoes dos arquivos de entrada */
    int numContas, numTrans;
    Conta *contas;
    Transacao *transacoes, *validas;
    int i, j;
    
    /* Obtendo o nome dos arquivos */
    strcpy(nomeArqConta, argv[1]);
    strcpy(nomeArqTrans, argv[2]);
    strcpy(nomeArqSaida, argv[3]);

    /* Abrir arquivos */
    arqConta = fopen(nomeArqConta,"rb");
    arqTrans = fopen(nomeArqTrans, "rb");
    arqSaida = fopen(nomeArqSaida, "wb");
 
    /* Verificacao da abertura */
    if((!arqConta)||(!arqTrans)||(!arqSaida)){
        return 0;
    }
    
    /* Le a quantidade de contas a serem lidas a seguir */
    fread(&numContas,sizeof(int),1,arqConta);    
    /* Cria um vetor para armazenar as informacoes das contas */
    contas = malloc(numContas*sizeof(Conta));
    /* Armazena os valores de cada conta */
    for(i=0;i<numContas;i++){
        fread(&contas[i],sizeof(Conta),1,arqConta);
    }
    
    /* Le a quantidade de transacoes a serem lidas a seguir */
    fread(&numTrans,sizeof(int),1,arqTrans);    
    /* Cria um vetor para armazenar as informacoes das transacoes*/    
    transacoes = malloc(numTrans*sizeof(Transacao));
    /* Cria vetor que marca as transacoes bem sucedidas */
    validas = malloc(numTrans*sizeof(Transacao));
    /* Armazena os valores de cada transacao */    
    for(i=0;i<numTrans;i++){
        fread(&transacoes[i],sizeof(Transacao),1,arqTrans);
    }
    
    /* Verifica o tipo de transacao */
    for(i=0;i<numTrans;i++){
        for(j=0;j<numContas;j++){
            if(transacoes[i].tipo == 'D')
                deposito(transacoes,i,contas,j,validas);
            else
                saque(transacoes,i,contas,j,validas);  
        }
    }
    
    /* Escreve o arquivo de saida com as contas alteradas */
    fwrite(&numContas,sizeof(int),1,arqSaida);
    for(i=0;i<numContas;i++){
        fwrite(&contas[i],sizeof(Conta),1,arqSaida);
    }
    
    /* Impressao na saida padrao */
    for(i=0;i<numTrans;i++){
        if(validas[i].valor)
            printf("T%d: %c %d %d %.2f\n", i, validas[i].tipo, validas[i].ag, validas[i].cc, validas[i].valor);
    }
    
    /* Fecha os arquivos */
    fclose(arqConta);
    fclose(arqTrans);
    fclose(arqSaida);

    /* Desaloca a memoria */
    free(transacoes);
    free(contas);
    free(validas);
    
    return 0;
}

void deposito (Transacao transacoes[], int i, Conta contas[], int j, Transacao validas[]){
    
    /* Verificao das condicoes para a validade da transacao e realizacao dessa */
    if((contas[j].ag == transacoes[i].ag)&&(contas[j].cc == transacoes[i].cc)){
        contas[j].saldo += transacoes[i].valor;
        validas[i] = transacoes[i];
    } else {
        return;
    }            
    return;
}

void saque (Transacao transacoes[], int i, Conta contas[], int j, Transacao validas[]){

     /* Verificao das condicoes para a validade da transacao e realizacao dessa */
     if((contas[j].ag == transacoes[i].ag)&&(contas[j].cc == transacoes[i].cc)&&(contas[j].saldo>0)&&(contas[j].saldo - transacoes[i].valor >= -100)){
         contas[j].saldo -= transacoes[i].valor;
         validas[i] = transacoes[i];            
         if(contas[j].saldo < 0){
             contas[j].saldo -= 5;
         }
     }else{
         return;
     }
     return;
}
