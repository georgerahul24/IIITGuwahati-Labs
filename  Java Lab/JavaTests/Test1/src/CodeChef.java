import java.util.Scanner;

public class CodeChef {


    public void AveragePermutation() {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        while ((t--) > 0) {

            int n = scanner.nextInt();
            int n_copy = n;

            int[] arr = new int[n];
            int state1 = 0, state2 = n - 1;
            boolean state = true;
            n+=1;
            while ((--n) > 0) {
                if (state) {
                    state = false;

                    arr[state2--] = n;
                } else {
                    state = true;
                    arr[state1++] = n;
                }
            }

            for (int i = 0; i < n_copy; i++) {
                System.out.printf("%d ", arr[i]);
            }


            System.out.println();


        }
    }

}
