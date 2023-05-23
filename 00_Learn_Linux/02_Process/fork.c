#include <t_stdio.h>
#include <unistd.h>

int main(void){
	pid_t pid;
	//在父进程中创建一个子进程
	pid = fork();
	if (pid == -1){
		perror("fork");
		return -1;
	}
	if (pid ==0){
	//子进程执行到的代码,如果fork返回值为0,
	//说明在子进程中，因为我们就是用fork的返回值来区分子进程和父进程的
		printf("child process...\n");
	}else{
	//父进程执行到的代码,如果fork的返回值不为0,说明在父进程中
	//返回的这个非零的整数是子进程的pid
		printf("parent process...\n");
	}
	//父进程和子进程都能执行到的代码
	printf("all ok...\n");
	return 0;
}

