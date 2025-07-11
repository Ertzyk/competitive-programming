#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main(){
    int n, result = 0;
    scanf("%d", &n);
    int a[6] = {0}, b[6] = {0};
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        b[x]++;
    }
    for(int i = 1; i <= 5; i++){
        if((a[i] + b[i])%2 == 1){
            printf("-1\n");
            return 0;
        }
        result += max(a[i], b[i]) - (a[i] + b[i])/2;
    }
    printf("%d", result/2);
    return 0;
}