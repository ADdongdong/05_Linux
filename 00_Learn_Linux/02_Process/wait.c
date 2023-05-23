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
		//这里传入了&s,传入了指针，s在wait函数中会被修改
		wait(&s);//这里有了wait以后，父进程始终会等回收了子进程的
				   //资源以后再继续执行父进程后面的代码
				   //这里就由异步变为同步的了
		if(WIFEXITED(s))//子进程正常终止，获取子进程退出状态码
			printf("exit code ...%d\n",WEXITSTATUS(s));
		if(WIFSIGNALED(s))//子进程被信号打断,获取信号的码
			printf("signum...%d\n", WTERMSIG(s));
		printf("parent process...%d\n", getpid());
	}
	return 0;
}
