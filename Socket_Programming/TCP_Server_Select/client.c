#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h> 
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>

#define PORT 6556

int main(){
	int sock;
	int rc;
	struct sockaddr_in client;
	struct hostent* server;
	char msg[100];

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0){
		perror("Socke creation failure\n");
		exit(0);
	}

	bzero(&client, sizeof(client));
	
	client.sin_family = AF_INET;
	client.sin_port = htons(PORT);
	server = gethostbyname("127.0.0.1");
	memcpy((char*)(&(client.sin_addr)), server->h_addr, server->h_length);
	
	rc = connect(sock, (void*)&client, sizeof(client));
	if(rc == -1){
		printf("Could not connect to server\n");
		exit(0);
	}

	while(1){
		printf("Enter the messaged\n");
		gets(msg);
		if(!strcmp(msg, "Exit"))
			exit(1);
		rc = send(sock, msg, sizeof(msg), 0);
		printf("Message sent to server\n");
	}
	return 0;
}
