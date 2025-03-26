/*************************************************************************
	> File Name: EP46.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Tue 25 Mar 2025 10:51:40 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#define MAX_N 1000000

int cnt = 0;
int primes[MAX_N + 5];
bool is_compound[MAX_N + 5] = {false};
bool a[MAX_N + 5] = {false};

void init_prime() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_compound[i]) {
            primes[cnt++] = i;
        }
        for (int j = 0; j < cnt && i * primes[j] <= MAX_N; j++) {
            is_compound[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    init_prime();
    for (int i = 0; i < cnt; i++) { 
            for (int n = 1; ; n++) {
            int val = primes[i] + 2 * n * n;
            if (val > MAX_N) break;
            a[val] = true;
        }
    }

        for (int n = 9; n <= MAX_N; n += 2) {
        if (!is_compound[n] || a[n]) continue;
        printf("%d\n", n);
        break;
    }
    return 0;
}
