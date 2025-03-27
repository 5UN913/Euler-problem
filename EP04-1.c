#include <stdio.h>

int reverse(int n);

int main() {
    for (int a = 999; a >=100; a--) {
        for (int i = 0, b = 999; i < 10; i++) {
            if (a * b == reverse(a * b)) {
                printf ("%d\n", a * b);
                break;
            }
            b--;
        }
    }
    
    return 0;
}

int reverse(int n) {
    int x = 0;
    
    while (n != 0) {
        int digit = n % 10;
        x = x * 10 + digit;
        n /= 10;
    }
    
    return x;
}