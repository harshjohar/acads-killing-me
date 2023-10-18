#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5555

void main()
{

    int clientSocket;
    struct sockaddr_in serverAddr;
    char buf[1024];
    
clientSocket = socket(PF_INET, SOCK_STREAM, 0);
    printf("Client socket Created Successfully...\n");
    
memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    printf("Connected to Server Successfully...\n");

    recv(clientSocket, buf, 1024, 0);
    printf("Data Received from server: %s...\n", buf);
    printf("Echoing data to server.......\n");
    send(clientSocket, buf, 1024, 0);

    printf("Closing Connection...\n");
}
/*
cd Socket/"TCP Echo Client"
gcc -o test tcp_echoclient_client.c
./test
*/
