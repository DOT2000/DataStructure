#include <string.h>
#include <malloc.h>
#include <stdbool.h>

/**
 *  @author 小粥无敌辣
 *  2023/9/19 16:38
 *  DataStructures
 */

bool isLeft(char c){
    if(c == '{' || c == '[' || c == '('){
        return true;
    }
    return false;
}

bool priority(char operator,char stack){
    if(operator == '*' || operator == '/'){
        if(stack == '+' || stack == '-'){
            return true;
        }
    }
    return false;
}

bool isRight(char c){
    if(c == '}' || c == ']' || c == ')'){
        return true;
    }
    return false;
}
/*
 * 该函数实现了将中缀表达式转换为后缀表达式 ---> 不足之处是只能处理操作数是变量的表达式
 * 每个元素最多进栈1次、出栈1次、入队1次
 *      时间复杂度O(n)
 */
char* infixToSuffix(char* s){
    int length = strlen(s);
    char* operatorStack = (char*)malloc(length * sizeof(char));
    int stackIndex = -1;
    char* Suffix = (char*)malloc((length + 1) * sizeof(char));
    int index = 0;
    for(int i = 0;i < length;++i){
        if(isLeft(s[i])){
            operatorStack[++stackIndex] = s[i];
        }else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            if(stackIndex < 0 || isLeft(operatorStack[stackIndex]) || priority(s[i],operatorStack[stackIndex])){
                operatorStack[++stackIndex] = s[i];
            }else if(!(priority(s[i],operatorStack[stackIndex]))){
                while(!(priority(s[i],operatorStack[stackIndex])) && !(isLeft(operatorStack[stackIndex])) && stackIndex >= 0){
                    Suffix[index++] = operatorStack[stackIndex--];
                }
                if(isLeft(operatorStack[stackIndex])){
                    stackIndex--;
                }
                operatorStack[++stackIndex] = s[i];
            }
        }else if(isRight(s[i])){
            while(!(isLeft(operatorStack[stackIndex]))){
                Suffix[index++] = operatorStack[stackIndex--];
            }
            stackIndex--;
        }else if(s[i] == ';'){
            while(stackIndex >= 0){
                Suffix[index++] = operatorStack[stackIndex--];
            }
        }else{
            Suffix[index++] = s[i];
        }
    }
    Suffix[index] = '\0';

    return Suffix;
}
/*
 * 改进之处：为了实现操作数可以是具体的数字，我们可以用两个栈来分别保存操作数和运算符，
 * 操作数栈的类型是 int ，运算符栈的类型是 char 。
 *
 * 另外：如果一个式子中的操作数既有变量也有具体的数字，该怎么办？
 * 可以使用侵入式链表形成队列，每个节点存储不同的元素，可以实现操作数类型多样，同时操作数和运算符可以存储在一起，形成完整的后缀表达式。
 */