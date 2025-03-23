/*************************************************************************
	> File Name: EP07-2.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Sun 23 Mar 2025 06:00:34 PM CST
 ************************************************************************/

#include <stdio.h>
#define MAX_N 200000

int prime[MAX_N + 5] = {0}; // 多开 5 个空间防止越界

void init_prime() {
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) continue;  // 非素数直接跳过
        prime[++prime[0]] = i;   // 精髓：用 prime[0] 记录素数个数，并存储素数
        for (int j = i; j <= MAX_N / i; j++) { // 优化：从 j=i 开始标记
            prime[i * j] = 1;    // 标记合数
        }
    }
}

int main() {
    init_prime();
    printf("%d\n", prime[10001]); // 输出第 10001 个素数
    return 0;
}

