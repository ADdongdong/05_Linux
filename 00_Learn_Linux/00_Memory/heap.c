#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	printf("pid:%d\n", getpid());
	char *p;
	p = (char *)malloc(1024);
	printf("&p=%p\n", &p);
	//查看p这个指针变量存在那个位置，也就是指针变量的地址
	printf("p=%p\n",p);
	//查看p这个指针变量保存的地址是哪里，也就是我们通过malloc分配的空间在哪里
	strcpy(p, "hello xian");
	printf("before free p:%s\n", p);
	free(p);
	p = NULL;//将释放的空间设置为空
	//printf("after free:%s\n", p);
	getchar();
	return 0;
}

