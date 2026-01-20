class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;                                   //慢指针
		for (int fast = 0; fast < nums.size(); fast++)  //快指针，先遍历数组，fast需<nums.size(),不能<=nums.size-1（防止数组为空）
        {
            if (val != nums[fast])                      //
            {
				nums[slow] = nums[fast];                //将不等于val的值赋值给慢指针位置
                slow++;
            }
        }
        return slow;
    }
};