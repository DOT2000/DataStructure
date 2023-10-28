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
    head->pre = NULL;
    head->next = NULL;
    return head;
}

void headInsert(Node* head,int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head->next;
    newNode->pre = head;
    if(head->next){
        head->next->pre = newNode;
    }
    head->next = newNode;
    head->data++;
}

void tailInsert(Node* head,int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    Node* current = head;
    while(current->next){
        current = current->next;
    }

    newNode->next = current->next;
    newNode->pre = current;
    current->next = newNode;

    head->data++;
}

int deleteNode(Node* head,int data){
    Node* current = head->next;
    while(current){
        if(current->data == data){
            if(current->next){
                current->pre->next = current->next;
                current->next->pre = current->pre;
            }else{
                current->pre->next = current->next;
            }
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
    while(printQueen){
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