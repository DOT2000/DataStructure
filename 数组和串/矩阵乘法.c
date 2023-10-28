#include <malloc.h>
#include <stdio.h>

/**
 *  @author 小粥无敌辣
 *  2023/10/2 16:21
 *  DataStructures
 */
int** MatrixMul(int** nums1,int** nums2,int nums1Size,int p,int nums2ColSize){
    int** ret = (int**)malloc(sizeof(int*) * nums1Size);
    for (int i = 0; i < nums1Size; ++i) {
        ret[i] = (int*)calloc(nums2ColSize,sizeof(int));
    }
    for (int i = 0; i < nums1Size; ++i) {
        for (int j = 0; j < nums2ColSize; ++j) {
            for (int k = 0; k < p; ++k) {
                ret[i][j] += nums1[i][k] * nums2[k][j];
            }
        }
    }
    return ret;
}

int main(){
    int nums1Size = 3;
    int nums2ColSize = 3;
    int p = 2, num;
    int** nums1 = (int**)malloc(sizeof(int) * nums1Size);
    printf("输入第一个矩阵的值");
    for (int i = 0; i < nums1Size; ++i) {
        nums1[i] = (int*)calloc(p,sizeof(int));
        for (int j = 0; j < p; ++j) {
            scanf("%d",&num);
            nums1[i][j] = num;
        }
    }
    printf("输入第二个矩阵的值");
    int** nums2 = (int**)malloc(sizeof(int) * p);
    for (int i = 0; i < p; ++i) {
        nums2[i] = (int*)calloc(nums2ColSize,sizeof(int));
        for (int j = 0; j < nums2ColSize; ++j) {
            scanf("%d",&num);
            nums2[i][j] = num;
        }
    }
    int** matrixMul = MatrixMul(nums1,nums2,nums1Size,p,nums2ColSize);
    for (int i = 0; i < nums1Size; ++i) {
        for (int j = 0; j < nums2ColSize; ++j) {
            printf("%d\t",matrixMul[i][j]);
        }
        printf("\n");
    }
    return 0;
}