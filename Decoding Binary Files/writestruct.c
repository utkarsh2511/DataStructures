#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
int main(int argc, char *argv[] ) {
	int n, i = 0, fd;
	scanf("%d", &n);
	struct info {
		int id;
		char name[16];
		double score;
	}t[n];
	while(i < n) {
		scanf("%d%s%lf", &t[i].id, t[i].name, &t[i].score);
		i++;
	}
	fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	if(fd == -1) {
		perror("open failed:");
		return errno;
	}
	i = 0;
	write(fd, &n, sizeof(int));
	while(i < n) {
		write(fd, &t[i], sizeof(t[i]));
		i++;
	}
	close(fd);
	return 0;
}
	
