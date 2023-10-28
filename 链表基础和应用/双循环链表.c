//
// Created by 小周 on 2023/9/12.
//
#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0

typedef struct Node{
    int data;
    struct Node* pre;
    struct Node* next;
}Node;

Node* initLinkList(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->pre = head->next = head;
    return head;
}

void headInsert(Node* head,int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head->next;
    newNode->pre = head;
    head->next->pre = newNode;
    head->next = newNode;
    head->data++;
}

/*
 * 双向循环链表的尾插操作不需要再进行遍历
 */
void tailInsert(Node* head,int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->pre = head->pre;
    head->pre->next = newNode;
    newNode->next = head;
    head->pre = newNode;

    head->data++;
}

int deleteNode(Node* head,int data){
    Node* current = head->next;
    while(current != head){
        if(current->data == data){
            current->next->pre = current->pre;
            current->pre->next = current->next;
            free(current);
            head->data--;
            return true;
        }
        current = current->next;
    }
    return false;
}

void printList(Node* head){
    Node* printQueen = head->next;
    while(printQueen != head){
        printf("%d -> ",printQueen->data);
        print = printQueen->next;
    }
    printf("NULL\n");
}

int main(){
    Node* head = initLinkList();
    headInsert(head,1);
    headInsert(head,2);
    headInsert(head,3);
    headInsert(head,4);
    tailInsert(head,5);
    tailInsert(head,6);
    tailInsert(head,7);
    tailInsert(head,8);
    tailInsert(head,9);
    printList(head);
    deleteNode(head,1);
    deleteNode(head,3);
    deleteNode(head,5);
    deleteNode(head,7);
    printList(head);
    return 0;
}