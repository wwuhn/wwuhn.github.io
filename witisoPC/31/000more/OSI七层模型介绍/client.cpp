#include<winsock2.h>
#include<stdio.h>
#pragma comment(lib,"ws2_32.lib")
void main()
{
WSADATA wsaData;
SOCKET sockClient;//客户端Socket
SOCKADDR_IN addrServer;//服务端地址
WSAStartup(MAKEWORD(2,2),&wsaData);
//新建客户端socket
sockClient=socket(AF_INET,SOCK_STREAM,0);
//定义要连接的服务端地址
addrServer.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");//目标IP(127.0.0.1是回送地址)
addrServer.sin_family=AF_INET;
addrServer.sin_port=htons(6000);//连接端口6000
//连接到服务端
connect(sockClient,(SOCKADDR*)&addrServer,sizeof(SOCKADDR));
//发送数据
char message[20]="HelloSocket!";
send(sockClient,message,strlen(message)+1,0);
//关闭socket
closesocket(sockClient);
WSACleanup();
system("pause");
}