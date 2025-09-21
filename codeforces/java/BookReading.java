package codeforces.java;

import java.util.*;

public class BookReading {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), t = sc.nextInt(), res = 0;
        ArrayList<Integer> a = new ArrayList<>(n);
        for(int i = 0; i < n; i++){
            int x = sc.nextInt();
            a.add(x);
        }
        while(t > 0){
            t -= 86400 - a.get(res);
            res++;
        }
        System.out.println(res);
        sc.close();
    }
}