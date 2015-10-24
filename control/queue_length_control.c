#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096

#define MY_CORE_NUMBER 8
#define MAX_LOOP 10000

int main ( int argc, char **argv )
{
	int configfd;
	int *pids;	
	char * address = NULL;
	int cid, pid;
	int i;

	if (argc != 3) {
		printf("need cid pid\n");
		return;
	}

	cid = atoi(argv[1]);
	pid = atoi(argv[2]);

	configfd = open("/sys/kernel/debug/queue_length", O_RDWR);
	if(configfd < 0) {
		perror("open");
		return -1;
	}

	address = mmap(NULL, PAGE_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, configfd, 0);
	if (address == MAP_FAILED) {
		perror("mmap");
		return -1;
	}

	pids = (int *)address;

	for (i = 0; i < MAX_LOOP; i++) {
	
		while (pids[cid] != -1)
			printf("Waiting for Kernel\n");

		pids[cid] = pid;
		printf("New Pid[%d] :%d\n", cid, pids[cid]);
		
	}
	close(configfd);	
	return 0;
}

