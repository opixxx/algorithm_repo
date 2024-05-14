package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
*백준 20115 에너지 드링크
*  */
public class _20115 {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        Integer[] arr = new Integer[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        double sum = arr[n - 1];

        for (int i = 0; i < n - 1; i++) {
            double a = arr[i] / 2.0;
            sum += a;
        }
        if (sum == (int) sum) {
            System.out.printf("%d\n", (int) sum);
        } else {
            System.out.printf("%.1f\n", sum);
        }


    }
}
