#include <iostream>
using namespace std;
#include <climits>
#include <vector>

class Solution
{
    vector<int> arr;
    int base;

public:
    /**
     * 最少货币数
     * @param arr int整型vector the array
     * @param aim int整型 the target
     * @return int整型
     */
    int minMoney(vector<int> &arr, int aim)
    {
        // write code here
        
        this->arr = arr;
        this->base = INT_MAX;
        for (int i : this->arr)
        {
            if (this->base > i)
            { // 直接选了
                this->base = i;
            }
        }
        return this->minMoney(aim);
    }
    int minMoney(int aim)
    {
        if (aim == 0)
        {
            return 0
        }
        
        // 递归基
        if (aim < this->base)
        { // 我一定不选这个
            return -1;
        }

        for (int i : this->arr)
        {
            if (aim == i)
            { // 直接选了
                return 1;
            }
        }
        // 找出最小的分支
        int min = INT_MAX;
        for (int i : arr)
        {
            int tmp = minMoney(aim - i); // 害得递归
            if (tmp < min)
            {
                min = tmp;
            }
        }
        // 返回分支+1
        return min + 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution *s = new Solution();

    // vector<int> arr{25, 20, 5, 1};
    // int aim = 41;

    vector<int> arr{5,2,3};
    int aim = 20;
    int res = s->minMoney(arr, aim);
    cout << res << endl;
    return 0;
}