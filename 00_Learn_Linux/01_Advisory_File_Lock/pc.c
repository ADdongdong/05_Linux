#include <t_stdio.h>
#include <t_file.h>

int main(int argc, char* argv[1]){
	struct flock lock;
	//打开文件，以读写方式打开文件
	int fd = open(argv[1], O_RDWR);
	if (fd == -1){
		perror("open");
		return -1;
	}
	//对flock结构体的成员进行初始化
	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 6;
	//测试是否可以加读锁
	int cnt = fcntl(fd, F_GETLK, &lock);
	if (cnt == -1){
		perror("fcntl");
		return -1;
	}
	if (lock.l_type == F_UNLCK)
		printf("可以加读锁...\n");
	else//不可以加读锁
		printf("pid == %d\n",lock.l_pid);
		//lock.l_pid存放的是和当前进程互斥的进程的pid	

	//关闭文件描述符,文件描述符上的所有记录锁都被移除
	close(fd);
	return 0;
}
