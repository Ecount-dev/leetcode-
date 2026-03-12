class Solution {
public:
    bool isAnagram(string s, string t) {
		int hash[26] = { 0 };                   // 定义一个长度为26的数组来统计每个字母出现的次数
		for (int i = 0; i < s.size(); i++)      // 遍历字符串s，统计每个字母出现的次数
        {
			hash[s[i] - 'a']++;                 // 将对应字母的计数加1，s[i] - 'a'是将字符转换为对应的数组索引,利用ascii码的特点，'a'的ascii码是97，所以s[i] - 'a'就可以得到s[i]在字母表中的位置，从而对应到hash数组中的索引
        }
		for (int i = 0; i < t.size(); i++)      // 遍历字符串t，统计每个字母出现的次数
        {
			hash[t[i] - 'a']--;                 // 将对应字母的计数减1，t[i] - 'a'同样是将字符转换为对应的数组索引
        }
        for (int i = 0; i < 26; i++)
        {
			if (hash[i] != 0)                   // 如果hash数组中有不为0的元素，说明s和t中对应字母的出现次数不相等，不是有效的字母异位词
            {
                return false;
            }
        }
        return true;

    }
};