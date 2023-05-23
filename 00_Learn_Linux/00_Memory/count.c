#include <stdio.h>
#include <unistd.h>

int g_val=300;
void count(void){
    static int val = 1;
	printf("val++=%d\n", val++);
	printf("&val=%p\n", &val);
	return ;
}

int main(void){
	printf("pid:%d\n", getpid());
	int i;
	for (i = 0; i < 5; i++)
		count();	
	printf("&g_val=%p\n", &g_val);
	getchar();
	return 0;
}
