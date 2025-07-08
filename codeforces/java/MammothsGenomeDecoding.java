package codeforces.java;

import java.util.*;

public class MammothsGenomeDecoding {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        if(n%4 != 0){
            System.out.println("===");
            sc.close();
            return;
        }
        int a = 0, c = 0, g = 0, t = 0;
        for(int i = 0; i < n; i++){
            if(s.charAt(i) == 'A') a++;
            else if(s.charAt(i) == 'G') g++;
            else if(s.charAt(i) == 'C') c++;
            else if(s.charAt(i) == 'T') t++;
        }
        if(a > n/4 || c > n/4 || g > n/4 || t > n/4){
            System.out.println("===");
            sc.close();
            return;
        }
        StringBuilder sb = new StringBuilder(s);
        for(int i = 0; i < n; i++){
            if(sb.charAt(i) == '?'){
                if(a < n/4) {
                    sb.setCharAt(i, 'A');
                    a++;
                } else if(c < n/4) {
                    sb.setCharAt(i, 'C');
                    c++;
                } else if(g < n/4) {
                    sb.setCharAt(i, 'G');
                    g++;
                } else {
                    sb.setCharAt(i, 'T');
                    t++;
                }
            }
        }
        System.out.println(sb.toString());
        sc.close();
    }
}
