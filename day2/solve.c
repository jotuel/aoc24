#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

static void count_and_print(int *arr[1000][8]) {
	int i = 0;
	int i1 = 0;
	int safe = 0;
	while(i < 1000) {
		if(arr[i][i1] > arr[i][i1 + 1]) {
			while(arr[i][i1] - 1 >= arr[i][i1 + 1] && arr[i][i1] - 2 <= arr[i][i1 + 1] && i1 < 8)
				i1++;
			if(arr[i][i1 + 1] == 0) {
				safe++;
			}
		i1 = 0;
		i++;
		} else {
			while(arr[i][i1] + 1 <= arr[i][i1 + 1] && arr[i][i1] + 2 <= arr[i][i1 + 1] && i1 < 8)
				i1++;
			if(arr[i][i1 + 1] == 0) {
				safe++;
			}
		i1 = 0;
		i++;
		}
	}
	printf("%d\n", *(arr[500][5]));
	printf("%d\n", safe);
}

static void arraylize(int fd, int *arr[1000][8]) {
	char buf;
	char nbr[3];
	int i = 0;
	int i1 = 0;

	nbr[1] = '\0';
	nbr[2] = '\0';
	while(read(fd, &buf, 1)) {
		if(isalnum(buf)) {
			nbr[0] = buf;
			if(read(fd, &buf, 1)) {
				if(isalnum(buf)) {
					nbr[1] = buf;
				} else {
					nbr[1] = '\0';
				}
			} else {
			nbr[1] = '\0';
			}
			*arr[i][i1] = atoi(nbr);
			i1++;
		}
		if (buf == '\n') {
			i++;
			i1 = 0;
		} else if (buf == ' ') {
			nbr[0] = '\0';
		}
	}
}

int main(int argc, char **argv) {
	if(argc != 2)
		return (-1);
	int fd = open(argv[1], O_RDONLY);
	if(fd < 1) {
		write(1, "error\n", 7);
		return (-1);
	}
	int	 *arr[1000][8];

	arraylize(fd, arr);
	count_and_print(arr);
}
