#include <t_stdio.h>
#include <t_file.h>
#include <string.h>

int main(int argc, char *argv[]){
	char buf[128];
	//打开文件，以只读的方式打开文件
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1){
		perror("open");
		return -1;
	}
	int r = read(fd, buf, 128);
	write(1, buf, r);
	close(fd);
	return 0;
}
