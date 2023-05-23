#include <t_stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char *argv[]){
	//获取环境变量caption的值
	char * p = getenv("caption");
	if (p == NULL){
		printf("notfound ... \n");
	} else {
		printf("caption=%s\n", p);
	}
	//改变环境变量caption的值
	//如果环境变量不存在，将其天骄到环境变量列表中
	//如果环境变量不存在，需要看第三个参数的值
	//如果第三个参数的值为0，不改变环境变量的值
	//如果第三个参数的值不为0， 改变环境变量的值
	int ifzero = atoi(argv[1]);
	setenv("caption", "xian", ifzero);
	p = getenv("caption");
	if (p == NULL){
		printf("setenv not found ... \n");
	} else {
		printf("setenv caption=%s\n", p);
	}
	//删除环境变量，删除环境变量只要指定环境变量的名字即可
	unsetenv("caption");
	p = getenv("caption");
	if (p == NULL){
		printf("unsetenv not found ... \n");
	} else {
		printf("unsetenv caption=%s\n", p);
	}
	//清除环境变量
	clearenv();
	if (environ == NULL){
		printf("clear all...\n");
	}
	return 0;
}
