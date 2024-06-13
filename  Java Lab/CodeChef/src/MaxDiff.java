import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        int t;
        t = sc.nextInt();

        while (t-- > 0) {

            int K, N;
            K = sc.nextInt();
            N = sc.nextInt();

            int[] arr = new int[K];
            for (int i = 0; i < K; i++) {
                arr[i] = sc.nextInt();
            }


            Arrays.sort(arr);

            int sum = 0;
            int check = 0;
            N = Math.min(N,K-N);
            for (int i = 0; i < K; i++) {
                if (check < N) sum -= arr[i];
                else sum += arr[i];
                check++;
            }
            System.out.println(sum);

        }

    }
}