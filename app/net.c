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
	}	 
	return 1;
}
void Net_Init()
{
	
}
int Net_Set(int *Fd, struct hostent * Host_addr, int Port, char * Msg,int Size)
{ 
	struct hostent * host_Addr = (struct hostent *)Host_addr;
	struct sockaddr_in server_addr;

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(Port);
	server_addr.sin_addr = *(host_Addr->h_addr);
	
	if(connect(*Fd, &server_addr, sizeof(server_addr)) == -1)
	{
		printf("connect error\n");
		free(host_Addr);
		return -1;
	}
	if(send(*Fd, Msg , Size, 0)== -1)
	{
		printf("send error\n");
		free(host_Addr);
		return -2;
	}
	free(host_Addr);
	return 1;
}
void Net_Send_Msg(struct hostent * Host_addr, int Port, char * Msg, int Size)
{
	int fb;
	fb = socket(AF_INET, SOCK_STREAM, 0);
	Net_Set(&fb, Host_addr, Port, Msg, Size);
}
struct hostent * Get_Server_By_Addr(char * Ip)
{
	struct in_addr *ip_addr; 
	struct hostent *host;
	host = malloc(sizeof(struct hostent));		//这个要记得进行free
	char *ip = Ip;
	if(!inet_aton(ip, ip_addr))
	{
		printf("inet error\n");
	}
	if((host = gethostbyaddr(ip_addr, 4, AF_INET)) == NULL)
	{
		printf("Get Host Addr Error\n");
	}
	return host;
}
struct hostent * Get_Server_By_Name(char * Name)
{
	struct hostent * host;
	char * name = Name;
	if((host = gethostbyname(name)) == NULL)
	{
		printf("Get Host Name Error\n");
	}
	printf("hostname : %s\n",host->h_name);
	return host;
}
void Set_Socket_Attribute()
{
	//setsockopt(Sock_Fd, SOL_SOCKET, SO_SNDBUF, (char *)&Buff, sizeof(int));
}
void Socket_Process()
{
	
}
