/*******************************************************************/
/** MAC 438 - Programação Concorrente                              */
/** IME-USP - Primeiro Semestre de 2016                            */
/** Prof. Marcel Parolin Jackowski                                 */
/**                                                                */
/** Primeiro Exercício-Programa                                    */
/** Arquivo: processo3.c                                           */
/**                                                                */
/** Wagner Ferreira Alves    7577319                               */
/** Rafael Marinaro Verona   7577323                               */
/** 04/04/2016                                                     */
/*******************************************************************/

#include "processo3.h"

void agulhaDeBuffon(int r) {
    int i, t = 0;
    srand (time(NULL));
    printf("[agulhaDeBuffon] Agulha De Buffon irá executar %d iterações\n", r);
    for (i = 0; i < r; ++i) {
        float d = (float) rand()/RAND_MAX;    
        float theta = (float) 2 * PI * rand()/RAND_MAX;    
        if (d + sin(theta) < 0 || d + sin(theta) > 1) {
            t++;
        }
    }
    printf("[agulhaDeBuffon] Probabilidade estimada: %f\n", (float) t/r);
}