#include <stdio.h>

int main() {
    char game[101], prev = 'x';
    int count_consecutive = 0;
    scanf("%s", game);
    for(int i=0; game[i] != '\0'; i++) {
        if (game[i] == prev) {
            count_consecutive++;
        } else {
            prev = game[i];
            count_consecutive = 1;
        }
        if (count_consecutive == 7) {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}