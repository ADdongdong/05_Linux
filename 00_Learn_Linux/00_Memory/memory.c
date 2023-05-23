#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(void){
	printf("pid:%d\n", getpid());
	char *str1 = "hello bejing";
	char *str2 = "hello bejing";
	char buf[32] = "hello bejing";
	char buf1[32];
	strcpy(buf1, "hello bejing");
	//问题，str1和str2是否指向同一个内容？
	printf("&str1=%p\n", &str1);
	printf("&str2=%p\n", &str2);
	//如果str1和str2这两个指针变量的地址应该是不同的。
	printf("str1=%p\n", str1);
	printf("str2=%p\n", str2);
	printf("buf1=%p\n",buf);
	printf("buf1=:%s\n", buf);
	//如果str1和str2的内容相同，说明这两个指针指向了统一地址。
	
	getchar();
	return 0;
}
