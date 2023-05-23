#include <t_file.h>

int main(int argc, char* argv[]){
	int flags = O_WRONLY | O_CREAT | O_EXCL; //定义打开方式
	int mode = 0644;//定义创建文件赋予的权限
	int fd = open(argv[1], flags, mode);
	if (fd = -1){
		perror("open");
		return -1;
	}
	printf("file %s open succuss...\n", argv[1]);
	close(fd);
	return 0;
}
