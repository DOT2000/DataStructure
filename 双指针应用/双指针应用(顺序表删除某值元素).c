#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

/**
 *  @author 小粥无敌辣
 *  2023/9/20 20:01
 *  DataStructures
 */
#define MAXSIZE 15
//已知长度为n的线性表A采用顺序存储结构，请编写尽可能高效的算法，删除该线性表中所有值为item的数据元素
typedef struct {
    int* array;
    int length;
}LArray;

LArray* initLArray(){
    LArray* nums = (LArray*)malloc(sizeof(LArray));
    nums->array = (int*) malloc(sizeof(int) * MAXSIZE);
    nums->length = 0;
    return nums;
}


bool addLArray(LArray* nums,int data){
    if(nums->length == MAXSIZE){
        return false;
    }
    nums->array[nums->length++] = data;
    return true;
}
/**
 * 双指针的应用，把需要留下的元素按照顺序从头开始填补数组
 * @param nums
 * @param item
 * @return
 */
LArray* deleteArray(LArray* nums,int item){
    int j = 0;
    for(int i = 0;i < nums->length;++i){
        if(nums->array[i] != item) {
            nums->array[j++] = nums->array[i];
        }
    }
    nums->length = j;
    return nums;
}

void printLArray(LArray* nums){
    if(nums->length > 0){
        for (int i = 0; i < nums->length; ++i) {
            printf("%d\t",nums->array[i]);
        }
        printf("\n");
    }
}
