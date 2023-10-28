/**
 *  @author 小粥无敌辣
 *  2023/9/18 20:12
 *  DataStructures
 */
#ifndef DATASTRUCTURES_LINK_LIST_H
#define DATASTRUCTURES_LINK_LIST_H

/*
 * C语言中有这样一个宏offsetof，它的作用是计算结构体成员相对于结构体的偏移
 * 参数说明:
 *      type：结构体类型
 *      member：结构体成员
 * 原理分析：
 *      偏移 = 成员地址 - 结构体地址，若结构体地址为0，则偏移 = 成员地址；
 */

#define offset_of(type, member) ((unsigned long) &((type*)0)->member)

/*
 * C语言中有这样一个宏container_of，
 * 它的作用是通过结构体的成员，结构体成员的地址以及结构体的类型来获取结构体的首地址，
 * 参数说明:
 *      ptr：结构体成员的地址
 *      type：结构体类型
 *      member：结构体成员--->会自动判断是否是结构体中的成员，无需通过结构体名 . 引用
 * 原理分析：
 *      结构体首地址 = 成员地址 - 成员偏移，成员偏移通过offsetof宏求出；
 */
#define container_of(ptr, type, member) ({          \
     const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
     (type *)( (char *)__mptr - offset_of(type,member) );})


typedef struct list_structure
{
    struct list_structure* next;
    struct list_structure* prev;
}ListObj;


#define LIST_HEAD_INIT(name)    {&(name), &(name)}
#define LIST_HEAD(name)         ListObj name = LIST_HEAD_INIT(name)


#define list_entry(node, type, member) \
    container_of(node, type, member)


#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)


#define list_for_each_safe(pos, n, head) \
  for (pos = (head)->next, n = pos->next; pos != (head); \
    pos = n, n = pos->next)


void list_init(ListObj* list);
void list_insert_after(ListObj* list, ListObj* node);
void list_insert_before(ListObj* list, ListObj* node);
void list_remove(ListObj* node);
int list_isEmpty(const ListObj* list);
unsigned int list_len(const ListObj* list);

#endif //DATASTRUCTURES_LINK_LIST_H