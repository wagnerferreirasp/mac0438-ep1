/*******************************************************************/
/** MAC 438 - Programação Concorrente                              */
/** IME-USP - Primeiro Semestre de 2016                            */
/** Prof. Marcel Parolin Jackowski                                 */
/**                                                                */
/** Primeiro Exercício-Programa                                    */
/** Arquivo: processo2.c                                           */
/**                                                                */
/** Wagner Ferreira Alves    7577319                               */
/** Rafael Marinaro Verona   7577323                               */
/** 04/04/2016                                                     */
/*******************************************************************/

#include "processo2.h"

/* Calcula o n-ésimo número de Fibonacci recursivamente */
long long calculaFibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 1;
	return calculaFibonacci(n-1) + calculaFibonacci(n-2);
}

/* Calcula o n-ésimo número de Fibonacci */
void fibonacci(int n) {
	printf("[fibonacci] Calculando o %d-ésimo número de Fibonacci\n", n);
	printf("[fibonacci] O %d-ésimo número de Fibonacci é: %lld\n", n, calculaFibonacci(n));
}
