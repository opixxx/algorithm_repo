package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
* 백준 20365 블로그2
* */
public class _20365 {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        String str = br.readLine();

        int blue = 0;
        int red = 0;

        char pre = ' ';

        for (int i = 0; i < str.length(); i++) {
            char cur = str.charAt(i);
            if (pre != cur) {
                if (cur == 'B') {
                    blue++;
                } else if (cur == 'R') {
                    red++;
                }
                pre = cur;
            }
        }

        int result = Math.min(blue, red) + 1;
        System.out.print(result);
    }
}
