#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void max_heapify(int *arr, int i, int heapsize)
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
    max_heapify(arr, largest, heapsize);
  }
}

void build_max_heap(int *arr, int len, int heapsize)
{
  heapsize = len;
  int i;
  for(i = len/2; i >= 0; i--)
  {
    max_heapify(arr, i, heapsize);
  }
}

void executa_heapsort(int len, int arr[], int heapsize)
{
  int i;
  build_max_heap(arr, len, heapsize);
  for(i = len-1; i >= 1; i--)
  {
    troca(&arr[0], &arr[i]);
    heapsize = heapsize -1;
    max_heapify(arr, 0, heapsize);
  }
}


void heapsort(int n) {
	int i;
  int heapsize = n;
	int* vetor = malloc(n * sizeof(int));
	srand (time(NULL));
	for (i = 0; i < n; i++) {
		vetor[i] = rand() % 100;
	}
  printf("[heapsort] Ordenando o vetor: \n", r);
	imprimeVetordeInteiros(n, vetor);
	executa_heapsort(n, vetor, heapsize);
  printf("[heapsort] Vetor ordenado: \n", r);
	imprimeVetordeInteiros(n, vetor);
}