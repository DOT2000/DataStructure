//
// Created by 小周 on 2023/9/16.
//
/**
 * JLU数据结构课本上BS算法的非递归形式实现
 * 自己创建一个顺序栈模拟递归进程
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int max;
    int min;
} Result;
/*
 * 这个程序的功能是寻找一个数组中的最大值和最小值
 */
Result* initResult(){
    Result* res = (Result*)malloc(sizeof(Result));
    res->min = res->max = 0;
    return res;
}

Result* binarySelect(const int A[], int i, int j) {
    Result* res = initResult();

    if (i == j) { //只有一个元素
        res->max = res->min = A[i];
        return res;
    }

    if (i == j - 1) { //有两个元素
        if (A[i] < A[j]) {
            res->max = A[j];
            res->min = A[i];
        } else {
            res->max = A[i];
            res->min = A[j];
        }
        return res;
    }

    // 创建一个栈来存储子数组范围
    int stack[j - i + 1];
    int top = -1;// 这里为什么要用-1作为初始值，并且使用前++来进行下标移动，是因为可以方便的判断何时栈空。

    // 将初始子数组范围压入栈
    stack[++top] = i;
    stack[++top] = j;

    // 在循环中处理子数组，直到栈为空
    while (top >= 0) {
        // 从栈中弹出子数组范围
        j = stack[top--];
        i = stack[top--];

        if (i == j) { // 基本情况：只有一个元素
            res->max = (res->max > A[i]) ? (res->max) : A[i];
            res->min = (res->min < A[i]) ? (res->min) : A[i];

        } else if (i == j - 1) { // 基本情况：有两个元素
            if (A[i] < A[j]) {
                res->max = (res->max > A[j]) ? (res->max) : A[j];
                res->min = (res->min < A[i]) ? (res->min) : A[i];
            } else {
                res->max = (res->max > A[i]) ? (res->max) : A[i];
                res->min = (res->min < A[j]) ? (res->min) : A[j];
            }
        } else {
            int mid = (i + j) / 2;

            // 将右侧子数组范围压入栈
            stack[++top] = mid + 1;
            stack[++top] = j;

            // 将左侧子数组范围压入栈
            stack[++top] = i;
            stack[++top] = mid;
        }
    }

    return res;
}