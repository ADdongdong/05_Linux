#include <t_stdio.h>
#include <string.h>
#include <t_file.h>

int main(int argc, char *argv[]){
	const char *msg = argv[2]; 
	int fd = open(argv[1], O_WRONLY); 
	if (fd == -1){
		perror("open");
		return -1;
	}
	//向管道中写入数据
	write(fd, msg, strlen(msg));
	//在数据结尾加上\n换行符
	write(fd, "\n", 1);
	//关闭文件描述符
	close(fd);
	return 0;
}
