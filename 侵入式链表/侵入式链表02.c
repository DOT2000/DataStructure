/**
 *  @author 小粥无敌辣
 *  2023/9/18 20:30
 *  DataStructures
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define LIST_POISON1  ((void *) 0x00100100)
#define LIST_POISON2  ((void *) 0x00200200)

struct list_head {
    struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }

/*
 *   创建一个新的链表。是新链表头的占位符，并且是一个哑元素。
 *    同时初始化prev和next字段，让它们指向list_name变量本身。
*/
#define LIST_HEAD(name) \
        struct list_head name = LIST_HEAD_INIT(name)

#define INIT_LIST_HEAD(ptr) do { \
        (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)


#define container_of(ptr, type, member) ({                   \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);  \
        (type *)( (char *)__mptr - offsetof(type,member));})

/*
 * 返回链表所在结点
 *
*/
#define list_entry(ptr, type, member) \
        container_of(ptr, type, member)
/*
 * 扫描指定的链表
*/
#define list_for_each(pos, head) \
        for (pos = (head)->next; pos != (head); pos = pos->next)

static inline void __list_add(struct list_head *new,
                              struct list_head *prev,
                              struct list_head *next)
{
    next->prev = new;
    new->next = next;
    new->prev = prev;
    prev->next = new;
}

/*
 * 把元素插入特定元素之后
*/
static inline void list_add(struct list_head *new, struct list_head *head)
{
    __list_add(new, head, head->next);
}

/*
 * 把元素插到特定元素之前。
*/
static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
    __list_add(new, head->prev, head);
}

static inline void __list_del(struct list_head * prev, struct list_head * next)
{
    next->prev = prev;
    prev->next = next;
}

/*
 * 删除特定元素
*/
static inline void list_del(struct list_head *entry)
{
    __list_del(entry->prev, entry->next);
    entry->next = LIST_POISON1;
    entry->prev = LIST_POISON2;
}

/*
 * 检查指定的链表是否为空
*/
static inline int list_empty(const struct list_head *head)
{
    return head->next == head;
}

typedef struct fox {
    int data;
    struct list_head list;
} fox_t;

int main(int argc, char *argv[])
{
    int i;
    fox_t red_fox[10];
    fox_t *node;
    struct list_head *pos;

    /*初始化链表*/
    LIST_HEAD(foxlist);
    INIT_LIST_HEAD(&foxlist);

    /*判断链表是否为空*/
    if (list_empty(&foxlist))
        printf("list is empty\n");

    /*插入节点*/
    for (i = 0; i < 10; i++)
    {
        red_fox[i].data = i + 1;
        list_add_tail(&red_fox[i].list, &foxlist);
    }

    printf("[ ");
    list_for_each(pos, &foxlist) {
        node = list_entry(pos, fox_t, list);
        printf("%d ", node->data);
    }
    printf("]\n");

    /*删除节点*/
    list_del(&red_fox[5].list);
    printf("[ ");
    list_for_each(pos, &foxlist) {
        node = list_entry(pos, fox_t, list);
        printf("%d ", node->data);
    }
    printf("]\n");

    /*判断链表是否为空*/
    if (!list_empty(&foxlist))
        printf("list is not empty\n");
    return 0;
}