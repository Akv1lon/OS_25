//Программа для чтения информации из FIFO
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#define BYTES 44

int main(){
	int fd;
	size_t size;
	char resstring[BYTES];
	char name[]="file.fifo";
	/*
	if (mknod(name, S_IFIFO | 0664, 0)<0){
		printf("Не удалось создать файл FIFO\n");
		exit(-1);
	}
	*/
	printf("Процесс-приемник готов к чтению информации из FIFO\n");
	if((fd=open(name, O_RDONLY))<0){
		printf("Не удалось открыть fifo на чтение\n");
		exit(-1);
	}
	size=read(fd, resstring, BYTES);
	if(size<0){
		printf("Не удалось прочитать строки из fifo");
		exit(-1);
	}
	printf("Содержимое прочитанной строки: %s\n", resstring);
	if (close(fd)<0){
		printf("Не удалось закрыть fifo\n");
		exit(-1);
	}
	printf("Процесс-приемник завершает работу\n");
	return 0;
}
