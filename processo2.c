#include <stdio.h>
#include <stdlib.h>

long long calcula_fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 1;
	return calcula_fibonacci(n-1) + calcula_fibonacci(n-2);
}

void fibonacci(int n) {
	printf("[fibonacci] Calculando o %d-ésimo número de Fibonacci\n", n);
	printf("[fibonacci] O %d-ésimo número de Fibonacci é: %lld\n", n, fibonacci(n));
}
