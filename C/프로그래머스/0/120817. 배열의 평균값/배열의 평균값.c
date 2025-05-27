#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
double solution(int numbers[], size_t numbers_len) {
    double A = 0;
    for(int i = 0; numbers_len > i; i++ )
    {
        A += numbers[i];
    }
    return A / numbers_len;
}