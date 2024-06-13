import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;

class Employee implements Serializable {
    String name;
    int EmployeeID;
    int Salary;
    String district;

    Employee() {
        System.out.println("Enter the name: ");
        name = Server_2201075_GeorgeRahul.sc.nextLine();
        System.out.println("Enter the Employee ID: ");
        EmployeeID = Server_2201075_GeorgeRahul.sc.nextInt();
        Server_2201075_GeorgeRahul.sc.nextLine();
        System.out.println("Enter the Salary: ");
        Salary = Server_2201075_GeorgeRahul.sc.nextInt();
        Server_2201075_GeorgeRahul.sc.nextLine();
        System.out.println("Enter the District: ");
        district = Server_2201075_GeorgeRahul.sc.nextLine();
    }

    @Override
    public String toString() {

        return "\n------" + "\nName: " + name + "\nEmployee ID: " + EmployeeID + "\nSalary: " + Salary + "\nDistrict: " + district;
    }
}

class TempEmployee extends Employee {
    @Override
    public String toString() {
        return super.toString() + "\nEmployee Type: Temporary";

    }
}

class PermanentEmployee extends Employee {
    @Override
    public String toString() {
        return super.toString() + "\nEmployee Type: Permanent";
    }
}


public class Server_2201075_GeorgeRahul {
    public final static Scanner sc = new Scanner(System.in);
    public static final ArrayList<Employee> employeeArrayList = new ArrayList<>();

    public static final String filename = "/Users/gr/Desktop/Java/JavaEndSem/src/ServerData.txt";


    public static void CreateEmployeesMenu() throws IOException {
        //This method is used to create the main data file and fill it with objects
        System.out.println("1. Initialise the objects.");
        System.out.println("2. Do not initialise the objects");

        if (sc.nextLine().equals("1")) {

            System.out.println("Enter the number of Employees you want to add: ");
            int numberofEmployees = sc.nextInt();
            sc.nextLine();

            for (int i = 0; i < numberofEmployees; i++) {
                System.out.println("1. Add a permanent employee.");
                System.out.println("2. Add a temporary employee. ");
                System.out.println("Enter your choice: ");

                int employeeTypeChoice = sc.nextInt();
                sc.nextLine();

                if (employeeTypeChoice == 1) {
                    employeeArrayList.add(new PermanentEmployee());
                } else {
                    employeeArrayList.add(new TempEmployee());
                }

            }

            FileOutputStream fileOutputStream = new FileOutputStream(filename);
            ObjectOutputStream objectOutputStream = new ObjectOutputStream(fileOutputStream);
            objectOutputStream.writeObject(employeeArrayList);
            objectOutputStream.flush();
            objectOutputStream.close();
            System.out.println("Server Data Created Successfully");
        }

    }

