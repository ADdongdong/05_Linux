#include <stdio.h>
#include <t_stdio.h>
//#include <errno.h>
//#include <string.h>

int main(int argc, char *argv[]){
	FILE *fp = fopen(argv[1], "r");//使用fopen打开文件
	if (fp == NULL){
#if 0
		errno = -1;
		//errno是errno.h文件中的全局变量，当打开文件失败的时候，
		//这个全局变量会被自动改写
		printf("fopen failed...%d\n", errno);
		//strerror()函数可以根据全局变量errno来输出
		//这errno对应的具体错误信息，以字符串形式
		printf("fopen failed...%s\n", strerror(errno));
		perror("fopen");
		return -1;
#endif
		E_MSG("fopen", -1);
	}
	printf("fopen success... \n");
	fclose(fp);
	return 0;
}
