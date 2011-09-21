#include <stdio.h>
#include "socket.h"
#ifdef _WIN32
#include <WinSock.h>
#else
#include <linux/socket.h>
#include <unistd.h>
#endif
int main(int argc, char **argv)
{
	char hostname[256];
	int ret;
	struct hostent *hptr;
	char **ptr;
	int i;
	struct in_addr addr;
	addr.S_un.S_addr = inet_addr("127.0.0.1");
	printf("%s\n", inet_ntoa(addr));
	network_init();
	ret = network_gethostname(hostname, 256);
	if (ret == -1) {
		printf("Cannot get host name\n");
		return -1;
	}
	printf("Host Name = %s\n", hostname);
	hptr = gethostbyname("www.kimo.com.tw");
	if (hptr != NULL)
	{
		printf("%s\n", hptr->h_name);
		printf("Aliases\n");
		for (ptr = hptr->h_aliases; *ptr; ptr++)
			printf("%s\n", *ptr);
		printf("Address type: ");
		switch (hptr->h_addrtype) {
		case AF_INET:
			printf("AF_INET\n");
			break;
		case AF_NETBIOS:
			printf("AF_NETBIOS\n");
			break;
		default:
			printf(" %d\n", hptr->h_addrtype);
			break;
		}
		printf("\tAddress length: %d\n", hptr->h_length);

		i = 0;
		if (hptr->h_addrtype == AF_INET)
		{
			while (hptr->h_addr_list[i] != 0) {
				addr.s_addr = *(u_long *) hptr->h_addr_list[i++];
				printf("\tIP Address #%d: %s\n", i, inet_ntoa(addr));
			}
		}
		else if (hptr->h_addrtype == AF_NETBIOS)
		{   
			printf("NETBIOS address was returned\n");
		}   
	}
	
	network_shutdown();
	return 0;
}
