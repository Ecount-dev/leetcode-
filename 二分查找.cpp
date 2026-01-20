class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;                                   //定义左边界，
		int right = nums.size();                    //定义右边界
		while (left < right) {                         //当左边界小于等于右边界时，继续循环，右边界为长度-1，是因为数组下标从0开始，所以最后一个元素的下标是长度-1，区间就是[left,right]
			                                            //如果当左边界小于右边界时，右边界为长度，区间就是[left,right)
			int middle = left + ((right - left) / 2);   //防止溢出，计算中间位置
			if (nums[middle] < target) {                //如果中间位置的值小于目标值，说明目标值在右边
				left = middle + 1;                      //更新左边界

            }
			else if (nums[middle] > target) {           //如果中间位置的值大于目标值，说明目标值在左边
				right = middle;                         //更新右边界
            }
            else {
                return middle;
            }
        }
        return -1;

    }
};