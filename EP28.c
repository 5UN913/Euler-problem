/*************************************************************************
	> File Name: EP28.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Sat 22 Mar 2025 06:55:04 PM CST
 ************************************************************************/

#include<stdio.h>
#define MAX_N 1001

int main() {
    int sum = 1;
    for (int l = 3; l <= MAX_N; l += 2) {
        sum += 4 * l * l - 6 * l + 6;
    }
    printf("%d\n", sum);
    return 0;
}
