import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;

class Client {
    public static void main(String[] args) throws IOException {
        System.out.println("Finding a server");
        Socket connection = new Socket("localhost", 80);
        System.out.println("Connected to Server");
        ObjectOutputStream outputStream = new ObjectOutputStream(connection.getOutputStream());
        ObjectInputStream inputStream = new ObjectInputStream(connection.getInputStream());
        System.out.println("Initialised the streams");
        ArrayList<Integer> arr = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        System.out.println("The Server said: "+inputStream.readUTF());


        while (true) {
            System.out.println("Enter the integer: ");
            arr.add(sc.nextInt());
            sc.nextLine();
            outputStream.writeObject(arr);
            outputStream.flush();
            outputStream.reset();

        }

    }
}