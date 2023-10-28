//
// Created by 小周 on 2023/9/16.
//
#include <stdio.h>
#include <stdlib.h>
#include <intrin.h>

int* mergeArray(int* nums1,int nums1Size,int* nums2,int nums2Size){
    int* ret = (int*) malloc(sizeof(int) * (nums1Size + nums2Size));
    int index = 0;
    int index1 = 0;
    int index2 = 0;

    while(index1 < nums1Size && index2 < nums2Size){
        if(nums1[index1] <= nums2[index2]){
            ret[index++] = nums1[index1++];
        }else{
            ret[index++] = nums2[index2++];
        }
    }

    if(index1 < nums1Size){
        memcpy(&ret[index],&nums1[index1],sizeof(int) * (nums1Size - index1));
    }
    if(index2 < nums2Size){
        memcpy(&ret[index],&nums2[index2],sizeof(int) * (nums2Size - index2));
    }

    return ret;
}

int main(){
    int nums1[6] = {1,4,6,8,10,13};
    int nums2[7] = {0,2,3,7,12,15,18};
    int* ret = mergeArray(nums1,6,nums2,7);
    for (int i = 0; i < 13; ++i) {
        printf("%d\t",ret[i]);
    }
    return 0;
}