class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
		vector<int> result(nums.size(), 0);                 //创建结果数组，大小与输入数组相同，初始值为0
		int k = nums.size() - 1;                            //结果数组的最后一个位置
		for (int i = 0, j = k; i <= j;) {                   //双指针，i指向数组开头，j指向数组结尾
			if (nums[i] * nums[i] > nums[j] * nums[j]) {    //比较两个指针所指向的值的平方
                result[k] = nums[i] * nums[i];          
                k--;
                i++;
            }
            else {
                result[k] = nums[j] * nums[j];
                k--;
                j--;
            }

        }
		return result;                                      //返回结果数组
    }
};