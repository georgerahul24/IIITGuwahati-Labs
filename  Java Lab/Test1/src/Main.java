import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        System.out.println("Enter the size of the array: ");
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        System.out.println("Enter the elements: ");
        int[] arr = new int[x];
        for (int i = 0; i<arr.length; i++){
            arr[i]=scanner.nextInt();
        }

        for (int j : arr) {
            System.out.printf("%d ", j);
        }

    }


}