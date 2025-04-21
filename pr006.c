//Программа, анализирующая аргументы командной строки
#include <stdio.h>

int main(int argc, char* argv[], char* envp[]){
	//Количество аргументов, переданных программе
	printf("Программе переданно %d аргументов\n\n", argc );

	//Список значений аргументов (массив argv)
	for (int i=0; i<argc; i++)
		printf("Аргумент [%d]: %s", i, argv[i]);
		printf("\n");

}
