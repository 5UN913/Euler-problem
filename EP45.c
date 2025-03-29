/*************************************************************************
	> File Name: EP45.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Sat 29 Mar 2025 03:28:44 PM CST
 ************************************************************************/

#include <stdio.h>

long long five(long long n) {
    return n * (3 * n - 1) / 2;
}

long long six(long long n) {
    return n * (2 * n - 1);
}

int binary_search(long long val, long long (*func)(long long)) {
    long long head = 1, tail = val, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (func(mid) == val) return 1;
        if (func(mid) < val) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int main() {
    long long n = 144;
    while (binary_search(six(n), five) == 0) n++;
    printf("%lld\n", six(n));
    return 0;
}
