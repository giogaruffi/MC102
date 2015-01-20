/* Nome: Giovani Garuffi Rondel
 * RA: 155559
 * Lab 04a - Deep Web */
 
 #include <stdio.h>
 
 int main () {
    /* Declaracao de variaveis */
    int numero_digitos, senha[16], i, j, k, digitos_conhecidos, soma = 0;
    
    /* Entrada do numero de digitos da senha */
    scanf("%d\n", &numero_digitos);
 
    /* Entrada dos valores ja definidos da senha */
    for ( i = 0; i < numero_digitos; i++ ) {
        scanf("%d", &senha[i]);      
    }
        
    /* Calculo dos digitos restantes da senha */
    for ( digitos_conhecidos = numero_digitos; digitos_conhecidos < 15; digitos_conhecidos++ ) {
    /* Calculo do valor da soma dos digitos conhecidos */        
        for ( j = 0; j < digitos_conhecidos; j++ ) {
            soma += digitos_conhecidos*(j + 1)*senha[j];            
        }
    /* Atribuicao do valor do digito calculado */
        senha[digitos_conhecidos] = soma%11;
            if ( soma%11 == 10 ) {
                senha[digitos_conhecidos] = 0;
            }
    /* Zerar soma para o calculo do proximo digito */
        soma = 0;    
    }
             
    /* Saída - senha final */
    for ( k = 0; k < 15; k++ ) {
        printf("%d", senha[k]);
    }
    
    printf("\n");
    
    return 0;
 }
