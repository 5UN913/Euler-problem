/*************************************************************************
	> File Name: EP14.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Wed 26 Mar 2025 04:45:42 PM CST
 ************************************************************************/

#include <stdio.h>
#define MAX_N 1000000

int main() {
    int len = 0, max_len = 0, best_num = 0;
    for (int i = 2; i <= MAX_N; i++) {
        len = 0;
        long long num = i;
        while (num != 1) {
            if (num % 2 == 0) num = num / 2;
            else num = 3 * num + 1;
            len += 1;
        }
        if (len > max_len) {
            max_len = len;
            best_num = i;
        }
    }
    printf("%d, %d", max_len, best_num);
    return 0;
}
