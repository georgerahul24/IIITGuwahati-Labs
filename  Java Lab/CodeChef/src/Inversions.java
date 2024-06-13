import java.util.*;

public class Inversions {
    public static int mergeInversion(int[] arr, int l, int m, int h) {
        int n1 = m - l + 1;
        int n2 = h - m;
        int[] L = new int[n1 + 1];
        int[] R = new int[n2 + 1];

        for (int i = 0; i < n1; i++) {
            L[i] = arr[l + i];
        }
        for (int j = 0; j < n2; j++) {
            R[j] = arr[m + j + 1];
        }
        L[n1] = Integer.MAX_VALUE;
        R[n2] = Integer.MAX_VALUE;

        int i = 0;
        int j = 0;
        int k = l;
        int crossInv = 0;

        while (i < n1 || j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
                k++;
            } else {
                arr[k] = R[j];
                j++;
                k++;
                if(L[i]!=Integer.MAX_VALUE)
                    crossInv += ((m - l) - i + 1);
            }
        }
        return crossInv;
    }

    public static int mergeSortInversion(int[] arr, int l, int h) {
        int inv = 0;
        if (l < h) {
            int m = l + (h - l) / 2;
            inv += mergeSortInversion(arr, l, m);
            inv += mergeSortInversion(arr, m + 1, h);
            inv += mergeInversion(arr, l, m, h);
        }
        return inv;
    }

    public static void main(String[] args) {
        //Array Input
        int n;
        System.out.println("Enter array size:");
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        sc.nextLine();
        int[] arr = new int[n];
        System.out.println("Enter the array:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.println("The inversions are " + mergeSortInversion(arr, 0, n - 1));
    }
}
