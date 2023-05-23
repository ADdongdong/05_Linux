#include <stdio.h>
#include <t_stdio.h>
#include <unistd.h>
#include <stdlib.h>

//遗言函数的定义
void fun1(int n, void *arg){
	printf("fun1..%d...%s\n", n, (char*)arg);
	return;
}

void fun2(int n, void *arg){
	printf("fun2..%d...%s\n", n, (char*)arg);
	return;
}

void fun3(int n, void *arg){
	printf("fun3..%d...%s\n", n, (char*)arg);
	return;
}

int main(int argc, char* argv[1]){
	//向进程注册遗言函数
	on_exit(fun1, argv[1]);
	on_exit(fun2, argv[1]);
	on_exit(fun3, argv[1]);
	pid_t pid = fork();
	if(pid ==-1){
		perror("fork");
		return -1;
	}
	sleep(2);
	return -1;
}
