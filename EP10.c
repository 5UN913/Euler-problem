/*************************************************************************
	> File Name: EP10.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Mon 24 Mar 2025 03:22:27 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#define MAX_N 2000000ll
typedef long long l;

int primes[MAX_N + 5];
bool is_compound[MAX_N + 5] = {false};

int main() {
    int cnt = 0;
    l sum = 0;
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_compound[i]) {
            primes[cnt++] = i;
        }
        for (int j = 0; j < cnt && i * primes[j] <= MAX_N; j++) {
            is_compound[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
        if (!is_compound[i]) sum += i;
    }
    printf("%lld\n", sum);
    return 0;
}
