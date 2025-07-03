package codeforces.java;

import java.util.*;

public class InsomniaCure {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt(), l = sc.nextInt(), m = sc.nextInt(), n = sc.nextInt(), d = sc.nextInt();
        int result = d/k + d/l + d/m + d/n - d/lcm(k, l) - d/lcm(k, m) - d/lcm(k, n) - d/lcm(l, m) - d/lcm(l, n) - d/lcm(m, n) + d/lcm(l, m, n) + d/lcm(k, m, n) + d/lcm(k, l, n) + d/lcm(k, l, m) - d/lcm(k, l, m, n);
        System.out.println(result);
        sc.close();
    }

    static int gcd(int a, int b){
        if(b == 0) return a;
        else return gcd(b, a%b);
    }

    static int lcm(int a, int b){
        return a*b/gcd(a, b);
    }

    static int lcm(int a, int b, int c){
        return lcm(lcm(a, b), c);
    }

    static int lcm(int a, int b, int c, int d){
        return lcm(lcm(a, b, c), d);
    }
}