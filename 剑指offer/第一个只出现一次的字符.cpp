// 题目描述
// 在一个字符串(1<=字符串长度<=10000，全部由大写字母组成)
// 中找到第一个只出现一次的字符,并返回它的位置


// 思路：
// 遍历字符串，将字符出现的次数和出现的位置存到分别存到两个map中，字符作为key。
// 然后再遍历一次字符串，如果字符出现的次数为1，则输出字符所在位置

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> countMap;
        for (int i = 0; i < str.length(); i++) {
            unordered_map<char, int>::iterator itCount = countMap.find(str[i]);
            if (itCount != countMap.end()) {
                itCount->second++;
            } else {
                countMap.insert(pair<char, int>(str[i], 1));
            }
        }

        for (int i = 0; i < str.length(); i++) {
            if (countMap[str[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};