/*************************************************************************
	> File Name: EP07-extended-1.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Sun 23 Mar 2025 06:07:58 PM CST
 ************************************************************************/

#include <stdio.h>
#define MAX_N 10000

int prime[MAX_N + 5] = {0};
void init_prime() {
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i] != 0) continue; // 已标记为合数，跳过
        for (int j = i * i; j <= MAX_N; j += i) {
            prime[j] = i; // 标记i的倍数为合数
        }
    }
}

int main() {
    init_prime();
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i] == 0) prime[i] = i;
        printf("min(%d)--->%d\n", i, prime[i]);
    }
    return 0;
}
