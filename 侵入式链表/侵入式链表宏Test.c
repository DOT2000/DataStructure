/**
 *  @author 小粥无敌辣
 *  2023/9/18 20:23
 *  DataStructures
 */
#include <stdio.h>

#define offsetof(type, member) ((size_t) &((type*)0)->member)

#define container_of(ptr, type, member) ({ \
    const typeof( ((type *)0)->member ) *__mptr = (ptr); \
    (type *)( (char *)__mptr - offsetof(type,member) );})

typedef struct
{
    char a;
    int b;
    float c;
}test_t;

int main(void)
{
    test_t test, *p_test;
    int *container_test = &(test.b);
    p_test = container_of(container_test, test_t, b);
    if(&test == p_test)
    {
        printf("Addr is same\r\n");
    }
    return 0;
}