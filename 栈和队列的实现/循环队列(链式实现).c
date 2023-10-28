//
// Created by 小周 on 2023/9/13.
//
#include <stdio.h>
#include <stdlib.h>
/**
 * 循环队列使用双向循环链表实现，说白了就是双向循环链表的部分基本操作
 */

/**
 * define the node of queue
 */
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* pre;
}Node;

/**
 * init queue
 * @return the head pointer of queue
 */
Node* initQueue() {
    Node* Q = (Node*)malloc(sizeof(Node));
    Q->data = 0;
    Q->pre = Q->next = Q;
    return Q;
}

/**
 * enqueue
 * @param Q the head pointer of queue
 * @param data the data you want to enqueue
 */
void enQueue(Node* Q, int data) {   //其实就是双向循环链表中的尾插实现方法
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = Q;
    node->pre = Q->pre;
    Q->pre->next = node;    //这行代码在只有一个Q节点的时候修改了Q节点的next指针值
    Q->pre = node;
    Q->data++;
}

/**
 * judge queue is or not empty
 * @param Q the head pointer of queue
 * @return empty flag
 */
int isEmpty(Node* Q) {
    if (Q->data == 0 || Q->next == Q) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * dequeue
 * @param Q the head pointer of queue
 * @return the data of dequeue
 */
int deQueue(Node* Q) {
    if (isEmpty(Q)) {
        return 0;
    } else {
        Node* node = Q->next;
        Q->next = Q->next->next;
        Q->next->pre = Q;
        int data = node->data;
        free(node);
        return data;
    }
}

/**
 * printQueen all item in queue
 * @param Q the head pointer of queue
 */
void printQueue(Node* Q) {
    Node* node = Q -> next;
    while (node != Q) {
        printf("%d -> ", node -> data);
        node = node -> next;
    }
    printf("NULL\n");
}
