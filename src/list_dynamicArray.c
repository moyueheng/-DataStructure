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



void print_dynamicArray(struct dynamicArray * arr){
    printf("capacity = %d, size = %d", arr->m_Capacity,arr->m_Size);
}
