/*******************************************************************/
/** MAC 438 - Programação Concorrente                              */
/** IME-USP - Primeiro Semestre de 2016                            */
/** Prof. Marcel Parolin Jackowski                                 */
/**                                                                */
/** Primeiro Exercício-Programa                                    */
/** Arquivo: util.c                                                */
/**                                                                */
/** Wagner Ferreira Alves    7577319                               */
/** Rafael Marinaro Verona   7577323                               */
/** 28/03/2016                                                     */
/*******************************************************************/
#include "util.h"

void imprimeAgora(char *texto) {
    write(STDOUT_FILENO, texto, strlen(texto));
}