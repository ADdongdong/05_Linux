#include <t_file.h>
#include <t_stdio.h>

int cp_file(int src_fd,int des_fd){
//定义从src_fd文件将文件内容写入到des_fd文件的函数
	int r,w;
	int total;
	char buf[128];//创建一个能存放128个char的缓冲区
	while ((r=read(src_fd, buf, 128))>0){
		char *tmp = buf;
		while(r>0){
		//当读取到的字符数量大于0的时候才进行写入操作
			w=write(des_fd, tmp, r);
			r = r-w;
			total+=w;
			tmp+=w;
		}
	}
	return total;
}
int main(int argc, char *argv[2]){
	int src_fd = open(argv[1], O_RDONLY);//以只读的方式读取
	//读取目标文件，以可写的方式读取，
	//如果，该文件中有内容就清空该文件中的内容
	//且如果是创建这个文件，则让这个文件的访问控制权设置为0644
	int flags = O_WRONLY | O_CREAT | O_TRUNC;
	int des_fd = open(argv[2], flags, 0644);
	//判断这两个文件是否都读取/创建成功了
	//如果没有成功，返回错误信息
	if (src_fd == -1 | des_fd == -1){
		perror("open:");
		return -1;//终止程序，返回-1
	}
	//现在将src_fd中的内容拷贝到dest_fd中
	cp_file(src_fd, des_fd);
	//关闭两个文件
	close(src_fd);
	close(des_fd);
	return 0;
}
