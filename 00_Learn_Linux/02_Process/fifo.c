#include <t_stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]){
	//创建管道类型的文件
	//argv[1]指定要创建管道类型文件的名字
	//0644 指定管道文件的权限
	int ff = mkfifo(argv[1],0644);
	if (ff == -1){
		perror("mkfifo");
		return -1;
	}
	printf("file %s success creat\n",argv[1]);
	return 0;
}
