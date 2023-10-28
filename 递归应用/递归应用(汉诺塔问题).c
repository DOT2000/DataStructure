/**
 *  @author 小粥无敌辣
 *  2023/9/25 22:52
 *  DataStructures
 */
#include <stdio.h>

/**
 * 递归回溯形式算法
 *
 * @param num 盘子的数量
 * @param A A柱
 * @param B B柱
 * @param C C柱
 */
void HanoiTows(int num, char A, char B, char C){
    if(num > 1){
        HanoiTows(num - 1, A, C, B);//在A柱上的盘子数量多于一个时，看成两个整体，把上面(num-1)个盘子借助C柱移到B柱上，
        printf("%c -> %c\n",A,C);//然后把最大的盘子移到C柱
        HanoiTows(num - 1, B, A, C);//最后借助A柱把B柱上的(num-1)个盘子移到C柱上
    }else{
        printf("%c -> %c\n",A,C);//如果只有一个盘子，就直接从A移到C
    }
}
