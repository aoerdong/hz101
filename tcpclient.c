#include<stdio.h>  // printf scanf 
#include<stdlib.h> // exit
#include<string.h>  // strcpy strlen
#include<sys/socket.h>  // socket 
#include<netinet/in.h>  // struct sockaddr_in 
#include<arpa/inet.h>

int main()
{
	// step1:�����׽���
	int clientfd; // �׽��֡��ļ���������  ���ڽ�������
			// AF_INET:Э���� ip+port�� tcp
	clientfd = socket(AF_INET, SOCK_STREAM, 0); // SOCK_DGRAM  ---- UDP
	// step:�����������ַ����������
	struct sockaddr_in  myservaddr;
	myservaddr.sin_family= AF_INET;
	myservaddr.sin_addr.s_addr = inet_addr("172.30.191.3")	;  // ���ػ���
	myservaddr.sin_port =  htons(1234);  //�˿ں� htons htonl
	connect(clientfd,&myservaddr,sizeof(myservaddr));
	
	//�ͻ���д
	char str[1024];
	while(1)
	{
		scanf("%s",str);
		write(clientfd,str,strlen(str)+1);
	}
	close(clientfd);
	
	return 0;
	
}