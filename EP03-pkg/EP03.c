/*************************************************************************
	> File Name: EP03.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Sat 22 Mar 2025 07:32:43 PM CST
 ************************************************************************/

#include <stdio.h>
#define MAX_N 600851475143LL

int main() {
    long long ans = 0;
    long long i = 2;
    long long N = MAX_N;

    while (i * i <= N) {
        if (N % i == 0) {  // 修正1：改为相等判断
            ans = i;       // 记录当前质因数
            while (N % i == 0) {
                N /= i;    // 完全除去该质因数
            }
        }
        i += (i == 2) ? 1 : 2; // 优化：2之后只检查奇数
    }

    if (N != 1) ans = N;  // 处理最后剩余的大质数
    printf("%lld\n", ans); // 修正2：正确格式说明符

    return 0;
}
