#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LOOP 100000000L

int main(int argc, char *argv[]) {
	char *msg;
	long i, count = 0;

	if (argc != 2) {
		printf("Usage: %s\n", argv[0]);
		exit(1);
	}
	
	msg = argv[1]; 	

	while (1) {
		for (i = 0; i < MAX_LOOP; i++);
			
		count++;
		printf("%s : %ld\n", msg, count);
	}
	
	return 0;
}
