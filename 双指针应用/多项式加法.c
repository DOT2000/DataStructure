/**
 *  @author 小粥无敌辣
 *  2023/10/3 11:34
 *  DataStructures
 */
#include <stdio.h>
#include <malloc.h>

typedef struct Node{
    int coefficient;//系数
    int index;//指数
    struct Node* next;
}Node;

Node* initLinkList(){
    Node* head = (Node*)malloc(sizeof(Node));
    head->coefficient = head->index = 0;
    head->next = NULL;
    return head;
}

void tailInsert(Node* head,int coefficient, int index){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->index = index;

    Node* current = head;
    while(current->next){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;

    head->coefficient++;
}

void freeList(Node* head){
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
        printf("%d and %d -> ",print->coefficient, print->index);
        print = print->next;
    }
    printf("NULL\n");
}

Node* polAddition(Node* pol1, Node* pol2){
    Node* newPol = initLinkList();//返回的新多项式
    Node* p = newPol;//跟随指针
    Node* delete = NULL;
    Node* num1 = pol1->next;
    Node* num2 = pol2->next;
    while(num1 && num2){
        if(num1->index > num2->index){
            p->next = num1;
            num1 = num1->next;
            p = p->next;
        }else if(num1->index < num2->index){
            p->next = num2;
            num2 = num2->next;
            p = p->next;
        }else {
            int coefficient = num2->coefficient + num1->coefficient;
            if (coefficient != 0) {
                p->next = num1;
                num1->coefficient = coefficient;
                delete = num2;
                num2 = num2->next;
                free(delete);
                num1 = num1->next;
                p = p->next;
            } else {
                delete = num1;
                num1 = num1->next;
                free(delete);
                delete = num2;
                num2 = num2->next;
                free(delete);
            }
            delete = NULL;
        }
    }
    if(num1){
        p->next = num1;
    }
    if(num2){
        p->next = num2;
    }
    return newPol;
}


int main(){
    Node* pol1 = initLinkList();
    Node* pol2 = initLinkList();
    tailInsert(pol1,3,8);
    tailInsert(pol1,-2,4);
    tailInsert(pol1,1,3);
    tailInsert(pol1,9,2);
    tailInsert(pol1,12,1);
    tailInsert(pol2,2,9);
    tailInsert(pol2,10,7);
    tailInsert(pol2,2,4);
    tailInsert(pol2,-1,3);
    tailInsert(pol2,2,2);

    Node* newPol = polAddition(pol1,pol2);

    printList(newPol);

    freeList(newPol);
    free(pol1);
    free(pol2);
    return 0;
}