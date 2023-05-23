#include <t_stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void){
	char buf[128];
	char *msg = "this is a test\n";
	//1.创建管道 fd[0] 指向管道的读端 fd[1] 指向管道的写端 
	int fd[2];
	//2.创建子进程，子进程继承父进程的文件描述符
	int pp = pipe(fd);
	if (pp == -1){
		perror("pipe");
		return -1;
	}
	pid_t pid = fork();
	if (pid == -1){
		perror("fork");
		return -1;
	}

	if (pid == 0 ){
	//父进程负责的任务
		close(fd[1]);//关闭管道的写端
		//从管道中读取数据到buf中
		//如果管道没有数据，阻塞等待
		int r = read(fd[0], buf, 128);
		write(1, buf, r);
		//关闭管道读端
		close(fd[0]);
		exit(0);//进程终止
	}else{
	//父进程负责的任务
		//关闭管道的读端
		close(fd[0]);
		//向管道写入数据
		write(fd[1], msg, strlen(msg));
		close(fd[1]);//关闭写端
		wait(NULL);//父进程回收子进程的资源
				   //阻塞等待子进程的结束
	}
	return 0;
}
