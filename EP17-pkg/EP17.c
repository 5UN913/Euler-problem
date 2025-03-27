/*************************************************************************
	> File Name: EP17.c
	> Author:shenxihan
	> Mail: 207165519@qq.com
	> Created Time: Thu 27 Mar 2025 10:56:27 AM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int units_and_teens[] = {0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8};
    int tens_count[] = {0,0,6,6,5,5,5,7,6,6};
    int sum = 0;
    for (int n = 1; n <= 1000; n++) {
        if (n == 1000) {
            sum += 11;
        } else {
            int hundreds = n / 100;
            int remainder = n % 100;
            int current = 0;
            if (hundreds > 0) {
                current += units_and_teens[hundreds] + 7;
                if (remainder != 0) {
                    current += 3;
                }
            }
            if (remainder != 0) {
                if (remainder < 20) {
                    current += units_and_teens[remainder];
                } else {
                    int tens_part = remainder / 10;
                    int units_part = remainder % 10;
                    current += tens_count[tens_part] + units_and_teens[units_part];
                }
            }
            sum += current;
        }
    }
    printf("%d\n", sum);
    return 0;
}
