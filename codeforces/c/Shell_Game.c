#include <stdio.h>

int main(){
    int n, x;
    scanf("%d %d", &n, &x);
    if(n%2 == 0){
        if(x == 0){
            if(n%6 == 0) printf("0\n");
            else if(n%6 == 2) printf("1\n");
            else printf("2\n");
        } else if(x == 1){
            if(n%6 == 0) printf("1\n");
            else if(n%6 == 2) printf("2\n");
            else printf("0\n");
        } else {
            if(n%6 == 0) printf("2\n");
            else if(n%6 == 2) printf("0\n");
            else printf("1\n");
        }
    } else {
        if(x == 0){
            if(n%6 == 1) printf("1\n");
            else if(n%6 == 3) printf("2\n");
            else printf("0\n");
        } else if(x == 1){
            if(n%6 == 1) printf("0\n");
            else if(n%6 == 3) printf("1\n");
            else printf("2\n");
        } else {
            if(n%6 == 1) printf("2\n");
            else if(n%6 == 3) printf("0\n");
            else printf("1\n");
        }
    }
    return 0;
}