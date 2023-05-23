#include <t_stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void){
	pid_t pid = fork();
	if (pid == -1){
		perror("fork");
		return -1;
	}
	if (pid == 0){
		exit(0);//子进程终止
	}else{
		getchar();
		wait(NULL);
	}
	return 0;
}
