
/*
 * @Author: Heng moyueheng@126.com
 * @Date: 2022-10-08 00:11:13
 * @LastEditors: Heng moyueheng@126.com
 * @LastEditTime: 2022-10-08 01:20:33
 * @FilePath: /DataStructure/递归/02爬楼梯.cpp
 * @Description: https://space.bilibili.com/343917159
 *
 * Copyright (c) 2022 by Heng moyueheng@126.com, All Rights Reserved.
 */
#include <iostream>
using namespace std;
#include <climits>
#include <vector>
#include <string>

class Solution
{
private:
public:
    static void main(string args)
    {
        Solution *s = new Solution;
        cout << s->climb(10) << endl;
    }

    /**
     * @description: 爬楼梯, 时间O（n^2） 空间 O(n), 优化思路同斐波那契
     * @param {int} n
     * @return {int}
     */
    int climb(int n)
    {
        if (n <= 2)
            return n;
        return climb(n - 1) + climb(n - 2);
    }
};

int main(int argc, char const *argv[])
{
    Solution::main("Hello");
    return 0;
}