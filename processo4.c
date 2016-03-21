/*******************************************************************/
/** MAC 438 - Programação Concorrente                              */
/** IME-USP - Primeiro Semestre de 2016                            */
/** Prof. Marcel Parolin Jackowski                                 */
/**                                                                */
/** Primeiro Exercício-Programa                                    */
/** Arquivo: processo4.c                                           */
/**                                                                */
/** Wagner Ferreira Alves    7577319                               */
/** Rafael Marinaro Verona   7577323                               */
/** 04/04/2016                                                     */
/*******************************************************************/

#include "processo4.h"

float sec(float x) {
    return 1.0/cos(x);
}

void integracaoPorSimulacao(int s) {
    int i, t = 0;
    srand (time(NULL));
    printf("[integracaoPorSimulacao] Sorteando s = %d pontos\n", s);
    for (i = 0; i < s; ++i) {
        float x = (float) rand()/RAND_MAX;
        float y = (float) sec(1) * rand()/RAND_MAX;
        if (y <= sec(x)) {
            t++;
        }
    }
    printf("[integracaoPorSimulacao] Número de pontos abaixo da curva: t = %d\n", t);
    printf("[integracaoPorSimulacao] Área estimada: %f\n", sec(1) * (float)t/s);
}