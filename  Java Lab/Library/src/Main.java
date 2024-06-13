import java.util.ArrayList;
import java.util.Scanner;

class Student {
    private final Scanner scanner = new Scanner(System.in);
    private int studentID;
    private String firstName;
    private String lastName;
    private int age;
    private String department;
    private int semester;
    private int CGPA;


    Student() {
        this.setDetails(true);

    }

    Student(int cgpa) {
        this.CGPA = cgpa;
        this.setDetails(false);
    }

    public void setDetails(boolean needCGPA) {
        System.out.print("Enter the studentID: ");
        studentID = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Enter the  First Name: ");
        firstName = scanner.nextLine();

        System.out.print("Enter the  Last Name: ");
        lastName = scanner.nextLine();

        System.out.print("Enter the age: ");
        age = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Enter the Department: ");
        department = scanner.nextLine();


        System.out.print("Enter the Semester: ");
        semester = scanner.nextInt();



        if (needCGPA) {
            System.out.print("Enter the CGPA: ");
            CGPA = scanner.nextInt();

        }

    }

    public void setDetails(int id, String fname, String lname, int age, String department, int semester, int cgpa) {
        this.studentID = id;
        this.firstName = fname;
        this.lastName = lname;
        this.age = age;
        this.department = department;
        this.semester = semester;
        this.CGPA = cgpa;

    }

    public static void getDetails(int id, ArrayList<Student> studentArray) {
        for (Student student : studentArray) {
            if (student.studentID == id) {
                student.printDetails();
                break;
            }
        }
    }

    public int getCGPA() {
        return CGPA;
    }

    public static void getCGPA(int id, ArrayList<Student> studentArray) {
        for (Student student : studentArray) {
            if (student.studentID == id) {
                System.out.println("CGPA: " + student.getCGPA());
                break;
            }
        }
    }

    public static void findStudentByAge(int age, ArrayList<Student> studentArray) {
        for (Student student : studentArray) {
            if (student.age == age) {
                student.printDetails();
            }
        }
    }

    public static float calculateAverage(ArrayList<Student> studentArray) {
        int sum = 0;
        for (Student student : studentArray) {
            sum += student.getCGPA();
        }
        return (float) sum / (float) studentArray.size();

    }

    public void printDetails() {
        System.out.println("Student ID: " + studentID);
        System.out.printf("\nName: %s %s\n", firstName, lastName);

        System.out.println("Age: " + age);
        System.out.println("Department: " + department);
        System.out.println("Semester: " + semester);
        System.out.println("CGPA: " + CGPA);

    }

    public int getStudentID() {
        return studentID;
    }


}


class Menu {
    private final Scanner scanner = new Scanner(System.in);
    private ArrayList<Student> studentArrayList = new ArrayList<Student>();


    public int printMenu() {


        System.out.println("\nMENU:\n");
        System.out.println("0. Add a new Student");
        System.out.println("1. Set Details");
        System.out.println("2. Get Details");
        System.out.println("3. Get CGPA");
        System.out.println("4. Find Students by Age");
        System.out.println("5. Calculate Average CGPA");
        System.out.println("6. Exit");
        System.out.println("\nEnter choice:");
        return scanner.nextInt();
    }

    public void callMenu() {
        while (true) {
            int choice = printMenu();

            switch (choice) {
                case 0:
                    studentArrayList.add(new Student());
                    break;
                case 1:
                    System.out.println("Enter the studentID to set details: ");
                    int id = scanner.nextInt();
                    scanner.nextLine();//To skip '\n'

                    for (Student student : studentArrayList) {
                        if (student.getStudentID() == id) {
                            student.setDetails(true);
                            break;
                        }
                    }
                    break;
                case 2:
                    System.out.println("Enter the studentID to get the details: ");
                    id = scanner.nextInt();
                    scanner.nextLine();//To skip '\n'
                    Student.getDetails(id, studentArrayList);
                    break;
                case 3:
                    System.out.println("Enter the studentID to set details: ");
                    id = scanner.nextInt();
                    scanner.nextLine();//To skip '\n'
                    Student.getCGPA(id, studentArrayList);
                    break;
                case 4:
                    System.out.println("Enter the age: ");
                    id = scanner.nextInt();
                    scanner.nextLine();//To skip '\n'
                    Student.findStudentByAge(id, studentArrayList);
                    break;
                case 5:
                    System.out.println("The average CGPA is " + Student.calculateAverage(studentArrayList));
                    break;
                case 6:
                    System.exit(0);


            }


        }
    }

}

public class Main {
    public static void main(String[] args) {
        new Menu().callMenu();
    }
}