#include "bubble_sort.h"

/**
 * @brief 无优化冒泡排序    
 * 
 * @param arr 
 * @param len 
 */
void buble_sort_1(int *arr, int len){
    for (int end = len - 1; end > 0 ; end--)
    {
        for (int begin = 1; begin <= end; begin++)
        {
            if (arr[begin -1] > arr[begin])
            {
                // 交换位置
                int tmp = arr[begin];
                arr[begin] = arr[begin-1];
                arr[begin-1] = tmp;
            }
        }
    }
}



/**
 * @brief 冒泡排序    
 * 通过一个标志位来确定是否提前有序
 * @param arr 
 * @param len 
 */
void buble_sort_2(int *arr, int len){
    int is_sort; // c语言没有bool
    for (int end = len - 1; end > 0 ; end--)
    {
        is_sort = 1;
        for (int begin = 1; begin <= end; begin++)
        {
            if (arr[begin -1 ] > arr[begin])
            {
                is_sort = 0;
                // 交换位置
                int tmp = arr[begin];
                arr[begin] = arr[begin-1];
                arr[begin-1] = tmp;
            }
        }
        if (is_sort)
        {
            return;
        }
        
    }
}


/**
 * @brief 冒泡排序    
 * 通过一个标志位来确定是否提前有序
 * @param arr 
 * @param len 
 */
void buble_sort_3(int *arr, int len){
    for (int end = len - 1; end > 0 ; end--)
    {
        int sorted_index = 0;
        for (int begin = 1; begin <= end; begin++)
        {
            if (arr[begin -1] > arr[begin])
            {
                // 交换位置
                int tmp = arr[begin];
                arr[begin] = arr[begin-1];
                arr[begin-1] = tmp;
                // 记录最后一次交换的位置
                sorted_index = begin;
            }
        }
        end = sorted_index;
    }
}