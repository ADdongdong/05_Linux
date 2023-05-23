#include <stdio.h>
#include <t_stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void){
	pid_t pid = fork();
	if (pid == -1){
		perror("fork");
		return -1;
	}
	if (pid ==0){
	//子进程执行的代码
		//父进程没有结束，打印子进程的父进程
		printf("父进程结束前子进程父进程的pid...%d\n", getppid());
		//打印子进程的pid
		printf("child process id...%d\n", getpid());
		sleep(10);
		//父进程结束以后，打印子进程的父进程
		printf("父进程结束，子进程还未结束，子进程的父进程的pid（孤儿院)...%d\n", getppid());
	}else{
	//父进程执行的代码
		sleep(1);
		printf("parent ...%d\n", getpid());
	}
	return 0;
}
