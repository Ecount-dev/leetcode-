class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {     //滑动窗口
        int i = 0;
        int sum = 0;
		int result = INT32_MAX;                             //初始化结果为最大值
        int subLen = 0;                                     //定义长度
        for (int j = 0; j < nums.size(); j++)
        {
            sum = sum + nums[j];                            //前j个元素和
            while (sum >= target)                           //当和大于等于目标值时，更新结果
            {
				int subLen = j - i + 1;                     //更新子数组长度
				result = result < subLen ? result : subLen; //更新最小长度
                sum = sum - nums[i];

                i++;
            }
        }
		return result == INT32_MAX ? 0 : result;            //如果结果没有更新，说明没有符合条件的子数组，返回0，否则返回结果

    }
};