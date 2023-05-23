#include <t_stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	//使用put_env添加环境变量
	char buf[128] = "name=headong";
	putenv(buf);
	char *p = getenv("name");
	if (p == NULL){
		printf("not found...\n");
	} else {
		printf("%s\n", p);
	}
	strcpy(buf, "name=xiaodousha");
	if (p == NULL){
		printf("buf not found ...\n");
	}else{
		printf("buf:%s\n", p);
	}
	return 0;
}
