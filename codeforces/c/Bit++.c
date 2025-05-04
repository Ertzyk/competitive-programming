#include <stdio.h>

int main() {
    int n, x = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char operation[4];
        scanf("%s", operation);
        if (operation[1] == '+') {
            x++;
        } else {
            x--;
        }
    }
    printf("%d\n", x);
    return 0;
}
