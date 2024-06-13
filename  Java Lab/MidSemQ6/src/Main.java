import java.util.ArrayList;
import java.util.Scanner;

class Details {
    private final Scanner sc = new Scanner(System.in);
    public ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
    public int numberOfItems;

    public void getDetails() {
        System.out.println("Enter the number of items: ");
        numberOfItems = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < numberOfItems; i++) {

        }

    }

    public void printDetails() {
        for (ArrayList<Integer> i : arr) {
            System.out.printf("(%d , %d)", i.get(0), i.get(1));
        }
    }
}


public class Main {
    public static void main(String[] args) {
        System.out.println("Hello world!");
    }
}