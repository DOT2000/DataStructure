//
// Created by 小周 on 2023/9/15.
//

/**
 * 使用循环存储来实现循环队列，用头尾指针以牺牲一个存储空间的方式来判断队列是否已满。
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 6   //正如注释所言，最大空间是6个，但是最多只能存储5个整数，需要牺牲一个空间来实现判断队列是否已满。

typedef struct Queue {
    int rear;
    int front;
    int data[MAXSIZE];
}Queue;

Queue* initQueue(){
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = queue->rear = 0;
    return queue;
}

bool isFull(Queue* queue){
    if((queue->rear + 1) % MAXSIZE == queue->front){
        return true;
    }
    return false;
}

bool isEmpty(Queue* queue){
    if(queue->front == queue->rear){
        return true;
    }
    return false;
}

bool enQueue(Queue* queue,int data){
    if(isFull(queue)){
        return false;
    }

    queue->data[queue->rear] = data;
    queue->rear = (queue->rear + 1) % MAXSIZE;
    return true;
}

int deQueue(Queue* queue){
    if(isEmpty(queue)){
        return false;
    }

    int data = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAXSIZE;
    return data;
}
/**
 * 返回队列长度
 * @param queue
 * @return
 */
int queueSize(Queue* queue){
    return ((queue->rear - queue->front + MAXSIZE) % MAXSIZE);
}

bool viewQueue(Queue* queue){
    if(isEmpty(queue)){
        printf("NULL");
        return false;
    }
    for (int i = queue->front; i < queue->rear; i = (i + 1) % MAXSIZE) {
        printf("%d -> ",queue->data[i]);
    }
    printf("NULL\n");
    return true;
}

int main(){
    Queue* queue = initQueue();
    enQueue(queue,1);
    enQueue(queue,2);
    enQueue(queue,3);
    enQueue(queue,4);
    enQueue(queue,5);
    viewQueue(queue);
    printf("%d\n", deQueue(queue));
    viewQueue(queue);
    printf("size = %d\n", queueSize(queue));
    printf("%d\n", deQueue(queue));
    printf("%d\n", deQueue(queue));
    return 0;
}