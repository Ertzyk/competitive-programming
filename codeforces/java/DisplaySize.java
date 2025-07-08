package codeforces.java;

import java.util.*;

public class DisplaySize {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = (int)Math.sqrt(n);
        while(n%k != 0) k--;
        System.out.println(k + " " + n/k);
        sc.close();
    }
}