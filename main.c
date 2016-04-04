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
/** 04/04/2016                                                     */
/*******************************************************************/

#include <stdio.h>          /* printf */
#include <stdlib.h>         /* atoi, exit, EXIT_SUCCESS */
#include <unistd.h>         /* fork */
#include <sys/types.h>      /* pid_t */
#include <sys/wait.h>       /* wait */
#include "processo1.h"      /* heapsort */
#include "processo2.h"      /* fibonacci */
#include "processo3.h"      /* agulhaDeBuffon */
#include "processo4.h"      /* integracaoPorSimulacao */

/* Cria um processso através de fork 
 *  Parâmetro funcaoDoProcessoFilho: é a funcão que será executada no novo processo
 *  Parâmetro parametro: é o parâmetro da funcão funcaoDoProcessoFilho
 *  Parâmetro idProcesso: é uma identificação do novo processo */
void criaProcesso(void (*funcaoDoProcessoFilho)(int), int parametro, char *idProcesso) {
    pid_t retornoDoFork = fork();
    if (retornoDoFork == 0) { // É o processo filho!
        printf("%s começou a rodar\n", idProcesso);
        funcaoDoProcessoFilho(parametro);
        printf("%s parou de rodar\n", idProcesso);
        exit(EXIT_SUCCESS);
    } 
}


/* Espera o fim da execução de quantos processos for necessário esperar. */
void esperaFilhosTerminarem() {
    int status;
    printf("=================Processo pai começou a esperar\n");
    pid_t espera = wait(&status);
    while (espera != -1) { /* espera quantos filhos for necessário */
        espera = wait(&status);
    }
}

int main(int argc, char const *argv[])
{
    int m, n, r, s;
    m = atoi(argv[1]);
    n = atoi(argv[2]);
    r = atoi(argv[3]);
    s = atoi(argv[4]);
    printf("=================Processo pai começou a rodar\n");
    criaProcesso(&heapsort, m, " HEAPSORT");
    criaProcesso(&fibonacci, n, "  FIBONACCI");
    criaProcesso(&agulhaDeBuffon, r, "   AGULHA_DE_BUFFON");
    criaProcesso(&integracaoPorSimulacao, s, "    INTEGRACAO_POR_SIMULACAO");
    esperaFilhosTerminarem();
    printf("=================Processo pai terminou de rodar\n");
    return 0;
}
