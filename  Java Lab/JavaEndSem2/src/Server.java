import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

class ThreadHandler implements Runnable {

    public ServerSocket serverSocket;
    public Socket connection;

    public int clientID;

    ObjectOutputStream objectOutputStream;
    ObjectInputStream objectInputStream;

    ThreadHandler(ServerSocket serverSocket, Socket connection) throws IOException {
        this.serverSocket = serverSocket;
        this.connection = connection;

        objectInputStream = new ObjectInputStream(connection.getInputStream());
        objectOutputStream = new ObjectOutputStream(connection.getOutputStream());

        System.out.println("Server has requested the client ID");
        objectOutputStream.writeUTF("clientID");
        objectOutputStream.flush();
        clientID = Integer.parseInt(objectInputStream.readUTF());

        System.out.println("Connected with Client ID: " + clientID);


    }

    @Override
    public void run() {
        System.out.println("Client ID: "+clientID+ " Thread has started");

        while (true) {
            try {
                System.out.println("Client: " + clientID + " || " + objectInputStream.readUTF());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

    }
}


public class Server {
    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(2409);

        System.out.println("The server has started");


        while (true) {
            Socket connection = serverSocket.accept();

            System.out.println("New client detected");

            ThreadHandler threadHandler = new ThreadHandler(serverSocket, connection);
            Thread thread = new Thread(threadHandler);
            thread.start();
        }


    }
}