/***
 * @Author: Heng
 * @Date: 2022-10-27 03:51:31
 * @LastEditTime: 2022-10-27 03:51:44
 * @LastEditors: Heng
 * @Description:
 * @FilePath: /DataStructure/分治/最大连续子序列和.cpp
 * @Heng
 */
#include <iostream>
using namespace std;
#include <climits>
#include <vector>

class Solution
{
public:
    /***
     * @description: 暴力求解
     * @param {vector<int>} &nums
     * @return {*}
     */
    int maxSubArray0(vector<int> &nums)
    {
        int res = INT_MIN;
        for (int begin = 0; begin < nums.size(); begin++)
        {
            int tmp = 0;
            for (int end = begin; end < nums.size(); end++)
            {
                tmp += nums[end];
                res = max(tmp, res);
            }
        }
        return res;
    }
    /***
     * @description: 分治算法 
     * @param {vector<int>} &nums
     * @return {*}
     */
    int maxSubArray1(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        return this->maxSubArray1(nums, 0, nums.size());
    }
    /*** 
     * @description: 求[begin, end) 的最大连续子序列和
     * @param {vector<int>} &nums
     * @param {int} begin
     * @param {int} end
     * @return {*}
     */    
    int maxSubArray1(vector<int> &nums, int begin, int end)
    {
        // 递归基
        if (end - begin < 2)
            return nums[begin];
        int mid = (begin + end) >> 1;
        // 左边
        int leftMax = this->maxSubArray1(nums, begin, mid);
        // 右边
        int rightMax = this->maxSubArray1(nums, mid, end);
        // 中间
        // 中左
        int leftMidMax = INT_MIN;
        int left_sum = 0;
        for (int i = mid - 1; i >= begin; i--)
        {
            left_sum += nums[i];
            leftMidMax = max(left_sum, leftMidMax);
        }
        // 中右
        int rightMidMax = INT_MIN;
        int right_sum = 0;
        for (int i = mid; i < end; i++)
        {
            right_sum += nums[i];
            rightMidMax = max(right_sum, rightMidMax);
        }
        int mid_max = leftMidMax + rightMidMax;
        return max(mid_max, max(leftMax, rightMax));
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int res = s.maxSubArray1(nums);
    cout << res << endl;
    return 0;
}