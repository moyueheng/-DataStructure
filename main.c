#include <stdio.h>
#include "tils.h"
#include "list_dynamicArray.h"

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

int main(int argc, char const *argv[])
{
    // struct dynamicArray *init_dynamicArray(int capacity);
    test_dynamicArray();
}
