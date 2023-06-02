#include <stdio.h>
#include <string.h>
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
	int shmid = shmget(key, 1024, IPC_CREAT|0644);
	if(shmid == -1){
		perror("shmget");
		return -1;
	}
	printf("shmid:%d\n", shmid);
	//使用共享内存段的id,将共享内存段关联到进程的地址空间
	void *p = shmat(shmid, NULL, 0);
	if (p == (void *)-1){
		perror("shmat");
		return -1;
	}
	//使用共享内存段,将hello xian写入到共享内存段中，
	//共享内存段在内核中, 不会随着进程的结束而结束
	strcpy(p, "hello xian\n");
	printf("%s", (char *)p);
	getchar();
	//不使用的时候，解除关联
	shmdt(p);
	return 0;
}
