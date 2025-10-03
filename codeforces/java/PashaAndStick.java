package codeforces.java;

import java.util.*;

public class PashaAndStick {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        if(n%2 == 1) System.out.println(0);
        else System.out.println((n/2 - 1)/2);
        sc.close();
    }
}