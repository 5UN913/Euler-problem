/*************************************************************************
	> File Name: EP05.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Sun 23 Mar 2025 10:58:29 AM CST
 ************************************************************************/

#include<stdio.h>

int gcd(int a, int b);

int main() {
    long long temp = 2, x;
    for (int i = 1; i <= 20; i++) {
        if (temp > i) x = gcd(temp, i);
        else x = gcd(i, temp);
        temp = temp * i / x;
    }
    printf("%lld\n", temp);
    return 0;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
