#include <t_stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
 
int main(void){
	char *ps_argv[] = {"ps", "-o", "pid,ppid,pgrp,comm", NULL};
	//创建子进程
	pid_t pid = fork();
	if (pid == -1){
		perror("fork");
		return -1;
	}
	if (pid == 0){
		printf("child process...\n");
		//更新进程的映像
		//execlp("/usr/bin/ps", "ps", "-o", "pid,ppid,pgrp,comm", NULL);
		execvp("ps", ps_argv);
		//只有exec(3)家族函数执行的失败的时候，才会执行到的代码
		perror("execvp");
		exit(0);
	}else{
		wait(NULL);
	}
	return 0;
}
