#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(void){
	alarm(5);
	int i;
	for (i = 1; i<700000; i++)
		printf("i=%d\n", i);
	int a = alarm(0);//取消原来的闹钟,
					 //变量a中存放的是原来闹钟的未决时间值
	printf("a=%d\n", a);
	return 0;
}
