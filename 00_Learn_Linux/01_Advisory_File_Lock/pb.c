#include <stdio.h>
#include <t_file.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	printf("pid:%d\n", getpid());
	struct flock lock;
	//设置锁结构体的成员
	lock.l_type = F_WRLCK;//加锁的类型
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;//从文件开头开始
	lock.l_len = 6;//加锁的长度
	//打开文件，以只写的方式打开
	int fd = open(argv[1], O_RDWR);
	if(fd == -1){
		perror("open");
		return -1;
	}	
	//对指定文件加读锁
	int f = fcntl(fd, F_SETLK, &lock);
	if (f == -1){
		perror("fcntl");
		return -1;
	}
	//加读锁成功
	printf("read lock success ...\n"); 
	//关闭文件 
	getchar();
	//让进程在这里中断，而不去终止进程，防止锁被解除	 //关闭文件描述符的时候，所有的记录锁都被移除 
	close(fd); 
	printf("释放文件锁 ... \n");
	return 0;
}
