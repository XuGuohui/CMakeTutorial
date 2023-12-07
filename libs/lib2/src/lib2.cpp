#include <stdio.h>
#if USE_STD_ACCUMULATE
#include <numeric>
#endif
#include "lib2.h"

int myPlus(int num1, int num2) {
    int sum = 0;

#if USE_STD_ACCUMULATE
    printf("Use std::accumulate()\n");
    int arr[3] = {num1, num2};
    sum = std::accumulate(&arr[0], &arr[2], 0);
#else
    printf("Use num1 + num2\n");
    sum = num1 + num2;
#endif

    printf("%d + %d = %d\n", num1, num2, sum);
    return sum;
}
