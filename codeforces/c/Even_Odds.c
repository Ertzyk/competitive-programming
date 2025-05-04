#include <stdio.h>

int main() {
    long long int n, k;
    scanf("%lld %lld", &n, &k);
    if ((n + 1)/2 >= k) {
        printf("%lld", 2*k - 1);
        return 0;
    }
    printf("%lld", 2*(k - (n + 1)/2));
    return 0;
}