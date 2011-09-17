#include <linux/socket.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	char hostname[256];
	int ret = gethostname(hostname, 256);
	if (ret == -1) {
		printf("Cannot get host name\n");
		return -1;
	}
	printf("Host Name = %s\n", hostname);
	return 0;
}
