#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define PORT 5353 // port number

int main(int argc, char const *argv[]) {
	struct sockaddr_in serverAddress;  // server address
	serverAddress.sin_family = AF_INET; // sockets address family (TCP/IP v4)
  serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); // getting address
  serverAddress.sin_port = htons(PORT); // conversion to network byte order  
  int client = socket(AF_INET, SOCK_STREAM, 0); // create socket

  // get connection with server
  if (connect(client, (struct sockaddr *)&serverAddress, sizeof(struct sockaddr)) == -1) {
    perror("Error connect");
    exit(1);
  }
	
  printf("Connected\n");

  while(1){
    char message[256];
    scanf("%s", message);
    send(client,message,strlen(message),0);
  }
	return 0;
}