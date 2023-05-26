#include <stdio.h>
#include <signal.h>
#include <unistd.h>

unsigned int t_sleep(unsigned int seconds){
	alarm(seconds);
	pause();//进程对信号忽略了，是否还能打断pause(2)
	return alarm(0);//取消原来的闹钟
					//返回未决时间值
}

//定义信号处理函数,这个函数是个空函数
void handler(int n){}

int main(void){
	//不能忽SIGALRM信号
	//signal(SIGALRM, SIG_IGN);
	signal(SIGALRM, handler);
	while(1){
		t_sleep(2);
		printf("你好...\n");
	}
	return 0;
}
