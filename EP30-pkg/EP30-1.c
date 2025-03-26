/*************************************************************************
	> File Name: EP30-1.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Fri 21 Mar 2025 06:59:25 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>


int calculator(int n);

int main() {
    int n, ans = 0;
    for (int i = 2; i <= 2177280; i++) {
        if (i == calculator(i)) ans += i;
    }
    printf("%d\n", ans);
    return 0;
}

int calculator(int n) {
    int sum = 0;
    int original = n; // 保存原始n的值，避免修改循环变量导致的问题
    while (original != 0) {
        int digit = original % 10;
        sum += digit * digit * digit * digit * digit;
        original /= 10;
    }
    return sum;
}
