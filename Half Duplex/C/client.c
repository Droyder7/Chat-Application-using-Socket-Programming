#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "arpa/inet.h"

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;

    struct sockaddr_in serv_addr;


    char buffer[256];
    if (argc < 3) {
       argv[1]="127.0.0.1";
		portno = 1234;
    }
	else{
    portno = atoi(argv[2]);
	}

printf("\nServer is set to : %s\n", argv[1]);

printf("\nPort is set to : %d\n", portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        error("\nERROR connecting, Sever may not be active");
    else
        printf("\nConnected to the Server\n");

    while(1)
      {

    printf("Enter a message for Server : ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);

    n = write(sockfd,buffer,sizeof(buffer));
    if (n < 0) 
         error("ERROR writing to socket");
	   else
      printf("Massage Sent!\n",buffer);

      bzero(buffer,256);

      printf("\nWaiting for the Server to respond...\n");

    n = read(sockfd,buffer,sizeof(buffer));
    if (n < 0) 
         error("ERROR reading from socket");
else if (n ==0)
	{
printf("\nCurrent Server is now closed\n");
break;
}
else
	printf("\nMassage from Server : %s\n",buffer);
}

	close(sockfd);

    return 0;
}