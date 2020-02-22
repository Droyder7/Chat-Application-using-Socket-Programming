/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

void error(char *msg)
{
   perror(msg);
   exit(1);
}

int main(int argc, char *argv[])
{
   int serv_sock, cli_sock, port, cli_len, n;     // Decalring Variables
     
   struct sockaddr_in serv_addr, cli_addr;   // Declaring server, client socket addresses

   char buffer[256], msg[256];    // Buffer in which the massage will receive

   //  Specifying Port No

   if (argc < 2) {
      port = 1234;
   }
   else
   {
     port = atoi(argv[1]);
   }

   printf("\nPort is set to : %d\n", port);

   if ((serv_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)      // Sever Socket File Descriptor is Created
      error("ERROR opening socket");
   
   bzero((char *) &serv_addr, sizeof(serv_addr));     // Initializing Zero in Server Socket Address

   // Initializing Server Socket Address
     
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = htons(port);
     
   if (bind(serv_sock, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)    // Binding of serv_sock to Current Host serv_addr
      error("ERROR on binding");

   if(listen(serv_sock,5)<0)     // Listen Call of serv_sock is done & 
      error("Listen");
   
   cli_len = sizeof(cli_addr);

while(1)
   {
   printf("\nWaiting for an Client to connect...\n");

   if ((cli_sock = accept(serv_sock, (struct sockaddr *) &cli_addr, &cli_len)) < 0)         // Accept Call is Successfull & cli_sock is created
      error("ERROR on accept");

      printf("\nA client is now connected");

   // printf("\nThe Successfully Connected client's address is : %s\n",inet_ntoa(cli_addr.sin_addr));

   while(1)
   {
      printf("\nWaiting for the Client to respond...\n");

   bzero(buffer,256);      // Initializing Buffer with zero

	n = read(cli_sock,buffer,sizeof(buffer));

   if (n < 0) error("ERROR reading from socket");
	else if (n ==0)
		break;
   else
      printf("\nMessage from Client: %s\n",buffer);

   bzero(msg,256);

   printf("Enter a massage for client :\n");
   fgets(msg,255,stdin);

   if ((n = write(cli_sock,msg, sizeof(msg))) < 0) error("ERROR writing to socket");
   else
      printf("Massage Sent!\n");    // closing the sever socket file descripter

   }
   close(cli_sock);     // closing the client socket file descripter

   printf("\nCurrent Client is now disconnected\n");
   }

   return 0;   
}