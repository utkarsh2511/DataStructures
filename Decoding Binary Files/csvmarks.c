#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
	int fd, i = 0, j = 0, l, n = 0;
	char arr[100], str[20], strn[10];
	char *tok[10];
	fd = open(argv[1], O_RDONLY);
	if(fd == -1) {
		perror("open failed:\n");
		return errno;
	}
	while(i < strlen(argv[2])) {
		strn[i] = argv[2][i];	
		i++;
	}
	strn[i] = '\0';
	i = 0;	
	while(read(fd, &arr[i], 1))
		i++;
	arr[i] = '\0';
	j = 0;
	while(j < i) {
		if(arr[j] == '\n')
			n++;
		j++;
	}
	l = 0;
	while(n) { 
		i = 0;
		j = 0;
		while(arr[l] != '\n') {
			str[j] = arr[l];
			l++;
			j++;
		}
		l++;
		str[j] = '\0';
		char *token = strtok(str, ",");
		while(token != NULL) {
			j = 0;
			tok[i] = token;
			if(strcmp(tok[i], strn) == 0) {
				printf("%s\n", tok[i - 2]);
				}
			token = strtok(NULL, ",");
			i++;
		}
		n--;
	}
	return 0;
}
		
	
