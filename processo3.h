/*******************************************************************/
/** MAC 438 - Programação Concorrente                              */
/** IME-USP - Primeiro Semestre de 2016                            */
/** Prof. Marcel Parolin Jackowski                                 */
/**                                                                */
/** Primeiro Exercício-Programa                                    */
/** Arquivo: processo3.h                                           */
/**                                                                */
/** Wagner Ferreira Alves    7577319                               */
/** Rafael Marinaro Verona   7577323                               */
/** 04/04/2016                                                     */
/*******************************************************************/

#ifndef PROCESSO3_H
#define PROCESSO3_H

#include <stdlib.h> /* rand, srand, RAND_MAX */
#include <stdio.h> /* printf, NULL */
#include <math.h> /* sin */
#include <time.h> /* time */


/* Constante PI */
#define PI 3.14159265358979323846

/* Resolve o problema da agulha de Buffon em r lançamentos */
void agulhaDeBuffon(int r);

#endif