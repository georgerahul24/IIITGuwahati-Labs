import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

public class Server {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ServerSocket socket = new ServerSocket(80);
        System.out.println(socket.getInetAddress());
        Socket connection = socket.accept();
        ObjectInputStream objectInput = new ObjectInputStream(connection.getInputStream());

        String str = "";

        ArrayList<Integer> arr;

        while (!str.equals("stop")) {
            // Read a string to check for the "Update" command
            str = objectInput.readUTF();
            System.out.println(str);

            if (str.equals("Update")) {

                // Read the object
                Object object = objectInput.readObject();
                arr = (ArrayList<Integer>) object;
                System.out.println(arr.toString());

                FileOutputStream f = new FileOutputStream("Server.ser");
                ObjectOutputStream fout = new ObjectOutputStream(f);
                fout.writeObject(arr);
                fout.flush();
                fout.close();
            }
        }

        connection.close();
        socket.close();
    }
}
