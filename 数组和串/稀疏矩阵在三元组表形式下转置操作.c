/**
 *  @author 小粥无敌辣
 *  2023/10/5 13:31
 *  DataStructures
 */
/**
 * 这段程序实现了一个稀疏矩阵的转置操作。
 *   主要步骤包括:
 *       1. 定义Nums结构体,包含矩阵元素信息的数组和长度
 *       2. 初始化Nums,分配内存
 *       3. 添加矩阵元素到Nums
 *       4. 转置操作,遍历原矩阵,将列和行交换后添加到新矩阵
 *       5. 打印矩阵
 */
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#define MAXSIZE 100
typedef struct{
    int row;//行
    int col;//列
    int val;//值
}Node;

typedef struct{
    Node* num;
    int length;
}Nums;

Nums* initNums(){
    Nums* nums = (Nums*)malloc(sizeof(Nums));
    nums->length = 0;
    nums->num = (Node*)malloc(sizeof(Node) * MAXSIZE);
    return nums;
}

bool isFull(Nums* nums){
    if(nums->length == MAXSIZE){
        return true;
    }
    return false;
}

void addData(Nums* nums, int row, int col, int data){
    if(isFull(nums)){
        return;
    }
    nums->num[nums->length].row = row;
    nums->num[nums->length].col = col;
    nums->num[nums->length].val = data;
    nums->length++;
}
/**
 * 这段算法的缺点是，没有提前确定转置后每一行元素的数量，也就是没确定转置前每列元素的数量
 * 所以在转置过程中，只能依次遍历，判断原三元组表元素的列数是否符合条件
 * 导致时间复杂度是 O(m * n)
 * @param nums
 * @return
 */
Nums* transpose(Nums* nums){
    Nums* newNums = initNums();
    for (int i = 1; ; ++i) {
        for (int j = 0; j < nums->length; ++j) {
            if(nums->num[j].col == i){
                addData(newNums, nums->num[j].col, nums->num[j].row, nums->num[j].val);
            }
        }
        if(newNums->length == nums->length){
            break;
        }
    }
    return newNums;
}
/**
 * 这段程序利用额外的两段空间，创建了两个用于确定每一行元素数量的数组，使时间复杂度降低
 * 提前确定了每行元素的个数，并把指针记录下来，在遍历原三元组表的元素时无需进行判断
 * 直接根据其列数的值确定要填入的地址
 * 牺牲了一部分的空间换取时间。
 * @param nums
 * @param colNum
 * @return
 */
Nums* quickTranspose(Nums* nums, int colNum){
    Nums* newNums = initNums();
    int* start = (int*)calloc(colNum + 1, sizeof(int));
    int* rowLength = (int*)calloc(colNum + 1, sizeof(int));
    for (int i = 0; i < nums->length; ++i) {
        rowLength[nums->num[i].col]++;
    }
    for (int i = 2; i <= colNum; ++i) {
        start[i] = start[i - 1] + rowLength[i - 1];
    }
    for (int i = 0; i < nums->length; ++i) {
        int newRow = start[nums->num[i].col]++;
        newNums->num[newRow].row = nums->num[i].col;
        newNums->num[newRow].col = nums->num[i].row;
        newNums->num[newRow].val = nums->num[i].val;
        newNums->length++;
    }
    return newNums;
}

void ViewNums(Nums* nums){
    for (int i = 0; i < nums->length; ++i) {
        printf("%d %d %d\n",nums->num[i].row, nums->num[i].col, nums->num[i].val);
    }
    printf("\n");
}

int main(){
    Nums* nums = initNums();
    addData(nums, 1,1,50);
    addData(nums, 2,1,10);
    addData(nums, 2,3,20);
    addData(nums, 4,1,-30);
    addData(nums, 4,3,-60);
    addData(nums, 4,4,5);
    ViewNums(nums);

    Nums* newNums = quickTranspose(nums, 4);
    ViewNums(newNums);
    return 0;
}