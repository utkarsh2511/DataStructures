#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
int main(int argc, char *argv[]) {
	int fd = open(argv[1], O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR), n, i = 0;
	double x;
	if(fd == -1) {
		perror("open failed:\n");
		return errno;
	}
	read(fd, &n, sizeof(int));
	struct info {
		int id;
		char name[16];
		double score;
	}t[n];
	x = atof(argv[2]);
	while(i < n) {
		read(fd, &t[i], sizeof(t[i]));
		i++;
	}
	i = 0;
	while(i < n) {
		if(x == t[i].score) {
			printf("%d %s %lf\n", t[i].id, t[i].name, t[i].score);
		}
		i++;
	}
	return 0;
}
