/*************************************************************************
	> File Name: EP32.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Fri 28 Mar 2025 11:55:40 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_pandigital(int a, int b, int product) {
    char str[20];
    sprintf(str, "%d%d%d", a, b, product);
    if (strlen(str) != 9) return false;
    int digits[10] = {0};
    for (int i = 0; i < 9; i++) {
        char c = str[i];
        if (c < '1' || c > '9') return false;
        int num = c - '0';
        if (digits[num]) return false;
        digits[num] = 1;
    }
    return true;
}

int main() {
    int products[100] = {0};
    int count = 0;

    // 两位乘三位
    for (int a = 10; a <= 99; a++) {
        int min_b = (1000 + a - 1) / a;
        int max_b = 9999 / a;
        if (min_b < 100) min_b = 100;
        if (max_b > 999) max_b = 999;
        for (int b = min_b; b <= max_b; b++) {
            int product = a * b;
            if (product >= 1000 && is_pandigital(a, b, product)) {
                int found = 0;
                for (int i = 0; i < count; i++) {
                    if (products[i] == product) found = 1;
                }
                if (!found) products[count++] = product;
            }
        }
    }

    // 三位乘两位
    for (int a = 100; a <= 999; a++) {
        int min_b = (1000 + a - 1) / a;
        int max_b = 9999 / a;
        if (min_b < 10) min_b = 10;
        if (max_b > 99) max_b = 99;
        for (int b = min_b; b <= max_b; b++) {
            int product = a * b;
            if (product >= 1000 && is_pandigital(a, b, product)) {
                int found = 0;
                for (int i = 0; i < count; i++) {
                    if (products[i] == product) found = 1;
                }
                if (!found) products[count++] = product;
            }
        }
    }

    // 一位乘四位
    for (int a = 1; a <= 9; a++) {
        int min_b = (1000 + a - 1) / a;
        int max_b = 9999 / a;
        if (min_b < 1000) min_b = 1000;
        if (max_b > 9999) max_b = 9999;
        for (int b = min_b; b <= max_b; b++) {
            int product = a * b;
            if (product >= 1000 && is_pandigital(a, b, product)) {
                int found = 0;
                for (int i = 0; i < count; i++) {
                    if (products[i] == product) found = 1;
                }
                if (!found) products[count++] = product;
            }
        }
    }

    // 四位乘一位
    for (int a = 1000; a <= 9999; a++) {
        int max_b = 9999 / a;
        if (max_b > 9) max_b = 9;
        if (max_b < 1) continue;
        for (int b = 1; b <= max_b; b++) {
            int product = a * b;
            if (product >= 1000 && is_pandigital(a, b, product)) {
                int found = 0;
                for (int i = 0; i < count; i++) {
                    if (products[i] == product) found = 1;
                }
                if (!found) products[count++] = product;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < count; i++) sum += products[i];
    printf("%d\n", sum);
    return 0;
}
