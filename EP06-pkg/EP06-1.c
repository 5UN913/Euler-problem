#include <stdio.h>

int main() {
    int sum_sq = 5050 * 5050;
    int sq_sum = 0;
    for (int i = 1; i < 101; i++) {
        sq_sum += (i * i);
    }
    printf("%d\n", sum_sq - sq_sum);
    return 0;
}
