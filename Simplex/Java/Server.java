import java.io.*;
import java.net.*;

public class Server {
    public static void main(String args[]) throws Exception {

        String clientMsg;

        int port= 1234;

        System.out.println("Welcome to the Chat Application\nYou are the Server");

        if(args.length==1)
        {
            port = Integer.parseInt(args[0]);
        }            
            
        System.out.println("Port is set to : "+port);

        start : while (true) 
        {
            ServerSocket serverSocket = new ServerSocket(port);

            System.out.println("\nWaiting for an Client to Connect...");

            Socket clientSocket = serverSocket.accept();

            System.out.println("\nAn Client is Now Connected to this Server\nThe Connected Client IP Address is :"+ clientSocket.getInetAddress());
        
            BufferedReader inFromClient = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

            inFromClient.readLine();

            clientSocket.close();


            System.out.println("\nWaiting for Client to Respond...");

            clientSocket = serverSocket.accept();

            inFromClient = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

            OutputStream outToClient = clientSocket.getOutputStream();

            clientMsg = inFromClient.readLine();

            if (clientMsg.indexOf("0") == 0)
            {
                System.out.println("\nCurrent Client is Now Disconnected..");
                continue start;
            }

            System.out.println("\nFROM CLIENT : "+clientMsg);

            // System.out.println("\nEnter the Server Message to Client :");

            // serverMsg = System.console().readLine();

            // if (serverMsg.indexOf('0')==0) 
            // {
            //     outToClient.write(("The Server is now closed").getBytes());
            //     clientSocket.close();
            //     break;
            // }

            // outToClient.write((serverMsg).getBytes());

            clientSocket.close();

            serverSocket.close();
            
        }

        
    }
} 
