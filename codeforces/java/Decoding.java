package codeforces.java;

import java.util.*;

public class Decoding {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = sc.next();
        StringBuilder front = new StringBuilder(), back = new StringBuilder();
        if(n%2 == 1){
            for(int i = 0; i < n; i++){
                if(i%2 == 0) back.append(s.charAt(i));
                else front.append(s.charAt(i));
            }
        } else {
            for(int i = 0; i < n; i++){
                if(i%2 == 0) front.append(s.charAt(i));
                else back.append(s.charAt(i));
            }
        }
        String result = front.reverse().toString() + back.toString();
        System.out.println(result);
        sc.close();
    }
}
