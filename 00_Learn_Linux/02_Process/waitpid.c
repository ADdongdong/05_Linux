#include <t_stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	int s;
	//创建子进程
	pid_t pid = fork();
	if (pid == -1){
		perror("fork");
		return -1;
	}
	if (pid ==0){
	//这是子进程的内容
		printf("child process...%d\n", getpid());
		getchar();
		exit(-1);
	}else{
	//这是父进程的内容
	//父进程阻塞等待回收子进程的资源
		//父进程回收子进程资源，并且设置为非阻塞WNOHANG
		int w = waitpid(-1,&s,WNOHANG);
		if (w == 0 ){
			printf("parent exit...\n目前没有子进程终止\n");
			return 0;//如果w为0,说明没有子进程的终止
		}			
		if(WIFEXITED(s))//子进程正常终止，获取子进程退出状态码
			printf("exit code ...%d\n",WEXITSTATUS(s));
		if(WIFSIGNALED(s))//子进程被信号打断,获取信号的码
			printf("signum...%d\n", WTERMSIG(s));
		printf("parent process...%d\n", getpid());
	}
	return 0;
}
