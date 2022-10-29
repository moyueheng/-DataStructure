/*
 * @Author: Heng moyueheng@126.com
 * @Date: 2022-10-08 02:00:37
 * @LastEditors: Heng moyueheng@126.com
 * @LastEditTime: 2022-10-08 02:28:48
 * @FilePath: /DataStructure/递归/03汉诺塔.cpp
 * @Description: https://space.bilibili.com/343917159
 *
 * Copyright (c) 2022 by Heng moyueheng@126.com, All Rights Reserved.
 */

#include <iostream>
using namespace std;
#include <climits>
#include <vector>
#include <string>
#include <cstring>
class Hanoi
{
private:
public:
    static void main(string args)
    {
        (new Hanoi)->hanoi(2, "A", "B", "C");
        // string s1= "Heelo";
        // printf("%s\n", s1);
    }

    /**
     * @description: 汉诺塔，把n个碟子从p1移动到p3，p2是中间柱子,没有必要优化，每一步都是必要的
     *  T(n) = 2*T(n-1) + O(1) --> 时间复杂度 O(2^n)， 空间复杂度 O(n  )
     * @param {int} n
     * @param {char* } p1
     * @param {char *} p2
     * @param {char *} p3
     * @return {*}
     */
    void hanoi(int n, char *p1, char *p2, char *p3)
    {
        if (n == 1)
        {
            move(1, p1, p3);
            return;
        }

        // 1. 把n-1个盘子从p1移动到p2
        hanoi(n - 1, p1, p3, p2);
        // 2. 把第n个盘子从p1移动到p3
        move(n, p1, p3);
        // 3. 把n-1个盘子从p2移动到p3，中间p1
        hanoi(n - 1, p2, p1, p3);
    }
    /**
     * @description: 把no号盘子从from移动到to
     * @param {int} no
     * @param {char* } from
     * @param {char* } to
     * @return {*}
     */
    void move(int no, char *from, char *to)
    {
        printf("no: %d, %s --> %s \n", no, from, to);
        // cout << "No: " << no << ", " << from << " --> " << to << endl;
    }
};

int main(int argc, char const *argv[])
{
    Hanoi::main("Hello");
    return 0;
}