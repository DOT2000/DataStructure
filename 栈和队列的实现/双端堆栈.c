/**
 *  @author 小粥无敌辣
 *  2023/10/3 10:54
 *  DataStructures
 */

#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

#define MAXSIZE 10

/**
*   两栈共享空间：使用一个数组来存储两个栈，让一个栈的栈底为该数组的始端，另一个栈的栈底为该数组的末端，两个栈从各自的端点向中间延伸。
*/
typedef struct {
    int* Stack;
    int top1;
    int top2;
}BothStack;

BothStack* initBothStack(){
    BothStack* bothStack = (BothStack*)malloc(sizeof(BothStack));
    bothStack->Stack = (int*)malloc(sizeof(int) * MAXSIZE);
    bothStack->top1 = -1;
    bothStack->top2 = MAXSIZE;
    return bothStack;
}

bool isEmpty(BothStack* bothStack, int num){
    if(num == 1){
        if(bothStack->top1 == -1){
            return true;
        }
        return false;
    }
    if(num == 2){
        if(bothStack->top2 == MAXSIZE){
            return true;
        }
        return false;
    }
    return false;
}

bool isFull(BothStack* bothStack){
    if(bothStack->top1 + 1 == bothStack->top2){
        return true;
    }
    return false;
}

void pushBothStack(BothStack* bothStack, int num, int data){
    if(num != 1 && num != 2) {
        return;
    }
    if(isFull(bothStack)){
        return;
    }
    if(num == 1){
        bothStack->Stack[++bothStack->top1] = data;
    }
    if(num == 2){
        bothStack->Stack[--bothStack->top2] = data;
    }
}

int popBothStack(BothStack* bothStack, int num){
    int ret = -1;
    if(num != 1 && num != 2){
        return ret;
    }
    if(isEmpty(bothStack, num)){
        return ret;
    }

    if(num == 1){
        ret = bothStack->Stack[bothStack->top1--];
    }
    if(num == 2){
        ret = bothStack->Stack[bothStack->top2++];
    }

    return ret;
}

void BothStackView(BothStack* bothStack, int num){
    if(num != 1 && num != 2){
        return;
    }
    if(isEmpty(bothStack, num)){
        return;
    }

    if(num == 1){
        for (int i = 0; i <= bothStack->top1; ++i) {
            printf("%d -> ",bothStack->Stack[i]);
        }
    }
    if(num == 2){
        for (int i = MAXSIZE - 1; i >= bothStack->top2; --i) {
            printf("%d -> ",bothStack->Stack[i]);
        }
    }
    printf("NULL\n");
}