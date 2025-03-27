/*************************************************************************
	> File Name: EP14-2.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Thu 27 Mar 2025 09:03:33 AM CST
 ************************************************************************/

#include<stdio.h>
#define MAX_N 1000000

int memo[MAX_N + 1] = {0};

int calc_len(long long n) {
    if (n == 1) return 1;
    if (n <= MAX_N && memo[n]) return memo[n];
    int result = 0;
    if (n & 1) result = calc_len(3 * n + 1) + 1;
    else result = calc_len(n >> 1) + 1;
    if (n <= MAX_N) memo[n] = result;
    return result;
}

int main() {
    int ans = 0, len = 0;
    for (int i = 1; i <= MAX_N; i++) {
        int tmp_len = calc_len(i);
        if (tmp_len <= len) continue;
        len = tmp_len;
        ans = i;
    }
    printf("best_num: %d, len: %d\n", ans, len);
    return 0;
}
