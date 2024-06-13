import java.util.ArrayList;
import java.util.Scanner;

class LibraryCardNumberException extends Exception {
    public LibraryCardNumberException(String str) {
        super(str);
        System.out.println(str);
    }
}

class PhoneNumberException extends Exception {
    public PhoneNumberException(String str) {
        super(str);
        System.out.println(str);
    }
}

class EmployeeIDException extends Exception {
    public EmployeeIDException(String str) {
        super(str);
        System.out.println(str);
    }
}

class EmailIDException extends Exception {
    public EmailIDException(String str) {
        super(str);
        System.out.println(str);
    }
}


class Person {
    public String firstName;
    public String lastName;
    public String dateOfBirth;

    Person() {
        System.out.println("Enter the First Name: ");
        firstName = Assignment10.sc.nextLine();
        System.out.println("Enter the Last Name: ");
        lastName = Assignment10.sc.nextLine();
        System.out.println("Enter the Date of Birth: ");
        dateOfBirth = Assignment10.sc.nextLine();
    }


    public void validate() throws LibraryCardNumberException {
    }


}

class Patron extends Person {
    public String libraryCardNumber;
    public String phoneNumber;

    Patron() {
        super();
        System.out.println("Enter the Library Card Number: ");
        libraryCardNumber = Assignment10.sc.nextLine();
        System.out.println("Enter the Phone Number: ");
        phoneNumber = Assignment10.sc.nextLine();
        validate();
    }

    public void validate() {

        try {
            if (!libraryCardNumber.matches("[a-zA-Z0-9]{10}")) {
                throw new LibraryCardNumberException("Wrong format for the Library Card");
            }
        } catch (Exception ignored) {

        }

        try {
            if (!phoneNumber.matches("\\d{10}")) {
                throw new PhoneNumberException("Wrong format for the Phone Number");
            }
        } catch (Exception ignored) {
            System.out.println();
        }
    }


}

class Librarian extends Person {
    public String employeeID;
    public String emailID;

    Librarian() {
        System.out.println("Enter the Employee ID: ");
        employeeID = Assignment10.sc.nextLine();
        System.out.println("Enter the Email ID: ");
        emailID = Assignment10.sc.nextLine();
    }

    public void validate() {
        try {
            if (!employeeID.matches("lib\\d{4}")) {
                throw new EmployeeIDException("Wrong format for Employee ID");
            }


        } catch (Exception ignored) {

        }

        try {
            if (!emailID.matches("[a-zA-Z0-9]*[@!#$&*][a-zA-Z0-9]*@[a-zA-Z]*.[a-zA-Z]*")) {
                throw new EmailIDException("Wrong format for Email ID");
            }

        } catch (Exception ignored) {

        }
    }
}

public class Assignment10 {
    public static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        ArrayList<Person> arr = new ArrayList<>();
        while (true) {
            System.out.println("Enter 1 to enter new Patron");
            System.out.println("Enter 2 to enter new Librarian");
            System.out.println("Enter 3 to exit");
            int choice = sc.nextInt();
            sc.nextLine();

            if (choice == 1) {
                arr.add(new Patron());
            }
            if (choice == 2) {
                arr.add(new Librarian());
            }
            if (choice == 3) break;

        }

        int[] num = new int[3];
        try {
            int a = num[4];

        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Invalid Index Entered");
        }

        String g = null;

        try {
            boolean d = g.matches("");
        } catch (NullPointerException e) {
            System.out.println("Null Pointer Operation Used");
        }

    }
}