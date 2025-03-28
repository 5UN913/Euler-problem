/*************************************************************************
	> File Name: EP33.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Fri 28 Mar 2025 03:58:41 PM CST
 ************************************************************************/

#include <stdio.h>

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int is_val(int x, int y) {
    int x1 = x / 10, x2 = x % 10;
    int y1 = y / 10, y2 = y % 10;
    if (x2 == 0 || y2 == 0) return 0;
    if (x1 == y1 && x2 * y == y2 * x) return 1;
    if (x1 == y2 && x2 * y == y1 * x) return 1;
    if (x2 == y1 && x1 * y == y2 * x) return 1;
    if (x2 == y2 && x1 * y == y1 * x) return 1;
    return 0;
}

int main() {
    int x = 1, y = 1, c = 1;
    for (int a = 10; a < 100; a++) {
        for (int b = a + 1; b < 100; b++) {
            if (!is_val(a, b)) continue;
            x *= a;
            y *= b;
            c = gcd(x, y);
            x /= c;
            y /= c;
        }
    }
    printf("%d\n", y);
    return 0;
}
