//
// Created by 小周 on 2023/9/16.
//

#include <malloc.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* initLinkList(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

void headInsert(Node* head,int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head->next;
    head->next = newNode;
    head->data++;
}

Node* reverseList(Node* head){
    Node* pre = NULL;
    Node* curr = head;
    Node* nextNode = NULL;
    while(curr){
        nextNode = curr->next;
        curr->next = pre;
        pre = curr;
        curr = nextNode;
    }
    return pre;
}