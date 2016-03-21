#include <stdio.h>
int main(int argc, char **argv) {
	int i, n = 4;
	for(i = 1; i < n; i++) {
		if (fork()) {
			break;
		}
	}
	printf("Processo %d de pai %d\n", getpid(), getppid());
	sleep(1);
	return 0;
}
