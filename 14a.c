/**********************************
* Nome: Giovani Garuffi Rondel    *
* RA: 155559                      *
* Lab14a - Gerenciador de memoria *
***********************************/

#include <stdio.h>

/*Funcao que aloca as memorias de cada programa*/
double alocacao(double disponivel){
    double alocada = 0;
    char caracter;
    
    /* Le o tipo de alocacao que o programa realiza */
    scanf("%c", &caracter);
    /* Caso base 1: caractere de fim da sequencia */
    if(caracter == '#'){
        return alocada;
    }
    /* Caso base 2: caractere que aloca a quantidade de memoria total 
    disponivel para o programa */
    if(caracter == 'I'){
        return disponivel;
    }
    /* Caso 3: Divisao da memoria disponivel em 3 partes, uma com 50% do 
    tamanho da memoria original e duas com 25% */
    if(caracter == 'D'){
        alocada = alocacao(disponivel/4.0);
        alocada += alocacao(disponivel/4.0);
        /* Retorna o valor alocado para a memoria se nao for caso base */
        return (disponivel/2.0 + alocada);
    }
    return 0;
}

int main (){
    /* Memoria alocada inicial eh nula */
    double alocada = 0.0;
    /* Caracter de verificacao final */ 
    char caracter_final;
    
    /* Chamada da funcao de alocacao */
    alocada = alocacao(1.0);
    
    /* Leitura do ultimo caractere da sequencia */
    scanf("%c", &caracter_final);
    
    /* Se a memoria alocada eh menor que 1, entao houve alocacao parcial */
    if (alocada < 1.0)
        printf("Alocacao parcial\n");
    /* Caso a memoria alocada seja preenchida, checar o proximo caracter: */
    else if (alocada == 1.0){
        /* Caso seja '#', a sequencia chegou ao fim e a alocacao foi total */
        if (caracter_final == '#')
            printf("Alocacao total\n");
        /* Caso contrario, a sequencia nao acabou e a alocacao eh invalida */
        else
            printf("Alocacao invalida\n");
    }
    
    return 0;
}
