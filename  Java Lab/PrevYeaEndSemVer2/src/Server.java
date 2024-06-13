import java.io.IOException;
import java.io.ObjectInput;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;

public class Server {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ServerSocket serverSocket = new ServerSocket(80);
        Socket connection = serverSocket.accept();
        System.out.println("Client Connected");

        ObjectInputStream inputStream = new ObjectInputStream(connection.getInputStream());
        ObjectOutputStream outputStream = new ObjectOutputStream(connection.getOutputStream());

        ArrayList<Integer> arr = new ArrayList<>();
        System.out.println("Enter a string: ");
        Scanner sc = new Scanner(System.in);

        outputStream.writeUTF(sc.nextLine());
        outputStream.flush();

        while (true) {

            Object obj = inputStream.readObject();
            arr = (ArrayList<Integer>) obj;

            System.out.println(arr.toString());

        }


    }


}
