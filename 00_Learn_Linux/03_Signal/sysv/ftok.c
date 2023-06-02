#include <stdio.h>
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
	return 0;
}
