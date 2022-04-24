/**
 * @file bubble_sort.h
 * @author moyueheng (moyueheng@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#if !defined(_BUBBLE_SORT_H_)
#define _BUBBLE_SORT_H_

/**
 * @brief 无优化冒泡排序    
 * 
 * @param arr 
 * @param len 
 */
void buble_sort_1(int *arr, int len);

/**
 * @brief 冒泡排序    
 * 通过一个标志位来确定是否提前有序
 * @param arr 
 * @param len 
 */
void buble_sort_2(int *arr, int len);


/**
 * @brief 冒泡排序    
 * 通过一个标志位来确定是否提前有序
 * @param arr 
 * @param len 
 */
void buble_sort_3(int *arr, int len);



#endif // _BUBBLE_SORT_H_
