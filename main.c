/*******************************************************************/
/** MAC 438 - Programação Concorrente                              */
/** IME-USP - Primeiro Semestre de 2016                            */
/** Prof. Marcel Parolin Jackowski                                 */
/**                                                                */
/** Primeiro Exercício-Programa                                    */
/** Arquivo: main.c                                                */
/**                                                                */
/** Wagner Ferreira Alves    7577319                               */
/** Rafael Marinaro Verona   7577323                               */
/** 28/03/2016                                                     */
/*******************************************************************/

#include <stdio.h> //printf 
#include <stdlib.h>
#include "processo1.h"
#include "processo2.h"
#include "processo3.h"
#include "processo4.h"
#include <time.h> // time
#include <math.h> // sin

#define PI 3.14159265358979323846

int count = 800;

void criaProcesso( void (*funcaoDoProcessoFilho)(int), int parametro, int idProcesso) {
    pid_t retornoDoFork = fork();
    if (retornoDoFork == 0) { // É o processo filho!
        printf("[%d - Processo %d começou a rodar\n", idProcesso, idProcesso);
        funcaoDoProcessoFilho(parametro);
        printf("%d] - Processo %d parou de rodar\n", idProcesso, idProcesso);
        exit(0);
    } 
}

void ordenacao(int m) {
    int i;
    for (i = 0; i < count; ++i)
    {
        if (i % 30 == 0)
            printf("1 - Sou o ordenacao com parametro %d\n", m);
    }
}

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

void fibonacci(int n) {
    int i;
    for (i = 0; i < count; ++i)
    {
        if (i % 38 == 0)
            printf("2 - Sou o fibonacci com parametro %d\n", n);
    }
}

float sec(float x) {
    return 1.0/cos(x);
}

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

void esperaFilhosTerminarem() {
    int status;
    printf("=================Processo pai começou a esperar\n");
    pid_t espera = wait(&status);
    while (espera != -1) { // espera quantos filhos for necessário
        espera = wait(&status);
    }
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int m = 1, n = 2, r = 3, s = 4;
    /*m = atoi(argv[1]);
    n = atoi(argv[2]);
    r = atoi(argv[3]);
    s = atoi(argv[4]);*/
    printf("=================Processo pai começou a rodar\n");
    criaProcesso(&ordenacao, m, 1);
    criaProcesso(&fibonacci, n, 2);
    criaProcesso(&agulhaDeBuffon, r, 3);
    criaProcesso(&integracaoPorSimulacao, s, 4);
    esperaFilhosTerminarem();
    printf("=================Processo pai terminou de rodar\n");
    return 0;
}