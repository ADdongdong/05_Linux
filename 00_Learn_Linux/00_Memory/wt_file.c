#include <t_file.h>

int main(int argc, char* argv[]){
	//打开文件，以写方式打开文件
	//文件不存在时候，创建文件
	//指定新建文件的权限为0644
	//如果文件存在，将文件内容清空
	//文件名，通过argv[1]传递给程序
	int flags = O_WRONLY | O_CREAT | O_TRUNC; //定义打开方式
	//8进制数字的前面得有个0，代表这个数字是8进制
	//文件的权限有3个8进制数字构成。
	//每个8进制数表示rwx:读写指向三种权限，
	//这个文件的那个所有这有那个权限就给哪个权限的位置设置为1
	//644->110 100 100
	//前三个数字是文件所有者拥有的权限 读写
	//第二个数字是文件所有组拥有的权限 读
	//第三个数字是其他用户所拥有的权限 读
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
