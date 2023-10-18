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
    int sockfd;
    struct sockaddr_in serverAddr;
    int newSocket;
    struct sockaddr_in newAddr;
    socklen_t addr_size;
    char buf[1024];
    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    printf("Server socket Created Successfully...\n");
    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    printf("Bind to Port Number %d\n", 5555);
    listen(sockfd, 6);
    printf("Listening...\n");
    newSocket = accept(sockfd, (struct sockaddr *)&newAddr, &addr_size);
    printf("Enter the length of message\n");
    int len;
    scanf("%d", &len);
    char temp;
    scanf("%c", &temp);
    printf("Enter the message to send\n");
    scanf("%[^\n]", buf);
    send(newSocket, buf, len, 0);
    recv(newSocket, buf, 1024, 0);
    printf("Data Received from client's echo: %s...\n", buf);
    printf("Closing Connection...\n");
}
/*
cd Socket/"TCP Echo Client"
gcc -o test tcp_echoclient_server.c
./test
*/
