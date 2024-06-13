import java.io.*;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(System.in);
        Socket connection = new Socket("localhost", 80);

        ObjectOutputStream objectOutput = new ObjectOutputStream(connection.getOutputStream());
        String str = "";

        ArrayList<Integer> dat = new ArrayList<>();
        dat.add(3);
        dat.add(4);

        while (!str.equals("2")) {
            System.out.println("1. Add an element to the Array List");
            System.out.println("2. Exit. ");
            str = sc.nextLine();

            if (str.equals("1")) {
                System.out.println("Enter a number: ");
                dat.add(sc.nextInt());
                sc.nextLine();

                // Use reset to clear the object cache
                objectOutput.reset();

                objectOutput.writeUTF("Update");
                objectOutput.flush();
                objectOutput.writeObject(dat);
                objectOutput.flush();
            }

            if (str.equals("2")) {
                objectOutput.writeUTF("stop");
                objectOutput.flush();
            }
        }

        System.out.println("Comes out of loop in client");
        objectOutput.close();
        connection.close();
    }
}
