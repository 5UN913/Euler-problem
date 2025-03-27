#include <stdio.h>
#define MAX 4000000

int fib(int n);

int main() {
    int sum = 0;
    for (int i = 1; i <= 33; i++) {
        if (fib(i) % 2 == 0) sum += fib(i);
    }
    printf("%d\n", sum);
    return 0;
}

int fib(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return fib(n - 1) + fib(n - 2);
}