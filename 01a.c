/* Nome: Giovani Garuffi Rondel
 * RA: 155559
 * Laboratorio 01a - Cálculo de média das notas de avaliaçoes */
 
#include <stdio.h>
#include <math.h>
 
 int main() {
    double P, P1, P2, P3, L, MA, MH, MG;
    
    /* Entrada de notas das provas e dos trabalhos de laboratorio */
    scanf("%lf %lf %lf %lf", &P1, &P2, &P3, &L);
    /* Calculo das Medias */
    P = (3*P1 + 3*P2 + 4*P3)/10.00;
    MA = (P + L)/2.00;
    MH = (2*P*L)/(P + L);
    MG = sqrt(P*L);
    
    /* Imprimindo a resposta */
    printf("Media aritmetica: %.1f\n", MA);
    printf("Media harmonica: %.1f\n", MH);
    printf("Media geometrica: %.1f\n", MG);
    
    return 0;
}
