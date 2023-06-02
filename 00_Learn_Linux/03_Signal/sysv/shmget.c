#include <stdio.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main(int argc, char *argv[]){
	//获取system v ipc的一个键值
	key_t key = ftok(argv[1], 31);
	if (key == -1){
		perror("ftok");
		return -1;
	}
	printf("key:0x%x\n", key);
	//使用key值获取共享内存段的id
	//如果共享内存段不存在，我们会创建共享内存段，并将权限设置为0644
	//如果共享内存段存在，直接报错
	int shmid = shmget(key, 1024, IPC_CREAT|IPC_EXCL|0644);
	if(shmid == -1){
		perror("shmget");
		return -1;
	}
	printf("shmid:%d\n", shmid);
	return 0;
}
