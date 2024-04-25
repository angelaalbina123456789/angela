#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char *argv[], char *envp[]) {
	printf("Количество параметров, переданных программе: %d", argc);
	for(int  i=0; i<argc; i++) {
		printf("Параметр %d: %s\n", i, argv[i]);
	} 
	int j=0; 
	while (envp[j]!=NULL) {
		printf("Параметр окружения %d: %s\n", j, envp[j]);
		j++;
	}
	return 0;
}

