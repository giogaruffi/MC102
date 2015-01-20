/* Nome: Giovani Garuffi Rondel
 * RA: 155559
 * Lab 03a - Composição de senha */
 
#include <stdio.h>

int main () {
    int contador;
    char letra;
    double total; 
          
    scanf("%c", &letra);        
    
    do {
        /* Loop para denotar uma linha inteira */              
        contador = 0;
        total = 0;
        
        do { 
            /* Loop para denotar o valor de um caractere */
            
                                       
            if (letra == 'A') {
                total += 1.0;
                contador++;
            } else if (letra == 'B') {
                total += 1.0/2;
                contador++;
            } else if (letra == 'C') {
                total += 1.0/4;
                contador++;
            } else if (letra == 'D') {
                total += 1.0/8;
                contador++;
            } else if (letra == 'E') {
                total += 1.0/16;
                contador++;
            } else if (letra == 'F') {
                total += 1.0/32;
                contador++;
            } else if (letra == 'G') {
                total += 1.0/64;
                contador++;
            } else if (letra == 'H') {
                total += 1.0/128;
                contador++;
            }            
            
            scanf("%c", &letra);
                       
        } while (letra != '\n');
        
           /* Impressão do dígito correspondente */ 
            if (total == 1)
                printf("%d", contador);
            else 
                printf("0");
        
         scanf("%c", &letra);
                
    } while (letra != '*');       

    printf("\n");
                                            
    return 0;
}
