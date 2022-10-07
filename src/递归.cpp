/*
 * @Author: Heng moyueheng@126.com
 * @Date: 2022-10-06 20:09:46
 * @LastEditors: Heng moyueheng@126.com
 * @LastEditTime: 2022-10-06 21:49:46
 * @FilePath: /DataStructure/src/递归.cpp
 * @Description: https://space.bilibili.com/343917159
 *
 * Copyright (c) 2022 by Heng moyueheng@126.com, All Rights Reserved.
 */

#include <iostream>
using namespace std;

class Fib
{
private:
public:
    /**
     * @description: 不带记忆的斐波那契数计算 空间O(n)， 时间O(n^2)
     * @param {int} n
     * @return {int}
     */
    int fib1(int n)
    {
        if (n <= 2)
            return 1;
        return fib1(n - 1) + fib1(n - 2);
    }

    /**
     * @description: 带记忆的斐波那契数列计算 空间O(n)， 时间 O(n)
     * @param {int} n
     * @return {*}
     */
    int fib2(int n)
    {
        if (n <= 2)
            return 1;

        int *ret = new int[n + 1]; // 全都是0, 堆区分配全为0，栈区分配是随机
        ret[1] = ret[2] = 1;
        return fib2(n, ret);
    }
    /**
     * @description: 带记忆的斐波那契数列计算
     * @param {int} n
     * @param {int} *ret
     * @return {*}
     */
    int fib2(int n, int *ret)
    {
        if (ret[n] == 0)
        {
            return fib2(n - 1, ret) + fib2(n - 2, ret);
        }
        return ret[n];
    }
    /**
     * @description: 斐波那契数，动态规划 空间O(n)， 时间 O(n)
     * @param {int} n
     * @return {int}
     */
    int fib3(int n)
    {
        if (n <= 2)
        {
            return 1;
        }
        int *arr = new int[n + 1];
        arr[1] = arr[2] = 1;
        for (int i = 3; i < n + 1; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        return arr[n];
    }
    /**
     * @description: 滚动数组来实现 空间O(1)， 时间 O(n)
     * @param {int} n
     * @return {int}
     */
    int fib4(int n)
    {
        if (n <= 2)
        {
            return 1;
        }
        int *arr = new int[2];
        arr[0] = arr[1] = 1;
        for (int i = 3; i < n + 1; i++)
        { 
            // arr[i % 2] = arr[(i - 1) % 2] + arr[(i - 2) % 2];
            arr[i & 1] = arr[(i - 1) & 1] + arr[(i - 2) & 1];
        }
        // return arr[n % 2];
        return arr[n & 1];
    }

    static void main()
    {
        Fib *fib = new Fib();
        int ret = fib->fib4(10);
        cout << ret << endl;
    }
};

int main()
{
    Fib::main();
    return 0;
}