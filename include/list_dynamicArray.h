#if !defined(_DYNAMIC_ARRAY_H_)
#define _DYNAMIC_ARRAY_H_

/**
 * @brief 动态数组
 *
 */
struct dynamicArray
{
    // 真实在堆区开辟数组的指针
    void **pAddr;
    // 数组容量
    int m_Capacity;
    // 数组大小
    int m_Size;
};

/**
 * @brief 初始化动态数组
 *
 * @param capacity 初始化的容量
 * @return struct dynamicArray*
 */
struct dynamicArray *init_dynamicArray(int capacity);

/**
 * @brief 打印动态数组
 * 
 * @param arr 需要被打印的动态数组
 */
void print_dynamicArray(struct dynamicArray * arr);


#endif // _DYNAMIC_ARRAY_H_
