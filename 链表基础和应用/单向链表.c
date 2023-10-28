#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

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

bool deleteNode(Node* head,int data){
    Node* pre = head;
    Node* current = head->next;
    while(current){
        if(current->data == data){
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

void freeListNode(Node* head){
    Node* delete;
    while(head->next){
        delete = head->next;
        head->next = head->next->next;
        free(delete);
    }
}

void printList(Node* head){
    Node* print = head->next;
    while(print){
        printf("%d -> ",print->data);
        print = print->next;
    }
    printf("NULL\n");
}

Node* findNode(Node* head,int data){
    Node* p = head->next;
    while(p && p->data != data){
        p = p->next;
    }
    return p;
}