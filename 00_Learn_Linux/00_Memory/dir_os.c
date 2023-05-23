#include <sys/types.h>
#include <dirent.h>
#include <t_stdio.h>

int main(int argc, char *argv[]){
	//打开文件夹，文件夹的名字通过argv[1]传递给程序
	DIR *dir = opendir(argv[1]);
	if(dir == NULL){
		//如果文件夹打开失败，输出错误原因。
		perror("opendir");
		return -1;
	}
	printf("opendir success...\n");
	struct dirent *dirp;
	//遍历文件夹下的所有文件
	while((dirp = readdir(dir))!= NULL){
		printf("file:%s\tinode:%ld\n", dirp->d_name, dirp->d_ino);
	}
	
	//关闭文件夹流
	closedir(dir);
	return 0;
}
