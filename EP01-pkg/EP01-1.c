#include <stdio.h>

int sum(int n);

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", sum(n));
    return 0;
}

int sum(int n) {
    int y = 0;
    for (int i = 1; i < n; i++) {
        if (i % 3 == 0 || i % 5 == 0) y += i;
    } 
    return y;
}
