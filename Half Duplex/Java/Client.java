import java.io.*;
import java.net.*;

public class Client {
    public static void main(String args[]) throws Exception{

        String clientMsg,serverMsg, ip = "127.0.0.1";
        int port = 1234;

        System.out.println("Welcome to the Chat Application\nYou are the Client");

         if (args.length == 1) {
            port = Integer.parseInt(args[0]);
        } else if (args.length == 2) {
            ip = args[0];
            port = Integer.parseInt(args[1]);
        }

        System.out.println("IP address is set to : " + ip);

        System.out.println("Port is set to : " + port);

        Socket clientSocket = new Socket(ip, port);
        OutputStream outToServer = clientSocket.getOutputStream();
        BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        outToServer.write(("1" + "\n").getBytes());
        clientSocket.close();
            
        System.out.println("\nConnection Established To The Server...");

        System.out.println("\nTo Exit enter 0");

        while (true)
        {
            System.out.println("\nEnter The Client Message to Server :");

            clientMsg = System.console().readLine();

            clientSocket = new Socket(ip, port);
            outToServer = clientSocket.getOutputStream();
            inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));

            outToServer.write((clientMsg + "\n").getBytes());

            if (clientMsg.indexOf("0") == 0)
            {
                break;
            }

            System.out.println("\nWaiting for Server to Respond");

            serverMsg = inFromServer.readLine();

            System.out.println("\nFROM SERVER : " + serverMsg);

            clientSocket.close();

            if (serverMsg.contentEquals("The Server is now closed")) {
                break;
            }
        }
        System.out.println("\nExiting The Application...");

    }
}
