#include<sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
	int fd, result;
	size_t size;
	char string[] = "Gr.3.008.2.24", resstring[13];
	char name[] = "fifo.fifo";
	if(mknod(name, S_IFIFO | 0666, 0) < 0){
		printf("не удалось создать  FIFO\n");
		exit(-1);
	}
		if(result = fork() < 0){
		printf("не удалось создать дочерный процесс\n");
		exit(-1);
	}
	else if(result > 0) {
		if ((fd = open(name, O_WRONLY)) < 0) {
			printf("не удалось открыть FIFO для записи\n");
			exit(-1);
		}
		size = write(fd, string, 13);
			if (size != 13) {
				printf("не удалось записать всю строку\n");
				exit(-1);
		}
		close(fd);
		printf("строка записана в FIFO.  процесс родитель заканчивает работу\n");
	}
	else {
		if((fd = open(name, O_RDONLY)) < 0) {
			printf("не удалость открыть FIFO для чтения\n");
			exit(-1);
		}
		size = read(fd, resstring, 13);
		if(size != 13) {
			printf("не удалось прочитать всю строку\n");
			exit(-1);
		}
		printf("Прочитаная строка: %s Дочерный процесс завершает работу\n", resstring);
		close(fd);
	}
	return 0;
}

