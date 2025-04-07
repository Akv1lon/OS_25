//Программа, порождающая дочерний процесс (часть 1)
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	pid_t procid, pprocid;
	int a=0, b;
	procid = getpid();
	pprocid = getppid();
	printf("До вызова fork()\n");
	printf("ID текущего процесса %d\nID родительского процесса: %d\n", procid, pprocid);
	printf("Начальное значение a: %d\n", a);
	b = fork();
	a = a+1;
	procid = getpid();
	pprocid = getppid();
	printf("После  вызова fork()\n");
	printf("ID текущего процесса %d\nID родительского процесса: %d\nНовое значение a: %d\n", procid, pprocid, a);
	return 0;
}
