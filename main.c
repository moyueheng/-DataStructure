#include <stdio.h>
#include "tils.h"
#include "list_dynamicArray.h"
#include "bubble_sort.h"
#include <stdlib.h>

struct Person
{
    char name[64];
    int age;
};

void printPerson(void *data)
{
    if (data == NULL)
    {
        return;
    }
    struct Person *person = data;
    printf("姓名：%s, 年龄：%d \n", person->name, person->age);
}

void test_dynamicArray()
{
    // 初始化动态数组
    struct dynamicArray *darr = init_dynamicArray(10);
    struct Person p1 = {"张飞", 18};
    struct Person p2 = {"A", 19};
    struct Person p3 = {"B", 20};
    struct Person p4 = {"C", 31};
    insert_dynamicArray(darr, &p1, 0);
    insert_dynamicArray(darr, &p2, 0);
    insert_dynamicArray(darr, &p3, 2);
    insert_dynamicArray(darr, &p4, 0);
    // 打印数组
    // C A 张飞 B
    foreach_dynamicArray(darr, printPerson);
}

void test_sort()
{
    int arr[] = {5, 4, 3, 234, 6, 56, 34, 1, 32, 14, 34};
    int len = sizeof(arr) / sizeof(*arr);
    show_nums(arr, len);
    buble_sort_3(arr, len);
    show_nums(arr, len);
}

int main(int argc, char const *argv[])
{
    // struct dynamicArray *init_dynamicArray(int capacity);
    // test_dynamicArray();
    // test_sort();
    int *p = malloc(sizeof(int));
    free(p);
    printf("第1次free");
    free(p);
    printf("第2次free");
    return 0;
}
