#include <t_stdio.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	struct stat buf;
	//获取文件的元数据
	int s = stat(argv[1], &buf);
	if (s == -1){
		//错误处理perror打印错误信息，并返回-1
		perror("stat");
		return -1;
	}
	//到这里就已经获取到文件的元数据了
	//已经将文件的元数据存放到buf的空间里了
	printf("file size:%ld\n",buf.st_size);
	//访问st_nlink获得文件的硬链接数量
	printf("link:%lu\n", buf.st_nlink);
	//获取问价的inode,inode就是文件的唯一编号，
	//可以通过文件的inode对文件的元数据进行操作
	printf("inode:%lu\n", buf.st_ino);
	//这里st_size为long int，所以前面是%ld
	
	printf("uid:%u\n", buf.st_uid);
	struct passwd *p = getpwuid(buf.st_uid);
	printf("username:%s\n",p->pw_name);
	printf("group name:%s\n", (getgrgid(buf.st_gid))->gr_name);
	printf("gid:%d\n", buf.st_gid);
	printf("modi time:%ld\n", buf.st_mtim.tv_sec);
	printf("modi time:%s", ctime(&buf.st_mtim.tv_sec));
	printf("mode:%o\n",buf.st_mode );
#if 0
	if(S_ISREG(buf.st_mode))printf("-");
	if(S_ISDIR(buf.st_mode))printf("d");
#endif
	switch (buf.st_mode & S_IFMT){
		case S_IFREG:
			printf("-");
			break;
		case S_IFDIR:
			printf("d");
			break;
		default:
			break;
	}
	//权限的处理
	((buf.st_mode & S_IRWXU) & S_IRUSR) ? printf("r"):printf("-");
	((buf.st_mode & S_IRWXU) & S_IWUSR) ? printf("w"):printf("-");
	((buf.st_mode & S_IRWXU) & S_IXUSR) ? printf("x"):printf("-");
	printf("\n");
	return 0;
}
