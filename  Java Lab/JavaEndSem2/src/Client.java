import javax.script.ScriptContext;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    public static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        System.out.println("Enter the Client ID: ");
        int clientID = sc.nextInt();
        sc.nextLine();

        Socket connection = new Socket("localhost", 2409);
        System.out.println("Connected to server");

        ObjectOutputStream objectOutputStream = new ObjectOutputStream(connection.getOutputStream());
        ObjectInputStream objectInputStream = new ObjectInputStream(connection.getInputStream());
        System.out.println("Streams Initialised");

        objectInputStream.readUTF();
        objectOutputStream.flush();
        objectOutputStream.writeUTF(Integer.toString(clientID));
        System.out.println("Server had requested the client ID");


        while (true){
            System.out.println("Enter something to say to the server: ");
            objectOutputStream.writeUTF(sc.nextLine());
            objectOutputStream.flush();
        }

    }
}
