#include <stdio.h>
#include "socket.h"
int main(int argc, char **argv)
{
	network_init();
	char hostname[256];
	int ret = gethostname(hostname, 256);
	if (ret == -1) {
		printf("Cannot get host name\n");
		return -1;
	}
	printf("Host Name = %s\n", hostname);
	network_shutdown();
	return 0;
}
