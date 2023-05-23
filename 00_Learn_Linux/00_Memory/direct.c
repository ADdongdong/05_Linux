#include <t_file.h>
#include <string.h>
#include <stdio.h>

//重定向的文件名通过argv[1]这个参数传递给进程
int main(int argc, char *argv[]){
	char *msg = "this is a test...\n";
	//0 1 2
	//文件以写的方式打开，文件不存在，就创建文件，0644
	//文件存在，将文件的内容清空
	int flags = O_WRONLY | O_CREAT | O_TRUNC;
	int fd = open(argv[1], flags, 0644);
	if (fd ==-1){
		perror("open");
		return -1;
	}

	//使用dup将标准输出的文件描述符表项保存到
	//文件描述符4所在别的表项
	int s_fd = dup(1); // s_fd == 4

	//将文件描述符3(也就是打开文件的文件描述符)
	//中的内容拷贝到文件描述符1中
	dup2(fd, 1);

	//关闭文件描述符3,这样只有1指向了我们打开的文件
	//关闭文件描述符
	close(fd);

	//通过标准输出，将信息输出到我们指定的文件
	write(1,msg, strlen(msg));

	//恢复原来的标准输出,重新指向显示器
	dup2(s_fd, 1);

	//再次打印消息进行测试,这时候就应该写入到显示器中了
	write(1, msg, strlen(msg));
	return 0;
}
