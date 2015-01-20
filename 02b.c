/* Nome: Giovani Garuffi Rondel
 * RA: 155559
 * Lab 02b - Pedra - Papel - Tesoura - Lagarto - Spock */
 
 #include <stdio.h>
 
 int main () {
    int n, i, l, s, a = 0, b = 0;
    
    /* Número de partidas */
    scanf("%d\n", &n);
    
    /* Resultado de cada partida */
        
    for (i = 1; i <= n; i++) {
        scanf("%d %d", &s, &l);
    if (l == s) {
        printf("Empate\n");
    }
    if ((l == 3) && (s == 2)) {
        printf("Leonard: Tesoura corta Papel\n");
        a++;
    }
    if ((s == 3) && (l == 2)) {
        printf("Sheldon: Tesoura corta Papel\n");
        b++;
    }
    if ((l == 2) && (s == 1)) {
        printf("Leonard: Papel embrulha Pedra\n");
        a++;
    }
    if ((s == 2) && (l == 1)) {
        printf("Sheldon: Papel embrulha Pedra\n");
        b++;
    }
    if ((l == 1) && (s == 4)) {
        printf("Leonard: Pedra amassa Lagarto\n");
        a++;
    }
    if ((s == 1) && (l == 4)) {
        printf("Sheldon: Pedra amassa Lagarto\n");
        b++;
    }
    if ((l == 4) && (s == 5)) {
        printf("Leonard: Lagarto envenena Spock\n");
        a++;
    }
    if ((s == 4) && (l == 5)) {
        printf("Sheldon: Lagarto envenena Spock\n");
        b++;
    }
    if ((l == 5) && (s == 3)) {
        printf("Leonard: Spock quebra Tesoura\n");
        a++;
    }
    if ((s == 5) && (l == 3)) {
        printf("Sheldon: Spock quebra Tesoura\n");
        b++;
    }
    if ((l == 3) && (s == 4)) {
        printf("Leonard: Tesoura decepa Lagarto\n");
        a++;
    }
    if ((s == 3) && (l == 4)) {
        printf("Sheldon: Tesoura decepa Lagarto\n");
        b++;
    }
    if ((l == 4) && (s == 2)) {
        printf("Leonard: Lagarto come Papel\n");
        a++;
    }
    if ((s == 4) && (l == 2)) {
        printf("Sheldon: Lagarto come Papel\n");
        b++;
    }
    if ((l == 2) && (s == 5)) {
        printf("Leonard: Papel refuta Spock\n");
        a++;
    }
    if ((s == 2) && (l == 5)) {
        printf("Sheldon: Papel refuta Spock\n");
        b++;
    }
    if ((l == 5) && (s == 1)) {
        printf("Leonard: Spock vaporiza Pedra\n");
        a++;
    }
    if ((s == 5) && (l == 1)) {
        printf("Sheldon: Spock vaporiza Pedra\n");
        b++;
    }
    if ((l == 1) && (s == 3)) {
        printf("Leonard: Pedra quebra Tesoura\n");
        a++;
    }
    if ((s == 1) && (l == 3)) {
        printf("Sheldon: Pedra quebra Tesoura\n");
        b++;
    }
    }
    
    /* Resultado final */
    printf("Sheldon %d x %d Leonard\n", b, a);
    
    return 0;
}
