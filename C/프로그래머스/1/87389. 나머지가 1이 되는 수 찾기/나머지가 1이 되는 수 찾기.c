#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
int i = 1;
    for(; n % i != 1; i++)
    {}
    return i;
}