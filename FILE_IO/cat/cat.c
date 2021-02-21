#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024
int fd , ret ;
char buffer[BUFFER_SIZE]; 

int main(int argc , char *argv[]){	
	if(argc == 1){
		printf("Please proide the file to Read\n");
		exit(1);
	}

	for(int i = 1; i < argc;i++){
		
		fd = open(argv[i],O_RDWR);
		if(fd < 0){
			printf("Not able to open the file becuase of the following Reason\n 1. file does not exist\n 2. You do not have permission to open the file\n");
			exit(1);
		}

		printf("**********************************\n");
		printf("-------- %s ---------\n",argv[i]);
		printf("**********************************\n");
		memset(buffer,0,sizeof(buffer));

		while(ret = read(fd,buffer,BUFFER_SIZE) != 0){
			write(1,buffer,sizeof(buffer));
		}
		printf("\n");
		close(fd);
	}
	return 0;
}
