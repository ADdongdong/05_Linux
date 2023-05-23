#include <t_stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char *argv[]){
	//使用atoi(3)将命令行的参数转换为整数类型
	//向argv[2]这个进程发送argv[1]这个信号
	//其实和shell中的kill命令是一样的
	kill(atoi(argv[2]),atoi(argv[1]));
	return 0;
}
