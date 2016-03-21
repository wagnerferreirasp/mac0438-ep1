/*******************************************************************/
/** MAC 438 - Programação Concorrente                              */
/** IME-USP - Primeiro Semestre de 2016                            */
/** Prof. Marcel Parolin Jackowski                                 */
/**                                                                */
/** Primeiro Exercício-Programa                                    */
/** Arquivo: processo4.h                                           */
/**                                                                */
/** Wagner Ferreira Alves    7577319                               */
/** Rafael Marinaro Verona   7577323                               */
/** 04/04/2016                                                     */
/*******************************************************************/

#ifndef PROCESSO4_H
#define PROCESSO4_H

#include <stdlib.h> /* rand, srand, RAND_MAX */
#include <stdio.h> /* printf, NULL */
#include <math.h> /* cos */
#include <time.h> /* time */

/* Devolve o valor da secante de x */
float sec(float x);

/* Estima o valor da integral de sec(X), 
 * para 0 <= x <= 1, utilizando s números aleatórios */
void integracaoPorSimulacao(int s);

#endif