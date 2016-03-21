/*******************************************************************/
/** MAC 438 - Programação Concorrente                              */
/** IME-USP - Primeiro Semestre de 2016                            */
/** Prof. Marcel Parolin Jackowski                                 */
/**                                                                */
/** Primeiro Exercício-Programa                                    */
/** Arquivo: processo1.c                                           */
/**                                                                */
/** Wagner Ferreira Alves    7577319                               */
/** Rafael Marinaro Verona   7577323                               */
/** 04/04/2016                                                     */
/*******************************************************************/

#include "processo1.h"

void imprimeVetordeInteiros(int n, int vetor[]) {
    int i;
    printf("[heapsort] ");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void troca(int *a ,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int *arr, int i, int heapsize)
{
    int l = 2*i, r =2*i+1, largest;
    if(l < heapsize && arr[l] > arr[i])
        largest = l;
    else
        largest = i;
    if(r < heapsize && arr[r] > arr[largest])
        largest = r;
    if(largest != i)
    {
        troca(&arr[i], &arr[largest]);
        maxHeapify(arr, largest, heapsize);
    }
}

void buildMaxHeap(int *arr, int len, int heapsize)
{
    heapsize = len;
    int i;
    for(i = len/2; i >= 0; i--)
    {
        maxHeapify(arr, i, heapsize);
    }
}

void executaHeapsort(int len, int arr[], int heapsize)
{
    int i;
    buildMaxHeap(arr, len, heapsize);
    for(i = len-1; i >= 1; i--)
    {
        troca(&arr[0], &arr[i]);
        heapsize = heapsize -1;
        maxHeapify(arr, 0, heapsize);
    }
}


void heapsort(int m) {
    int i;
    int heapsize = m;
    int* vetor = malloc(m * sizeof(int));
    srand (time(NULL));
    for (i = 0; i < m; i++) {
        vetor[i] = rand() % 100;
    }
    printf("[heapsort] Ordenando o vetor: \n");
    imprimeVetordeInteiros(m, vetor);
    executaHeapsort(m, vetor, heapsize);
    printf("[heapsort] Vetor ordenado: \n");
    imprimeVetordeInteiros(m, vetor);
}