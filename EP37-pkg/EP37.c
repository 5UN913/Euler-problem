/*************************************************************************
	> File Name: EP37.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Mon 24 Mar 2025 07:46:57 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define MAX_N 2000000ll

int primes[MAX_N + 5];
bool is_compound[MAX_N + 5] = {false};
int cnt = 0;

void init_prime() {
    is_compound[0] = is_compound[1] = true;
    cnt = 0;
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_compound[i]) primes[cnt++] = i;
        for (int j = 0; j < cnt && i * primes[j] <= MAX_N; j++) {
            is_compound[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int is_val(int n) {
    int h = pow(10, floor(log10(n)));
    int original_n = n;

    while (h >= 10) {
        int current = n % h;
        if (is_compound[current]) {
            return 0;
        }
        h /= 10;
    }

    int x = original_n;
    while (x > 0) {
        if (is_compound[x]) {
            return 0;
        }
        x /= 10;
    }

    return 1;
}

int main() {
    int sum = 0;
    init_prime();
    for (int i = 0; i < cnt; i++){
        if (is_val(primes[i])){
            sum += primes[i];
        }      
    }
    printf("%d\n", sum - 17);
    return 0;
}
