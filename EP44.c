/*************************************************************************
	> File Name: EP44.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Sat 29 Mar 2025 11:00:06 AM CST
 ************************************************************************/

#include <stdio.h>
#define MAX_N 10000000ll

long long num[MAX_N + 5] = {0};

void init_num() {
    for (long long i = 1; ; i++) {
        long long p_i = i * (3 * i - 1) / 2;
        if (p_i >= MAX_N) break;
        num[p_i] = 1;
    }
}

int main() {
    init_num();
    int D = MAX_N;
    for (int i = 1; ; i++) {
        long long p_i = i * (3 * i - 1) / 2;
        if (p_i >= MAX_N) break;
        for (int j = i + 1; ; j++) {
            long long p_j = j * (3 * j - 1) / 2;
            if (p_j >= MAX_N) break;
            long long sum = p_i + p_j;
            long long temp = p_j - p_i;
            if (sum >= MAX_N || temp >= MAX_N) continue;
            if (num[sum] && num[temp]) {
                if (temp < D) D = temp;
            }
        }
    }
    printf("%d\n", D);
    return 0;
}
