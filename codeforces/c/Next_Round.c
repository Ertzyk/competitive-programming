#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, k, result = 0;
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int lowest_score_to_qual = max(a[k - 1], 1);
    for (int i = 0; i < n; i++) {
        if (a[i] < lowest_score_to_qual) {
            break;
        }
        result += 1;
    }
    printf("%d\n", result);
    return 0;
}