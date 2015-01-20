/********************************
 * Nome: Giovani Garuffi Rondel *
 * RA: 155559                   *
 * Lab13a - JMob                *
 ********************************/

#include <stdio.h>

/* Funcao recursiva que testa os equilibrios */
int teste_equilibrio (int *equilibrado){
    /* Declaracao de variaveis */
    int Pe, De, Pd, Dd;
    /* Leitura dos valores de cada linha */
    scanf("%d %d %d %d", &Pe, &De, &Pd, &Dd);
    
    /* Caso a esquerda seja zero em primeiro lugar, leia a proxima linha */
    if(!Pe){
        Pe = teste_equilibrio(equilibrado);
    }
    /* Caso a direita seja zero, leia a proxima linha */
    if(!Pd){
        Pd = teste_equilibrio(equilibrado);
    }
    /* Sendo Pe e Pd nao sejam zero, testar o equilibrio */
    if((Pe*De)!=(Pd*Dd)){
        *equilibrado = 0;
    }
    /* Caso Base = Pe e Pd nao sejam zero, retorna soma dos pesos */
    return (Pe + Pd);
}

int main (){
    int peso, equilibrado = 1;
 
    /* Chamada da funcao recursiva com "equilibrado" como ponteiro */
    peso = teste_equilibrio(&equilibrado);
   
    /* Caso o equilibrio seja verdadeiro */
    if(equilibrado)
        printf("Mobile equilibrado\n");
    /* Caso nao haja equilibrio */
    else
        printf("Mobile desequilibrado\n");
    /* Impressao do peso final */    
    printf("Peso total: %d\n", peso);
    
    return 0;
}
