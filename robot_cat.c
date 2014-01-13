

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>


#define	BUFSIZE	4096

int main(int argc, char *argv[]){
	FILE	*fp;
	char	usrbuf[BUFSIZE];
	char	catbuf[BUFSIZE];
	int	nread, i;
	char	*p;
	char	*usrname = "小白呵呵";

	if((fp = fopen("robot_cat.dat", "r")) == NULL){
		fprintf(stderr ,"open robot_cat.dat error: %s\n", strerror(errno));
		return 1;
	}

	printf("机器小猫开始跟你说话......\n%s: ", usrname);
	while(fgets(usrbuf, BUFSIZE, stdin) != NULL){	//读入用户说的话
		rewind(fp);	//返回文件开始
		nread = strlen(usrbuf) - 1;
		if(nread >= (BUFSIZE - 2)){
			fputs("你说话太长了。。。。。\n请重新开始。。。\n", stderr);
			goto again;
		}
		while(1){
			if(fgets(catbuf, BUFSIZE, fp) != NULL){
				if(catbuf[0] != ':'){
					fputs("对话文件出现错误，跳过。。。\n", stderr);
					continue;
				}
				if(strncmp(&catbuf[1], usrbuf, nread) == 0){//找到了对应的话
					p = strchr(&catbuf[1], ':');
					if(p == NULL)
						printf("机器小猫（沉默）\n");
					else
						printf("机器小猫: %s", p+1);
					break;
				}
			}else{
				printf("机器小猫不知道要说什么......\n");
				break;
			}
		}
again:
		printf("%s: ", usrname);
	}
	return 0;
}




