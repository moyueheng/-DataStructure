/**
 * @file dynamicArray.c
 * @author moyueheng (moyueheng@126.com)
 * @brief
 * @version 0.1
 * @date 2022-04-11
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list_dynamicArray.h"

struct dynamicArray *init_dynamicArray(int capacity)
{

    if (capacity < 0)
    {
        return NULL;
    }
    // 内存
    struct dynamicArray *arr = malloc(sizeof(struct dynamicArray));
    if (arr == NULL)
    {
        return NULL;
    }
    arr->m_Capacity = capacity;
    arr->m_Size = 0;
    arr->pAddr = malloc(sizeof(void *) * capacity);
    return arr;
}

void print_dynamicArray(struct dynamicArray *arr)
{
    printf("capacity = %d, size = %d", arr->m_Capacity, arr->m_Size);
}

void insert_dynamicArray(struct dynamicArray *arr, void *data, int index)
{
    if (arr == NULL)
    {
        return;
    }
    if (data == NULL)
    {
        return;
    }
    // 位置是否合理
    if (index < 0 || index > arr->m_Size)
    {
        index = arr->m_Size; // 强制把位置放到最后实现尾插
        return;
    }
    // 扩容
    if (arr->m_Size == arr->m_Capacity)
    {
        // 申请更大的空间
        int newCapacity = arr->m_Capacity * 1.5;
        void **newSpace = malloc(sizeof(void *) * newCapacity);
        // 再把原来的数据拷贝过来
        memcpy(newSpace, arr->pAddr, sizeof(void *) * arr->m_Capacity);
        // 释放原来的空间
        free(arr->pAddr);
        // 更新原来的数据
        arr->pAddr = newSpace;
        arr->m_Capacity = newCapacity;
    }
    // 新元素插入数组中的指定位置
    for (int i = arr->m_Size - 1; i >= index; i--)
    {
        arr->pAddr[i + 1] = arr->pAddr[i];
    }
    arr->pAddr[index] = data;
    arr->m_Size++;
}

/**
 * @brief 遍历动态数组
 *
 * @param arr
 * @param myPrint 函数指针，回调函数
 */
void foreach_dynamicArray(struct dynamicArray *arr, void (*myPrint)(void *))
{
    if (arr == NULL)
    {
        return;
    }

    for (int i = 0; i < arr->m_Size; i++)
    {
        myPrint(arr->pAddr[i]);
    }
}