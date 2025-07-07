package codeforces.java;

import java.util.*;

public class Compote {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();
        System.out.println(Math.min(Math.min(a, b/2), c/4)*7);
        sc.close();
    }
}
