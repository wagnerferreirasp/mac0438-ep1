#include "processo3.h"

void agulhaDeBuffon(int r) {
    int i, t = 0;
    printf("[agulhaDeBuffon] Agulha De Buffon irá executar %d iterações\n", r);
    for (i = 0; i < r; ++i)
    {
        float d = (float) rand()/RAND_MAX;    
        float theta = (float) 2 * PI * rand()/RAND_MAX;    
        if (d + sin(theta) < 0 || d + sin(theta) > 1) {
            t++;
        }
    }
    printf("[agulhaDeBuffon] Probabilidade estimada: %f\n", (float) t/r);
}