#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <netinet/in.h>

#define PORT 8001

int main(){
	// creating a file pointer to read the html file to send to client
	// open a file to server
	FILE *html_data;
	html_data = fopen("index.html", "r");
	
	// creating a string to store the content of html file
	char response_data[1024];
	
	//syntax for fgets which is used to read the file 
	//fgets(destination, size, source)
	fgets(response_data, 1024, html_data);

	char http_header[2048] = "HTTP/1.1 200 OK\r\n\n";
	// \r == return carriage, which waits for the return key to be pressed, i think
	 
	// concatenate the http header and response data
	strcat(http_header, response_data);
	
	//create a socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	// define the address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PORT);
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	// binding the socket to the port
	bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

	listen(server_socket, 5);

	int client_socket;
	/*we want the server to keep on serving, hence the use of while(1) infinte loop
	and can only be interrupted by system of ctrl + C command, etc */
	while(1){
		// accepting connection on client socket
		client_socket = accept(server_socket, NULL, NULL);
		// sending data back to the client alongside the http status
		send(client_socket, http_header, sizeof(http_header), 0);
		// closing the client socket
		close(client_socket);
	}

	return 0;
}
