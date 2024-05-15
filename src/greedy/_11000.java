package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
/*
* 백준 11000 강의실 배정
* */
class Class implements Comparable<Class>{
    int start;
    int end;

    public Class(int start, int end) {
        this.start = start;
        this.end = end;
    }

    @Override
    public int compareTo(Class o) {
        if (this.start == o.start) {
            return this.end - o.end;
        } else {
            return this.start - o.start;
        }
    }
}
public class _11000 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        List<Class> list = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            list.add(new Class(start, end));
        }
        Collections.sort(list);

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        pq.offer(list.get(0).end);

        for (int i = 1; i < n; i++) {
            if (pq.peek() <= list.get(i).start) {
                pq.poll();
            }
            pq.offer(list.get(i).end);
        }
        System.out.println(pq.size());
    }
}
