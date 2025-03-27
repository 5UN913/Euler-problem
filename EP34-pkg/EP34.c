#include<stdio.h>

int f(int n);
int val(int n);

int main() {
    int sum;
    for (int i = 3; i <= 2540160; i++) {
        if (val(i) == f(i)) sum += i;
    }
    printf("%d", sum);
    return 0;
}

int f(int n) {
    if (n == 1) return 1;
    return f(n-1) * n;
}

int val(int n) {
    int temp, sum;
    for (int i = 1; i < 8; i++) {
        temp = n % 10;
        sum += f(temp);
        n /= 10;
    }
}
