/* Nome: Giovani Garuffi Rondel
 * RA: 155559
 * Lab 01b - Notas do vestibular */
 
 #include <stdio.h>
 #include <math.h>
 
 int main() {
    int A, NMO;
    double Pcg, Pin, Ppo, Pma, Pch, Pcn, Ncg, Mcg, DPcg, NPcg, Nin, Min, DPin, Npo, Mpo, DPpo, Nma, Mma, DPma, Nch, Mch, DPch, Ncn, Mcn, DPcn, NPin, NPpo, NPma, NPch, NPcn, NF;
    
    /* Calculo da nota da primeira fase do vestibular */
    scanf("%d %d", &A, &NMO);
    scanf("%lf %lf %lf %lf %lf %lf", &Pcg, &Pin, &Ppo, &Pma, &Pch, &Pcn);
    scanf("%lf %lf %lf", &Ncg, &Mcg, &DPcg);
    NPcg = (Ncg - Mcg)*100.00/DPcg + 500.00;
    printf("Primeira Fase: %.1f\n", NPcg);
        
    if (NPcg >= 550.0) {
        scanf("%lf %lf %lf", &Nin, &Min, &DPin);
        scanf("%lf %lf %lf", &Npo, &Mpo, &DPpo);
        scanf("%lf %lf %lf", &Nma, &Mma, &DPma);
        scanf("%lf %lf %lf", &Nch, &Mch, &DPch);
        scanf("%lf %lf %lf", &Ncn, &Mcn, &DPcn);
    
    /* Calculo da nota padronizada de cada disciplina */
    NPin = (Nin - Min)*100.00/DPin + 500.00;
    NPpo = (Npo - Mpo)*100.00/DPpo + 500.00;
    NPma = (Nma - Mma)*100.00/DPma + 500.00;
    NPch = (Nch - Mch)*100.00/DPch + 500.00;
    NPcn = (Ncn - Mcn)*100.00/DPcn + 500.00;
    
    /* Calculo da nota da segunda fase do vestibular */
    NF = (Pcg*NPcg + Pin*NPin + Ppo*NPpo + Pma*NPma + Pch*NPch + Pcn*NPcn)/(Pcg + Pin + Ppo + Pma + Pch + Pcn);
    printf("Segunda Fase: %.1f\n", NF);
    
    /* Determinaçao do grupo correspondente */
    if (A == 1) {
        if ((NPma >= NMO) && (NPcn >= NMO)) {
            printf("Grupo 1\n");
        } else {
        printf("Grupo 2\n");
        }
    }
    if (A == 2) {
        if ((NPpo >= NMO) && (NPch >= NMO)) {
            printf("Grupo 1\n");
        } else {
            printf("Grupo 2\n");
        }
    }
    if (A == 3) {
        if (NPcn >= NMO) {
            printf("Grupo 1\n");
        } else {
            printf("Grupo 2\n");
        }
    }
    
}
    
    return 0;
}
