/**
 *  @author 小粥无敌辣
 *  2023/9/25 22:12
 *  DataStructures
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * 初始化棋盘
 * @param num
 * @return Queen
 */
int* initQueen(int num){
    return (int*)calloc(num,sizeof(int));
}

/**
 *
 * @param Queue  棋盘
 * @param i  目前要进行放置的行
 * @param j  目前要进行放置的列
 * @return
 */
bool isFeasible(const int* Queue,int i,int j){
    for (int k = 0; k < i; ++k) {
        if(Queue[k] == j || abs(k - i) == abs(Queue[k] - j)){
            return false;
        }
    }
    return true;
}

void printQueen(int* Queue, int length){
    for (int i = 0; i < length; ++i) {
        printf("%d -> ",Queue[i]);
    }
    printf("end\n");
}

void queenIsRight(int* Queen,int maxNum,int i){
    if(i == maxNum){
        printQueen(Queen, maxNum);
        return;
    }else{
        for (int j = 0; j < maxNum; ++j) {//判断一行中的每一列
            if(isFeasible(Queen,i,j)){
                Queen[i] = j;
                queenIsRight(Queen,maxNum,i + 1);//行数在递归调用时递增
            }
        }
    }
}
