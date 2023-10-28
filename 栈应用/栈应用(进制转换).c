/**
 *  @author С���޵���
 *  2023/9/19 15:46
 *  DataStructures
 */
#include <stdio.h>
#include <stdbool.h>

bool baseConversion(int num,int base){
    if(base > 16 || base < 2){
        printf("����Ҫ����(2--16)����");
        return false;
    }
    char bases[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    char stack[num / base];
    int index = -1;
    while(num > 0){
        stack[++index] = bases[num % base];
        num /= base;
    }
    while(index >= 0){
        printf("%c",stack[index--]);
    }
    return true;
}