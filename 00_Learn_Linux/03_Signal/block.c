#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void handle(int n){
	printf("recv...%d\n", n);
}

int main(void){
	signal(2, handle);//改变收到信号时候的处理函数
	signal(3, handle);//改变收到信号时候的处理函数
	signal(45, handle);//改变收到信号时候的处理函数
	//定义信号集类型的变量
	sigset_t set, oset;
	//初始化信号集set为空
	sigemptyset(&set);
	//将2,3,9信号添加到set集合中
	//信号集其实本质上就是一个位数组，每个元素都只能取0或1
	//将信号添加到信号集，比如添加2号信号，
	//就是将index的元素设置为1
	sigaddset(&set,2);
	sigaddset(&set,3);
	sigaddset(&set,45);
	//将信号集set设置为进程的信号掩码集
	//这里的【信号掩码集】就是阻塞信号集

	//参数一：how SIG_SETMASK 将信号集设置为进程的信号掩码集
	//参数二：指定具体的信号集
	//参数三：oldset 用于保存原来的信号集。如果设置为NULL,
	//        表示不保存原来的信号集。
	int sm = sigprocmask(SIG_SETMASK, &set, &oset);
	if (sm == -1){
		perror("sigprocmask");
		return -1;
	}
	//while(1);
	sleep(30);
	
	//恢复原来的信号掩码集
	sm = sigprocmask(SIG_SETMASK, &oset, NULL);
	while(1);//这时候发送2,3信号，就不会被阻塞了

	return 0;
}