    public static void displayServerData() throws IOException, ClassNotFoundException {
        //This method helps to see the data in the file
        System.out.println("Do you want to see the server data? (y/n)");
        if (sc.nextLine().equals("y")) {
            FileInputStream fileInputStream = new FileInputStream(filename);
            ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);
            ArrayList<Employee> arrayList = (ArrayList<Employee>) objectInputStream.readObject();

            for (Employee emp : arrayList) {
                if (emp.getClass() == PermanentEmployee.class) {
                    System.out.println(((PermanentEmployee) emp));
                } else {
                    System.out.println(((TempEmployee) emp));
                }
            }

            objectInputStream.close();
            fileInputStream.close();

        }


    }

    public static int getTotalNumberOfEmployees() throws IOException, ClassNotFoundException {
        //This function returns the total number of employees store in the server
        FileInputStream fileInputStream = new FileInputStream(filename);
        ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);
        ArrayList<Employee> arrayList = (ArrayList<Employee>) objectInputStream.readObject();
        objectInputStream.close();
        fileInputStream.close();
        return arrayList.size();
    }

    public static Employee employeeDetail(int EmployeeID) throws IOException, ClassNotFoundException {
        //This function gets the employee details wrt an Employee ID
        FileInputStream fileInputStream = new FileInputStream(filename);
        ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);
        ArrayList<Employee> arrayList = (ArrayList<Employee>) objectInputStream.readObject();

        for (Employee emp : arrayList) {
            if (emp.EmployeeID == EmployeeID) {
                objectInputStream.close();
                fileInputStream.close();
                return emp;
            }
        }
        objectInputStream.close();
        fileInputStream.close();
        return null;
    }

    public static String CompareSalary(int EmployeeID1, int EmployeeID2) throws IOException, ClassNotFoundException {
        //This function compares the two salaries
        Employee employee1 = employeeDetail(EmployeeID1);
        Employee employee2 = employeeDetail(EmployeeID2);

        if (employee1.Salary > employee2.Salary) {
            return employee1.name + "has a higher salary";
        } else if (employee1.Salary < employee2.Salary) {
            return employee2.name + "has a higher salary";
        } else {
            return "Both " + employee1.name + " and " + employee2.name + " have equal salaries";
        }
    }

    public static ArrayList<Employee> findByDistrict(String district) throws IOException, ClassNotFoundException {
        //This function returns an arrayList with all Employees in that district
        ArrayList<Employee> employeeArrayListByDistrict = new ArrayList<>();

        FileInputStream fileInputStream = new FileInputStream(filename);
        ObjectInputStream objectInputStream = new ObjectInputStream(fileInputStream);
        ArrayList<Employee> arrayList = (ArrayList<Employee>) objectInputStream.readObject();

        for (Employee emp : arrayList) {
            if (emp.district.equals(district)) {
                employeeArrayListByDistrict.add(emp);
            }
        }
        objectInputStream.close();
        fileInputStream.close();
        return employeeArrayListByDistrict;

    }


    public static void main(String[] args) throws IOException, ClassNotFoundException {
        Server_2201075_GeorgeRahul.CreateEmployeesMenu();
        Server_2201075_GeorgeRahul.displayServerData();

        System.out.println("Waiting for the client to connect: ");

        ServerSocket serverSocket = new ServerSocket(2409);
        Socket connection = serverSocket.accept();

        System.out.println("Connected to the Client....");

        //Creating the Streams
        ObjectInputStream objectInputStream = new ObjectInputStream(connection.getInputStream());
        ObjectOutputStream objectOutputStream = new ObjectOutputStream(connection.getOutputStream());


        String clientCommand = "";

        while (!clientCommand.equals("stop")) {
            clientCommand = objectInputStream.readUTF();
            System.out.println("Client Requested this: " + clientCommand);

            if (clientCommand.equals("numberOfEmployeesPresent")) {
                objectOutputStream.writeUTF(Integer.toString(getTotalNumberOfEmployees()));
                objectOutputStream.flush();
            } else if (clientCommand.equals("getEmployeeDetails")) {
                int employeeID = Integer.parseInt(objectInputStream.readUTF());
                Employee employee = employeeDetail(employeeID);
                objectOutputStream.writeObject(employee);
                objectOutputStream.flush();


            } else if (clientCommand.equals("compareSalaries")) {
                int employeeID1 = Integer.parseInt(objectInputStream.readUTF());
                int employeeID2 = Integer.parseInt(objectInputStream.readUTF());

                objectOutputStream.writeUTF(CompareSalary(employeeID1, employeeID2));
                objectOutputStream.flush();
            } else if (clientCommand.equals("getByDistrict")) {
                objectOutputStream.writeObject(findByDistrict(objectInputStream.readUTF()));
                objectOutputStream.flush();
            }

            objectOutputStream.reset(); //Inorder to reset the output stream. Else, causes issues while sending objects
        }

        System.out.println("Disconnected from the client. Ending the program");
        objectOutputStream.close();
        objectInputStream.close();
        connection.close();
        serverSocket.close();
    }
}