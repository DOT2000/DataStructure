//
// Created by 小周 on 2023/9/13.
//
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* initQueue(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

void enQueue(Node* head,int data){
    Node* current = head;
    while(current->next){
        current = current->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = current->next;
    current->next = newNode;
    head->data++;
}

bool isEmpty(Node* head){
    if(head->data == 0 || head->next == NULL) {
        return true;
    }
    return false;
}

int deQueue(Node* head){
    if(isEmpty(head)){
        return false;
    }else{
        Node* pop = head->next;
        int data = pop->data;
        head->next = pop->next;
        free(pop);
        return data;
    }
}

void QueueView(Node* head){
    Node* view = head->next;
    while(view){
        printf("%d -> ",view->data);
        view = view->next;
    }
    printf("NULL\n");
}
