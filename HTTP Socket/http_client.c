#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	
  // The required argument that needs to be passed for the variable address is `127.0.0.1` that will be processed by the function inet_aton (see the man page for more info)
	char *address;
	address = argv[1]; /* argv[0] contains the file name, argv[1] contains the first argument passed to the program, it is used because tcp client... */
  int connect_status;
	
	// creating the client socket
	int client_socket;
	client_socket = socket(AF_INET, SOCK_STREAM, 0);

	// connect to an address
	struct sockaddr_in remote_address;
	remote_address.sin_family = AF_INET;
	remote_address.sin_port = htons(8001);
	inet_aton(address, &remote_address.sin_addr.s_addr);

	connect_status = connect(client_socket, (struct sockaddr *) &remote_address, sizeof(remote_address));

  printf("Conntection Status: %d \n", connect_status);

	char request[] = "GET / HTTP/1.1\r\n\r\n";
	char response[4096];
	
	send(client_socket, request, sizeof(request), 0);	
	recv(client_socket, &response, sizeof(response), 0);

	printf("Response from the server: %s \n", response);
	
	close(client_socket);  	

	return 0;
}
