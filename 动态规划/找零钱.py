
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 最少货币数
# @param arr int整型一维数组 the array
# @param aim int整型 the target
# @return int整型
#
class Solution:
    def minMoney(self , arr, aim: int) -> int:
        # write code here
        # 找到最小面值
        if len(arr) == 0:
            return -1
        if (aim == 0):
            return 0
        self.base = min(arr)
        self.arr = arr
        self.memory = {}

        res = self.__minMoney(aim)
        if res == float("inf"):
            return -1
        return res

    def __minMoney(self, aim : int):
        if (aim == 0):
            return 0
        # 递归基, 说明不要了
        if(aim < self.base):
            return -1
        # 查询记忆
        if(self.memory.get(aim)):
            return self.memory[aim]
        # 向下搜索
        min = float("inf")
        for i in self.arr:
            tmp = self.__minMoney(aim - i)
            if (tmp < min and tmp != -1):
                min = tmp
        self.memory[aim] = min + 1
        return min + 1


if __name__ == "__main__":
    s = Solution()
    res = s.minMoney([2887,2355,335,4472,4561,1819,3808],4953)
    print(res)
    pass