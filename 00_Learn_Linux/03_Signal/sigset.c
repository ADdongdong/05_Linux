#include <stdio.h>
#include <signal.h>

int main(void){
	//定义信号集类型的变量set
	sigset_t set;
	//初始化信号集set为空
	sigemptyset(&set);
	//将2号信号添加到信号集set中
	sigaddset(&set,2);
	sigaddset(&set,3);
	//测试3号信号是不是信号集中的一员
	int is = sigismember(&set,3);
	if (is == -1){
		perror("sigismember");
		return -1;
	}
	if (is == 1){
		printf("signum 3 is member of set...\n");
	} else{
		printf("signum 3 is not member of set...\n");
	}
	//将3号信号从信号集中移除
	sigdelset(&set, 3);
	is = sigismember(&set,3);
	if (is == -1){
		perror("sigismember");
		return -1;
	} 
	if (is == 1){
		printf("del signum 3 is member of set...\n");
	} else{
		printf("del signum 3 is not member of set...\n");
	}
	return 0;
}
