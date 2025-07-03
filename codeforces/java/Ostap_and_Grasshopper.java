package codeforces.java;

import java.util.*;

public class Ostap_and_Grasshopper {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt(), start = -1;
        String s = sc.next();
        for(int i = 0; i < n; i++){
            if(s.charAt(i) == 'G' || s.charAt(i) == 'T'){
                start = i;
                break;
            }
        }
        for(int i = start + k; i < n; i += k){
            if(s.charAt(i) == 'G' || s.charAt(i) == 'T'){
                System.out.println("YES");
                sc.close();
                return;
            } else if(s.charAt(i) == '#'){
                System.out.println("NO");
                sc.close();
                return;
            }
        }
        System.out.println("NO");
        sc.close();
    }
}
