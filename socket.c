#ifdef _WIN32
#include <Winsock2.h>
#pragma comment(lib, "Ws2_32.lib")
#else
#include <linux/socket.h>
#include <unistd.h>
#endif
void network_init()
{
#ifdef _WIN32
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif
}
void network_shutdown()
{
#ifdef _WIN32
	WSACleanup();
#endif
}
