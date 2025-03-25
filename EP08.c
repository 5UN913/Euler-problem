/*************************************************************************
	> File Name: EP08.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Tue 25 Mar 2025 09:01:08 PM CST
 ************************************************************************/

#include <stdio.h>
#include "EP08.h"

int main() {
    long long p = 1, zero = 0, ans = 0;
    for (int i = 0; num[i]; i++) {
        if (num[i] == '0') zero += 1;
        else p *= (num[i] - '0');
        if (i < 13) continue;
        if (num[i - 13] == '0') zero -= 1;
        else p /= (num[i - 13] - '0');
        if(zero == 0 && p > ans) ans = p;
    }
    printf("%lld", ans);
    return 0;
}
