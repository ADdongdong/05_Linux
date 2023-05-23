#include <stdio.h>
#include <t_stdio.h>
#include <stdlib.h>
#include <unistd.h>

//进程的遗言函数
void fun1(void){
	printf("fun1...\n");
	return;
}
//进程的遗言函数goodbye
void fun2(void){
	printf("fun2...\n");
	return;
}
void fun3(void){
	printf("fun3...\n");
	return;
}

int main(void){
	//向进程注册遗言函数
	atexit(fun1);
	atexit(fun2);
	atexit(fun3);
	//创建子进程
	pid_t pid= fork();
	if(pid == -1){
		perror("fork");
		return -1;
	}
	sleep(2);
	/*
	 * 自进程继承父进程的遗言函数，遗言函数是先注册，
	 * 注册几次，调用几次,且先注册的遗言函数后进行调用
	 */
		 
	
	if (pid == 0){
	//这是子进程
		printf("我是子进程\n");
	}else{
	//这是父进程
		printf("我是父进程\n");
	}
	return 0;
}
