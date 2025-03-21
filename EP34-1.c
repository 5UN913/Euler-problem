/*************************************************************************
	> File Name: EP34-1.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Fri 21 Mar 2025 10:04:07 PM CST
 ************************************************************************/

#include<stdio.h>

int factorial(int n);
int sumOfFactorials(int n);

int main() {
    int sum = 0;
    // 从3开始，排除1和2
    for (int i = 3; i <= 2540160; i++) {
        if (sumOfFactorials(i) == i) {
            sum += i;
        }
    }
    printf("%d\n", sum); // 输出 145 + 40585 = 40730
    return 0;
}

int factorial(int n) {
    if (n <= 1) return 1;
    return factorial(n - 1) * n;
}

int sumOfFactorials(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += factorial(digit);
        n /= 10;
    }
    return sum;
}
