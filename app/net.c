#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include "net.h"


int Sock_Fd[sock_All];
int Sock_Send_Buff[sock_All][SockBuffLen];
int Sock_Recv_Buff[sock_All][SockBuffLen];

const int Port[sock_All] = {
	PORT_1,
	PORT_2
};

int Net_Function_Init()
{
	struct sockaddr_in netsock;
	int on = 1;
	int Buff = SockBuffLen;
	int i = 0;
	for(i=0; i<sock_All; i++)
	{
		memset(&netsock, 0, sizeof(netsock));
		Sock_Fd[i] = socket(AF_INET, SOCK_STREAM, 0);
		if(Sock_Fd[i] < 0)
		{
			printf("creat socket error\n");
			return 0
		}
		netsock.sin_family = AF_INET;
		netsock.sin_port = htons(Port[i]);
		netsock.sin_addr.s_addr = htonl(INADDR_ANY);

		if(bind(Sock_Fd[i], (struct sockaddr_in *)&netsock, sizeof(struct sockaddr_in)) < 0)
		{
			printf("bind fail\n");
			return 0
		}
		
	}	
	Set_Socket_Attribute();
	return 1;
}
void Set_Socket_Attribute()
{
	//setsockopt(Sock_Fd, SOL_SOCKET, SO_SNDBUF, (char *)&Buff, sizeof(int));
}
void Socket_Process()
{
 
}
