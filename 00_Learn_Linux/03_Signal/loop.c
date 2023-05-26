#include <stdio.h>
#include <unistd.h>
#include <signal.h>

//用户自定义的信号处理函数
void handle(int n){
	//参数n是信号的编号
	printf("recv...%d\n", n);
	return;
}
int main(void){
	//从父进程继承了信号处理函数
	//采用默认处理方式，所以，按下Ctrl+c会发送终止信号
	signal(2, SIG_IGN);//改变进程对2号信号的处理函数，
					   //改为忽略2号信号
	signal(3, handle);//改变进程对3号信号的处理函数，
					   //改为忽略3号信号
	signal(9, SIG_IGN);//改变进程对9号信号的处理函数，
					   //改为忽略9号信号
					   //注意：9号信号是不能忽略，不能阻塞的
	pid_t pid = fork();
	if (pid == -1){
		perror("fork");
		return -1;
	}
	while(1);
	return 0;
}
