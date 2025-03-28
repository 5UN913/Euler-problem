/*************************************************************************
	> File Name: EP38.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Fri 28 Mar 2025 08:39:59 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX_N 10000

int chk[15] = {0};

int digits(int n) {
    return floor(log10(n)) + 1;
}

long long assemble(int i, int j) {
    int temp1 = 0, temp2 = 0, dh = 0, ans = 0;
    for (int k = 1; k <= j; k++) {
        temp1 = i * k;
        dh += digits(temp1);
        temp2 = temp1 * pow(10, (9 - dh));
        ans += temp2;
    }
    return ans;
}  

int is_val(long long x, int *chk) {
    memset(chk, 0, 15 * sizeof(int));
    if (x <= 0) return 0;
    int count = 0;
    while (x > 0) {
        int digit = x % 10;
        if (digit == 0 || chk[digit]) return 0;
        chk[digit] = 1;
        count++;
        x /= 10;
    }
    return count == 9;
}

int main() {
    long long ans = 0, temp;
    for (int i = 1; i < MAX_N; i++) {
        for (int j = 1; j < 10; j++) {
            temp = assemble(i, j);
            if (!is_val(temp, chk)) continue;
            if (temp > ans) ans = temp;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
