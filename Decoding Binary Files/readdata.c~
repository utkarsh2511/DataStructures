#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
int main(int argc, char *argv[]) {
	int n, m, p, i = 0, q;
	char arr;
	int fd = open(argv[1], O_RDONLY, S_IRUSR | S_IWUSR);
	if(fd == -1) {
		perror("open failed:\n");
		return errno;
	}
	read(fd, &n, sizeof(int));
	while(i < n) {
		read(fd, &q, sizeof(int));
		printf("%d\n", q);
		i++;
	}
	read(fd, &m, sizeof(int));
	struct data {
		int age;
		char name[16];
	}t[m];
	i = 0;
	while(i < m) {
		read(fd, &t[i], sizeof(t[i]));
		printf("%d %s \n", t[i].age, t[i].name);
		i++;
	}
	read(fd, &p, sizeof(int));
	i = 0;
	q = 0;
	while( q < p) {
		read(fd, &arr, sizeof(char));
		printf("%c", arr);
		while(arr != '\0') {
			read(fd, &arr, sizeof(char));
			if(arr != '\0')
				printf("%c", arr);
			else
				break;
		}
		printf("\n");
		q++;
		i = 0;
	}
	close(fd);
	return 0;
}


		




