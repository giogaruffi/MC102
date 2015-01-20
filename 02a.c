/* Nome: Giovani Garuffi Rondel
 * RA: 155559
 * Lab 02a - INSS e IRPF */

#include <stdio.h>

int main () {
    int D;
    double S, INSS, Base, IRPF;
    
    scanf("%lf %d", &S, &D);
    
    /* Cálculo do valor do INSS */
    
    if (S > 4390.24) {
        INSS = 482.93;
    } else if (S >= 2195.13 && S <= 4390.24) {
        INSS = S * 0.11;
    } else if (S >= 1317.08 && S <= 2195.12) {
        INSS = S * 0.09;
    } else if (S <= 1317.07) {
        INSS = S * 0.08;
    }
    printf("INSS: R$ %.2f\n", INSS);
    
    /* Cálculo do valor da Base */
    Base = S - INSS - (D * 179.71);
    printf("Base: R$ %.2f\n", Base);
    
    /* Cálculo do valor do IRPF */
    if (Base > 4463.81) {
        IRPF = (Base - 4463.81) * 0.275;
        IRPF += (891.37 * 0.225) + (893.13 * 0.15) + (891.51 * 0.075);
    }
    if (Base >= 3572.44 && Base <= 4463.81) {
        IRPF = (Base - 3572.44) * 0.225;
        IRPF += (893.13 * 0.15) + (891.51 * 0.075);
    }
    if (Base >= 2679.30 && Base <= 3572.43) {
        IRPF = (Base - 2679.30) * 0.15;
        IRPF += (891.51 * 0.075);
    }
    if (Base >= 1787.78 && Base <= 2679.29) {
        IRPF = (Base - 1787.78) * 0.075;
    }
    printf("IRPF: R$ %.2f\n", IRPF);
    
    return 0;
}
