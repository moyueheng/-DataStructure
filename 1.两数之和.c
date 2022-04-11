/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */
#include<stdio.h>
#include"tils.h"
#include<stdlib.h>
// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    // 选定一个
    
    for (int i = 0; i < numsSize; ++i)
    {

        for (int j = i + 1; j < numsSize; ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                int * ret = malloc(sizeof(int) * 2);
                ret[0] = i;
                ret[1] = j;
                *returnSize = 2; 
                return ret;
            }
        }
    }
    *returnSize = 0; 
    return NULL;
    // 再选定第二个
}
// @lc code=end

int main(int argc, char const *argv[])
{
    int nums[] = {2,7,11,15};
    show_nums(nums, sizeof(nums)/ sizeof(*nums));
    return 0;
}
