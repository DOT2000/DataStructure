//
// Created by 小周 on 2023/9/15.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    char data;
    struct Node* next;
}Node;

Node* initStack(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

void push(Node* head,char data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head->next;
    head->next = newNode;
    head->data++;
}

bool isEmpty(Node* head){
    if(head->next == NULL || head->data == 0){
        return true;
    }
    return false;
}

char pop(Node* head){
    if(isEmpty((head))){
        printf("栈为空，弹出失败。");
        return 0;
    }
    Node* current = head->next;
    head->next = current->next;
    char ret = current->data;
    free(current);
    return ret;
}

char peek(Node* head){
    if(isEmpty(head)){
        printf("栈为空");
        return 0;
    }
    return head->next->data;
}
/*
 * 过关斩将的思想进行条件判断，不符合条件的情况尽早返回，退出函数。
 */
bool isMatch(Node* head,char* string,int Size){
    for (int i = 0; i < Size; ++i) {
        if(string[i] == '{' || string[i] == '(' || string[i] == '['){
            push(head, string[i]);
        }
        if(string[i] == '}' || string[i] == ')' || string[i] == ']'){
            if(isEmpty(head)){
                return false;
            }

            if(string[i] == '}' && peek(head) == '{' || string[i] == ']' && peek(head) == '[' || string[i] == ')' && peek(head) == '('){
                pop(head);
            }else{
                return false;
            }
        }
    }
    if(!isEmpty(head)){
        return false;
    }
    return true;
}

int main(){
    Node* head = initStack();
    char string[100] = "";
    scanf("%s",string);
    printf("%d", isMatch(head,string,sizeof(string)/sizeof(string[0])));
    return 0;
}