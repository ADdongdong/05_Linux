#include <t_stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
 
int main(void){
	char *ps_envp[]	= {
		"name=tarena",
		"caption=beijing",
		NULL
	};
	char *ps_argv[] = {
		"t_env",
		NULL
	};
	//创建子进程
	pid_t pid = fork();
	if (pid == -1){
		perror("fork");
		return -1;
	}
	if (pid == 0){
		printf("child process...\n");
		//更新进程的映像
		//查看当前进程的环境变量
		//使用自定义的环境变量列表，替换从父进程继承的环境变量列表
		execve("./t_env", ps_argv, ps_envp);
		//只有exec(3)家族函数执行的失败的时候，才会执行到的代码
		perror("execle");
		exit(0);
	}else{
		wait(NULL);
	}
	return 0;
}
