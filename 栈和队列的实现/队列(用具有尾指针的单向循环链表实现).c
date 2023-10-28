//
// Created by 小周 on 2023/9/16.
//
/**
 * 使用具有尾指针的单向循环链表可以实现入队出队操作的时间复杂度都是 O(1)
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* initQueue(){
    Node* tail = (Node*)malloc(sizeof(Node));
    tail->data = 0;
    tail->next = tail;
    return tail;
}

Node* enQueue(Node* tail,int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = tail->next;
    tail->next = newNode;
    newNode->next->data++;
    return newNode;
}

bool isEmpty(Node* tail){
    if(tail->next->data == 0 || tail->next == tail){
        return true;
    }
    return false;
}

int deQueue(Node* tail){
    if(isEmpty(tail)){
        return false;
    }

    int data = tail->next->next->data;
    Node* delete = tail->next->next;
    tail->next->next = tail->next->next->next;
    free(delete);
    tail->next->data--;
    return data;
}

void viewQueue(Node* tail){
    Node* view = tail->next->next;
    while(view != tail->next){
        printf("%d -> ",view->data);
        view = view->next;
    }
    printf("NULL\n");
}

int main(){
    Node* tail = initQueue();
    tail = enQueue(tail,1);
    tail = enQueue(tail,2);
    tail = enQueue(tail,3);
    tail = enQueue(tail,4);
    tail = enQueue(tail,5);

    viewQueue(tail);

    printf("%d\n",deQueue(tail));
    viewQueue(tail);
    printf("%d\n",deQueue(tail));
    viewQueue(tail);
    printf("%d\n",deQueue(tail));
    viewQueue(tail);
    printf("%d\n",deQueue(tail));
    viewQueue(tail);
    printf("%d\n",deQueue(tail));
    viewQueue(tail);
    return 0;
}