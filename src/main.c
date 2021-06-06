#include <stdio.h>

int main(void)
{

    float numero = 79.1254;

    unsigned int conversao = *(int *)&numero;
    unsigned int sinal = conversao >> 31;

    signed int expoente = (signed int)(((conversao >> 23) - 256 * sinal) - 127);

    unsigned int mask = 8388607;
    unsigned int mantissa = (conversao & mask);
    int counter = 2;
    double soma = 0;
    int posicao = 4194304;
    for (int i = 1; i <= 23; ++i)
    {
        if (mantissa / posicao)
        {
            soma += (1 / (double)counter);
            mantissa -= posicao;
        }
        counter *= 2;

        posicao = posicao >> 1;
    }
    soma += 1;
    printf("%f é representado em notação científica binária como:\n", numero);
    if (sinal)
        printf("-");
    printf("%.23f x 2^%d\n", soma, expoente);

    return 0;
}