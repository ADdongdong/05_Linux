#include <stdio.h>
#include <unistd.h>

extern char **environ;//变量的声明，只是作用域的扩充
int main(){
	int i;
	for (i = 0; environ[i]!=NULL; i++){
		printf("%s\n", environ[i]);
	}
	return 0;
}
