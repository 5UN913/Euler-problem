/*************************************************************************
	> File Name: EP07-extended-1.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Sun 23 Mar 2025 06:07:58 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX_N 10000

int prime[MAX_N + 5] = {0};
int max_prime[MAX_N + 5] = {0}; // 新增max_prime数组

void init_prime() {
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i] != 0) continue;
        prime[i] = i; // 质数的最小质因数是自身
        for (int j = i * i; j <= MAX_N; j += i) {
            if (prime[j] == 0) prime[j] = i; // 记录最小质因数
        }
    }
}

int main() {
    init_prime();
    
    // 计算每个数的最大质因数
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i] == i) { // i是质数
            max_prime[i] = i;
        } else {
            int p = prime[i]; // 最小质因数
            max_prime[i] = (p > max_prime[i / p]) ? p : max_prime[i / p];
        }
    }
    
    for (int i = 2; i <= MAX_N; i++) {
        printf("max(%d)--->%d\n", i, max_prime[i]);
    }
    
    return 0;
}
