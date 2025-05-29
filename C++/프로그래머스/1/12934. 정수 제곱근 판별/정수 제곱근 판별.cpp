#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long solution(long long n) {
    long long anwser = sqrt(n);
    
    if(anwser*anwser == n)
    {
        return pow(anwser+1, 2);
    }
    return -1;
}

