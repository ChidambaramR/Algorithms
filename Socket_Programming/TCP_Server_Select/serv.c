#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 6556
#define MAXMSG 50

int make_socket(int port){
	int sock;
	struct sockaddr_in serv;
	
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0){
		perror("Socket Creation failure\n");
		exit(0);
	}	

	serv.sin_family = AF_INET;
	serv.sin_port = htons(port);
	serv.sin_addr.s_addr = htonl(INADDR_ANY);

	/*
	We are casting it to sockaddr instead of sockaddr_in. 
	sockaddr_in is the structure used with IPV4 addresses. It holds the address family
	AF_INET, a port in sin_port, and an IPV4 address in sin_addr
	But sockaddr is the common data structure used for all protocols.
	Also sockaddr is the 1st member in sockaddr_in. Thus address of sockaddr_in really means
	the sockaddr structure. So it is safe to typecast between the two structus
	*/	
	if(bind(sock, (struct sockaddr *)&serv, sizeof(serv)) < 0){
		perror("Socket bind failure\n");
		exit(0);
	}

	return sock;
}

int main(){
	int sock;
	int max;
	fd_set read_fd_set, write_fd_set, active_fd_set;
	struct timeval timeout;
	struct sockaddr_in client;
	int size;
	int i=0;
	
	// Create the socket
	sock = make_socket(PORT);
	max = sock;

	// Listen in the socket
	if(listen(sock, 5) < 0){
		perror("Socket Listen failure\n");
		exit(0);
	}

	// Add the socket to active fds
	FD_ZERO(&active_fd_set);
	FD_SET(sock, &active_fd_set);

	printf("Waiting for clients");
	fflush(stdout);
	while(1){
		/*
		Check for read/write in all the created sockets
		*/
		read_fd_set = active_fd_set;
		write_fd_set = active_fd_set;
	
		// Set the timeouts
		timeout.tv_sec = 1;
		timeout.tv_usec = 0;

		// Wait in the select call
		//printf(".");
		fflush(stdout);
		if(select(max+1, &read_fd_set, &write_fd_set, NULL, &timeout) < 0){
			perror("Select failure\n");
			exit(0);
		}

		// There is not error and some fd is set
		for(i=0; i<(max+1); i++){
			if(FD_ISSET(i, &read_fd_set)){
				// There is a connection request on the original socket
				if(i == sock){
					int new;
					int size = sizeof(client);
					new = accept(sock, (struct sockaddr *)&client, &size);
					if(new > max)
						max = new;
					if(new < 0){
						perror("Accept failure\n");
						exit(0);
					}
					printf("Server: connect from host %s, port %hd.\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
					FD_SET(new, &active_fd_set);
				}
				else{
					// This is a normal operation from already established client
					char buffer[100];
					int nbytes;
					nbytes = read(i, buffer, MAXMSG);
					if(nbytes < 0){
						perror("Read filure\n");
						exit(0);	
					}
					if(nbytes == 0){
						/* 
						EOF. The socket is still readable on EOF. So we need to close it
						*/
						close(i);
						FD_CLR(i, &active_fd_set);
					}
					printf("From client %s: %s\n",inet_ntoa(client.sin_addr), buffer);
				}
			}
		}
		FD_ZERO(&read_fd_set);
		FD_ZERO(&write_fd_set);
	}
	return 0;
}
