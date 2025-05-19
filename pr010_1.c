//Программа-отправитель информации в FIFO

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
	printf("Отправитель записал строку в fifo и завершает работу\n");
	if((fd=open(name, O_WRONLY))<0){
			printf("Не удалось открыть FIFO на запись");
	}
	printf("Процесс-отправитель начинает запись в FIFO\n");
	size=write(fd,"Текстовая строка для fifo",BYTES);
	if (size != BYTES){
		printf("Не удалось записать всю строку в fifo\n");
		exit(-1);
	}
	if (close(fd)<0) {
		printf("Не удалось закрыть fifo\n");
		exit(-1);
	}
	return 0;
}
