#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(long long n) {
    long long awnser = sqrt(n);
    
    while(awnser*awnser == n)
    {
        return (awnser+1)*(awnser+1);
    }
    
    
    return -1;
}

