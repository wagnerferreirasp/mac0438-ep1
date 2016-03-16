#include "processo4.h"

void integracaoPorSimulacao(int s) {
    int i, t = 0;
    printf("[integracaoPorSimulacao] Sorteando s = %d pontos\n", s);
    for (i = 0; i < s; ++i)
    {
        float x = (float) rand()/RAND_MAX;
        float y = (float) sec(1) * rand()/RAND_MAX;
        if (y <= sec(x)) {
            t++;
        }
    }
    printf("[integracaoPorSimulacao] Número de pontos abaixo da curva: t = %d\n", t);
    printf("[integracaoPorSimulacao] Área estimada: %f\n", sec(1) * (float)t/s);
}