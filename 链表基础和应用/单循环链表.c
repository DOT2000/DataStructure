//
// Created by 小周 on 2023/9/12.
//
#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* initLinkList(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = head;
    return head;
}

void headInsert(Node* head,int date){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = date;
    newNode->next = head->next;
    head->next = newNode;
    head->data++;
}

void tailInsert(Node* head,int date){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = date;

    Node* current = head;
    while(current->next != head){
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    head->data++;
}

int deleteNode(Node* head,int date){
    Node* pre = head;
    Node* current = head->next;
    while(current != head){
        if(current->data == date){
            pre->next = current->next;
            free(current);
            head->data--;
            return true;
        }
        pre = current;
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