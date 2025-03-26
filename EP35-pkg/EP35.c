/*************************************************************************
	> File Name: EP35.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Mon 24 Mar 2025 07:28:49 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void euler_sieve(int n, bool *is_prime, int *primes, int *primes_count) {
    memset(is_prime, true, (n + 1) * sizeof(bool));
    is_prime[0] = is_prime[1] = false;
    *primes_count = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes[(*primes_count)++] = i;
        }
        for (int j = 0; j < *primes_count && i * primes[j] <= n; j++) {
            is_prime[i * primes[j]] = false;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

bool is_circular_prime(int p, bool *is_prime) {
    if (p < 10) {
        return p == 2 || p == 3 || p == 5 || p == 7;
    }
    char s[10];
    sprintf(s, "%d", p);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == '0' || s[i] == '2' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '8') {
            return false;
        }
    }
    for (int i = 0; i < len; i++) {
        char rotated[10];
        strncpy(rotated, s + i, len - i);
        strncpy(rotated + len - i, s, i);
        rotated[len] = '\0';
        int rotated_num = atoi(rotated);
        if (!is_prime[rotated_num]) {
            return false;
        }
    }
    return true;
}

int main() {
    const int limit = 1000000;
    bool *is_prime = (bool *)malloc((limit + 1) * sizeof(bool));
    int *primes = (int *)malloc(limit * sizeof(int));
    int primes_count;

    euler_sieve(limit, is_prime, primes, &primes_count);

    int count = 0;
    for (int i = 0; i < primes_count; i++) {
        if (is_circular_prime(primes[i], is_prime)) {
            count++;
        }
    }

    printf("%d\n", count);

    free(is_prime);
    free(primes);
    return 0;
}
