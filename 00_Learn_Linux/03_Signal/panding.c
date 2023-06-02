#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(void){
	//定义信号集类型的变量set
	sigset_t set, pset;
	//初始化信号集set为空
	sigemptyset(&set);
	//将2号信号添加到信号集set中
	sigaddset(&set, 2);
	//将set设置为进程的信号掩码集
	//第一个参数:how SIG_BLOCK
	//将set信号集和原来的信号集做并集操作，
	//结果设置为进程信号的掩码集
	int sm = sigprocmask(SIG_BLOCK,&set, NULL);
	if (sm == -1){
		perror("mask");
		return -1;
	}
	while(1){
		sleep(1);
		//获取进程的未决信号集,pset中存放的是进程的未决信号集
		sigpending(&pset);
		//使用sigismember函数，测试2号信号是不是pset中的一员
		int is = sigismember(&pset, 2);
		if (is == -1){
			perror("sigismember");
			return -1;
		}
		//三目运算符如果is为1打印yes否则打印no 
		is?printf("yes\n"):printf("no\n");
	}
	return 0;
}
