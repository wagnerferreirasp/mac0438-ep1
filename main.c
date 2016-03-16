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

#include <stdio.h>
#include <stdlib.h>
#include "processo1.h"
#include "processo2.h"
#include "processo3.h"
#include "processo4.h"

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

void fibonacci(int n) {
    int i;
    for (i = 0; i < count; ++i)
    {
        if (i % 38 == 0)
            printf("2 - Sou o fibonacci com parametro %d\n", n);
    }
}

void agulhaDeBuffon(int r) {
    printf("3 - Sou agulhaDeBuffon. Só entrei com parametro %d\n", r);
}

void integracaoPorSimulacao(int s) {
    int i;
    for (i = 0; i < count-20; ++i)
    {
        if (i % 16 == 0)
            printf("4 - Sou o integracaoPorSimulacao com parametro %d\n", s);
    }
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