#include <stdio.h>

int reverse(int n);

int main() {
    int max_palin = 0;
    for (int a = 999; a >= 100; a--) {
        // 内层循环从a开始递减，确保a >= b以避免重复检查
        for (int b = a; b >= 100; b--) {
            int product = a * b;
            // 如果当前乘积小于等于已知最大回文数，后续乘积更小，直接终止内层循环
            if (product <= max_palin) {
                break;
            }
            // 检查是否为回文数
            if (product == reverse(product)) {
                max_palin = product; // 更新最大回文数
                break; // 当前a下已找到最大可能的回文数，后续b更小无需检查
            }
        }
    }
    printf("%d\n", max_palin);
    return 0;
}

// 反转数字并返回
int reverse(int n) {
    int reversed = 0;
    while (n != 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}