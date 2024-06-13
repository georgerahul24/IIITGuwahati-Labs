import java.util.Scanner;

public class Fibonacci {
    private static int getSize() {
        System.out.println("Enter the number of Fibonacci terms you need: ");
        Scanner scanner = new Scanner(System.in);
        return scanner.nextInt();

    }

    public void fibonacci() {
        int n = Fibonacci.getSize();

        int a = 0;
        int b = 1;
        int c;

        System.out.printf("The Fibonacci Series is: %d %d ", a, b);

        for (int i = 0; i < n - 2; i++) {
            c = a + b;
            System.out.printf("%d ", c);
            a = b;
            b = c;

        }
    }

}
