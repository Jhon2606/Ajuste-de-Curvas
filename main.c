#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    double t[100], N[100], y[100];
    int n = 0, i;
    FILE *arq;

    if (argc < 2) {
        printf("Uso: %s arquivo.txt\n", argv[0]);
        return 1;
    }

    arq = fopen(argv[1], "r");
    if (arq == NULL) {
        printf("Nao consegui abrir %s\n", argv[1]);
        return 1;
    }

    while (n < 100 && fscanf(arq, "%lf %lf", &t[n], &N[n]) == 2) {
        y[n] = log(N[n]);
        n++;
    }
    fclose(arq);

    printf("%d pontos lidos\n", n);
    for (i = 0; i < n; i++)
        printf("%.0f  %.0f  %f\n", t[i], N[i], y[i]);

    return 0;
}
