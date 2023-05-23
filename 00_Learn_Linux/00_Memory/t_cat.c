#include <t_file.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int r,w;
	char buf[128];//定义缓冲区
	//从argv[1]中读取文件
	int des_file = open(argv[1], O_RDONLY);
	if (des_file == -1){
		perror("open");
		return -1;
	}
	//将读取到的文件写入到标准输出中
	while ((r = read(des_file, buf, 128))>0){
		char *tmp = buf;
		while (r > 0){
			w = write(0, tmp, r);
			r = r-w;
			tmp+=w;
		}
	}

	close(des_file);
	return 0;
}
