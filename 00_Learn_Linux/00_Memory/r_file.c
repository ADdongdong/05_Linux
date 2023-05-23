#include <t_file.h>

int main(int argc, char* argv[]){
	//打开文件，以只读方式打开文件
	//文件名，通过argv[1]传递给程序
	int fd = open(argv[1], O_RDONLY);
	if (fd = -1){
		perror("open");
		return -1;
	}
	printf("file %s open succuss...\n", argv[1]);
	close(fd);
	return 0;
}
