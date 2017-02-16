// 题目描述
// 输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
// 输入描述:
// 输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

// 思路：
// 先求出所有可能出现在第一个位置的字符（把第一个字符和后面所有字符依次交换）
// 然后当第一个字符固定的情况下，求后面所以字符的排列（递归）
// 注意输入中可能出现重复字符，需要判断重复字符的情况

class Solution {
    void Permutation(vector<string> &vec, string &str, int index) {
        if (index == str.size()-1)
        {
            vec.push_back(str);
        }
        // 重复字符不再使用
        unordered_set<char> usedChar;

        for (int i = index; i < str.size(); i++)
        {
            if (usedChar.find(str[i]) == usedChar.end())
            {
                usedChar.insert(str[i]);
                swap(str[i], str[index]);
                Permutation(vec, str, index + 1);
                swap(str[i], str[index]);
            }

        }

    }

public:
    vector<string> Permutation(string str) {
        vector<string> result;
        if (str.size() == 0)
		{
        	return result;
        }
        Permutation(result, str, 0);
        sort(result.begin(), result.end());
        return result;
    }
};