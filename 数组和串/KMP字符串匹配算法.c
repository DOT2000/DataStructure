#include <malloc.h>
#include <string.h>

/**
 *  @author 小粥无敌辣
 *  2023/9/21 15:27
 *  DataStructures
 */

/**
 * 思路分析：
 *      如何来获取模式串的next数组？
 *      1. 首先显而易见的是，next数组的长度与模式串应该是一样的，因为在每个位置都有可能出现匹配不成功的情况，我们就要把子串的指针跳转到相应的快速匹配位置。
 *      2. 每个模式串的前两个字符的next值都是一样的，next[0] = -1; next[1] = 0;    -1表示主串的指针也要向后移动了。
 *      3. 在此基础上，我们讨论next值的递推关系：如何通过前一个已经求出的next值来得到目前这个位置上的next值
 *      4. 假设我们的模式串是这个字符串：  a  b  a  b  a  b  c  a  b  c  d
 *                        next数组    -1  0  0  1  2  3  4  0  1  2  0
 *         我们应该如何分析？    因为当 j = -1 的时候，表示模式串的第一个字符也没有办法和主串此时的字符匹配成功了，那么我们就需要同时移动主串和模式串的指针，
 *                            而反映在next数组中的话，需要把 j 调整为有效的数组下标，而此时也不需要 i 索引位置的字符进行递推比较了，所以 i 和 j 都加 1，填入next数组
 *                            现在讲一下为什么要判断 j 索引位置的字符和 i 索引位置的字符是否相等：（因为我们要根据前一个字符的值以及它的next值，求下一个字符的next）
 *                  a  b  a  b  a  b  c  a  b  c  d
 *                              ^             例如在此位置发生了模式不匹配,即要求得此位置的next数组值
 *                     ^     ^                则，上一个 b 字符的next值为 1 ，所以此时 i 指向 b ，j 指向 1 处的 b
 *                     j     i                这个指向的意思是如果在 b 处发生了不匹配，会把指针移到 1 索引处，形成快速匹配状态。
 *                  ^     ^                   原因是第一个 a 和第二个 a 形成快速匹配
 *                       j++   i++            而我们此时比较 i 指向的字符和 j 指向的字符，如果两者相等，那么 i 指向的字符的下一个字符的公共前后缀
 *                                            是不是就要比此时 i 指向的字符的公共前后缀的长度大 1 位，所以要执行 i 和 j 同时加 1 ，并填入next数组
 *
 *                  a  b  a  b  a  b  c  a  b  c  d     但是如果两者不相等了怎么办？
 *                              ^     ^  |              例如现在要求 | 位置的 a 的next值
 *                              j     i                 它的前一位next已经求出来了，为 4 ，但是 a 和 c 不相等啊，无法形成公共前后缀长度加 1 可得的美好结果
 *                                                      那么我们不应该直接放弃，又回到最初开始去比较了，我们应该试一试 a 的next索引处的字符是否能形成快速匹配
 *                                                      若P[i] != P[j]，则需要回溯，找到更短的前缀和后缀，直到找到相等的字符或回溯到开头。
 *
 *                  a  b  a  b  a  b  c  a  b  c  d     因为 a 也有自己的公共前后缀：a 前面的子串也形成了一部分的快速对应，只是前缀到 a 这个长度的位置的时候要进行判断了
 *                  ----  ----  ^     ^  |
 *                   跳转  ^                             然后就按照这个逻辑继续与 i 指向的字符进行比较，如果直到 j = -1 时都没相同，那只好从头开始了。
 *
 *                   最后还有两个很重要的可以帮助理解的规律哦：
 *                              1、next数组的值每次最多增加 1 ，因为每次向后移动了一位，那么前后缀的重合数最大值加一
 *                              2、模式串的最后一位字符不影响next数组的结果
 * @param subString
 * @param length
 * @return 模式串的next数组
 */
int* getNext(const char* subString,int length){
    int* next = (int*)malloc(sizeof(int) * length);
    int i = 0;
    int j = -1;
    next[i] = j;//第一位的next值一定为 -1
    while(i < length - 1){//第一位已经确定，只剩下 length - 1 位了
        if(j == -1 || subString[i] == subString[j]){
            i++;
            j++;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
    return next;
}

int strStr(char * haystack, char * needle){
    int length1 = strlen(haystack);
    int length2 = strlen(needle);
    int* next = getNext(needle,length2);
    int i = 0,j = 0;
    while(i < length1 && j < length2){
        if(j == -1 || haystack[i] == needle[j]){//如果 j = -1 ，避免陷入死循环，要提醒主串指针也向后移动了
            i++;
            j++;
        }else{
            j = next[j];
        }
    }

    if(j == length2)    return i - j;
    return -1;
}