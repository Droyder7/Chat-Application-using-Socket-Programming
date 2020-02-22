                              =======================================================
                                    CHAT APPLICATION USING SOCKET PROGRAMMING
                              =======================================================
This is a client - server user-level application using Socket Programming in C & Java.
Server accepts massages in form of strings from clients (even multiple
strings from each client) and can reply by sending server massages to the connected client.

For example:
Client may send "Hello Server" and the server may reply with "Hi Client" and vice versa.


Both server and client(s) output's both sending & receiving strings on the terminal.The server and client processes can run on same or
different machines.

Helper Functions:
(1) void error(char *msg)
To report any kind of error along with the massage containing the cause of the error.

=======================================================
                          USAGE
=======================================================

Usage of Server in C:

The default PORT number of server is 1234

To connect to different PORT number, the PORT number is to be passed as command line argument while executing the server process.

Ex: ./server 11001
Port is set to : 11001

Usage of Client in C:

The default Server IP address is 127.0.0.1 (localhost) and PORT number is 1234 in client program.
Ex: ./client
Server is set to : 127.0.0.1

Port is set to : 1234

To connect to different IP address & PORT number of a server, the IP address and PORT number of server is to be passed as command line argument while executing the client process, .

Ex: ./client 172.16.4.12 11001
Server is set to : 172.16.4.12

Port is set to : 11001

=======================================================
                          OUTPUT
=======================================================

At Client End:
Server is set to : 127.0.0.1

Port is set to : 1234

Enter the message for Server : Hello Server
Massage Sent!

Enter the message for Server :
Massage from Server : Hi Client


At Server End:
Port is set to : 1234

Enter a massage for client :

Message from Client: Hello Server

Hi Client
Massage Sent!


=======================================================
                        NOTE
=======================================================


Multiple client processes can connect to the same server but not at the same time. When one client get disconnected then another client can connect to the server.

