/*************************************************************************
	> File Name: EP07-3.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Sun 23 Mar 2025 09:48:02 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdbool.h>  // 使用 bool 类型需要 C99 标准

#define MAX_N 100

int primes[MAX_N / 2 + 1];  // 存储质数的数组
bool is_composite[MAX_N + 1] = {false};  // 标记是否为合数

int main() {
    int count = 0;  // 已找到的质数数量

    for (int i = 2; i <= MAX_N; ++i) {
        // 如果i不是合数，则加入质数数组
        if (!is_composite[i]) {
            primes[count++] = i;
        }
        
        // 用当前数i与已知质数标记合数
        for (int j = 0; j < count && i * primes[j] <= MAX_N; ++j) {
            is_composite[i * primes[j]] = true;
            
            // 关键点：保证每个合数只被最小质因数标记一次
            if (i % primes[j] == 0) {
                break;
            }
        }
    }

    // 输出结果
    printf("2~100之间的质数共%d个：\n", count);
    for (int k = 0; k < count; ++k) {
        printf("%d ", primes[k]);
    }
    printf("\n");
    
    return 0;
}
