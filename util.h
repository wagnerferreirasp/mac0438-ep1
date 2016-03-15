/*******************************************************************/
/** MAC 438 - Programação Concorrente                              */
/** IME-USP - Primeiro Semestre de 2016                            */
/** Prof. Marcel Parolin Jackowski                                 */
/**                                                                */
/** Primeiro Exercício-Programa                                    */
/** Arquivo: util.h                                                */
/**                                                                */
/** Wagner Ferreira Alves    7577319                               */
/** Rafael Marinaro Verona   7577323                               */
/** 28/03/2016                                                     */
/*******************************************************************/
#include <unistd.h> //STDOUT_FILENO
#include <string.h> //strlen

/* Imprime imediatamente na saída padrão o que tiver apontado por texto.
   Função criada para substituir o printf, que possui um buffer 
 */
 void imprimeAgora(char *texto);