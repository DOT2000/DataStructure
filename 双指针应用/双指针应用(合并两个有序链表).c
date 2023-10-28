//
// Created by 小周 on 2023/9/16.
//
#include <stdio.h>
#include <stdlib.h>

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


void tailInsert(Node* head,int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;

    Node* current = head;
    while(current->next){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;

    head->data++;
}


void printList(Node* head){
    Node* print = head->next;
    while(print){
        printf("%d -> ", print->data);
        print = print->next;
    }
    printf("NULL\n");
}


Node* mergeList(Node* list1,Node* list2){
    Node* ret = list1;
    Node* p = ret;
    ret->data = ret->data + list2->data;
    Node* p1 = list1->next;
    Node* p2 = list2->next;

    while(p1 && p2){
        if(p1->data <= p2->data){
            p->next = p1;
            p1 = p1->next;
        }else{
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
    }

    if(p1){
        p->next = p1;
    }
    if(p2){
        p->next = p2;
    }
    free(list2);
    return ret;
}