#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
int main() {
	int fd = open("decodeme", O_RDONLY);
	int i = 0,  j = 0;
 	int a;
	char ch;
	read(fd, &a, sizeof(int));
	printf("%d\n", a);
	while(i < 22) {
		read(fd, &ch, 1);
		printf("%c\n", ch);
		i++;
	}
	read(fd, &a, sizeof(int));
	printf("%d\n", a);
	i = 0;
	while(i < 3){
		read(fd, &ch, 1);
		printf("%c\n", ch);
		i++;
	}
	read(fd, &a, 1);
	printf("%d\n", a);
	i = 0;
	read(fd, &a, 4);
	printf("%d\n", a);	
	i = 0;
	while(i < 10){
		read(fd, &ch, 1);
		printf("%c\n", ch);
		i++;
	}
	while(j < 5){
		read(fd, &a, sizeof(int));
		printf("%d\n", a);
		i = 0;
		while(i < 28){
			read(fd, &ch, 1);
			printf("%c\n", ch);
			i++;
		}	
		i = 0;
		while(i < 2){
			read(fd, &a, 4);
			printf("%d\n", a);
			i++;
		}
		i = 0;
		while(i < 8){
			read(fd, &ch, 1);
			printf("%c\n", ch);
			i++;
		}
		j++;
	}
	close(fd);
	return 0;
}
	
