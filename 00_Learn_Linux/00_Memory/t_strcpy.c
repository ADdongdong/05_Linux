#include <stdio.h>

//这个函数返回值是char*,所以，是可以在函数中嵌套调用的
char *t_strcpy(char *dest, const char *src){
	int i;
	//如果，没有遇到\0说明字符串还没有结束，继续拷贝
	for (i = 0; src[i]!='\0';i++){
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return dest;
}

int main(void){
	char buf[32];
	char *msg="hello xian";
	//t_strcpy(buf, msg);
	printf("buff:%s\n",t_strcpy(buf, msg));
	return 0;
}
