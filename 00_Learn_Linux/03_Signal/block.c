#include <signal.h>
#include <stdio.h>

int main(void){
	//定义信号集类型的变量
	sigset_t set;
	//初始化信号集set为空
	sigemptyset(&set);
	//将2,3,9信号天剑到set集合中
	sigaddset(&set,2);
	sigaddset(&set,3);
	sigaddset(&set,9);
	//将信号集set设置为进程的信号掩码集
	
	return 0;
}
