package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
/*
* 백준 1541 잃어버린 괄호
* */
public class _1541 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        List<Integer> list = new ArrayList<>();

        String str = br.readLine();

        String[] split = str.split("-");

        for (String s : split) {
            int sum = 0;
            String[] split1 = s.split("\\+");
            for (String s1 : split1) {
                sum += Integer.parseInt(s1);
            }
            list.add(sum);

        }
        int answer = list.get(0);

        for (int i = 1; i < list.size(); i++) {
            answer -= list.get(i);
        }

        System.out.println(answer);
    }
}
