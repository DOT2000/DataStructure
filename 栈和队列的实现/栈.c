//
// Created by 小周 on 2023/9/12.
//
#include <stdio.h>
#include <malloc.h>

#define true 1
#define false (-1)

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* initStack(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

void push(Node* head,int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head->next;
    head->next = newNode;
    head->data++;
}

int pop(Node* head){
    Node* current = head->next;
    if(current){
        head->next = current->next;
        int data = current->data;
        free(current);
        head->data--;
        return data;
    }
    return false;
}

void StackView(Node* head){
    Node* view = head->next;
    while(view){
        printf("%d -> ",view->data);
        view = view->next;
    }
    printf("NULL\n");
}
