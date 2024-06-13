import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;

public class Client_2201075_GeorgeRahul {
    public static final Scanner sc = new Scanner(System.in);

    public static int printMenu() {
        System.out.println("1. Total Number Of Employees Present");
        System.out.println("2. Get Employee Details");
        System.out.println("3. Compare the Salaries of two employees");
        System.out.println("4. Get by District");
        System.out.println("5. Exit");
        System.out.println("Enter the choice: ");
        int choice = sc.nextInt();
        sc.nextLine();
        return choice;
    }

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        Socket connection = new Socket("localhost", 2409);

        //Creating the streams
        ObjectOutputStream objectOutputStream = new ObjectOutputStream(connection.getOutputStream());
        ObjectInputStream objectInputStream = new ObjectInputStream(connection.getInputStream());


        System.out.println("Connected to the Server....");
        while (true) {
            int choice = printMenu();

            if (choice == 1) {
                objectOutputStream.writeUTF("numberOfEmployeesPresent");
                objectOutputStream.flush();
                System.out.println("The total number of employees is: " + objectInputStream.readUTF());
            } else if (choice == 2) {
                objectOutputStream.writeUTF("getEmployeeDetails");
                objectOutputStream.flush();

                System.out.println("Enter the Employee ID: ");
                int EmployeeID = sc.nextInt();
                sc.nextLine();
                objectOutputStream.writeUTF(Integer.toString(EmployeeID));
                objectOutputStream.flush();

                Employee employee = (Employee) objectInputStream.readObject();
                System.out.println(employee);

            } else if (choice == 3) {
                objectOutputStream.writeUTF("compareSalaries");
                objectOutputStream.flush();

                System.out.println("Enter the first Employee ID: ");
                int EmployeeID = sc.nextInt();
                sc.nextLine();
                objectOutputStream.writeUTF(Integer.toString(EmployeeID));
                objectOutputStream.flush();

                System.out.println("Enter the second Employee ID: ");
                EmployeeID = sc.nextInt();
                sc.nextLine();
                objectOutputStream.writeUTF(Integer.toString(EmployeeID));
                objectOutputStream.flush();

                System.out.println(objectInputStream.readUTF());


            } else if (choice == 4) {
                objectOutputStream.writeUTF("getByDistrict");
                objectOutputStream.flush();
                System.out.println("Enter the District: ");
                objectOutputStream.writeUTF(sc.nextLine());
                objectOutputStream.flush();

                ArrayList<Employee> arrayList = (ArrayList<Employee>) objectInputStream.readObject();

                for (Employee emp : arrayList) {
                    if (emp.getClass() == PermanentEmployee.class) {
                        System.out.println(((PermanentEmployee) emp));
                    } else {
                        System.out.println(((TempEmployee) emp));
                    }
                }


            } else if (choice == 5) {
                objectOutputStream.writeUTF("stop");
                break;
            }
            objectOutputStream.reset();//Inorder to reset the output stream. Else, causes issues while sending objects
        }
        System.out.println("Disconnected from the server. Ending the program");
        objectOutputStream.close();
        objectInputStream.close();
        connection.close();
    }
}