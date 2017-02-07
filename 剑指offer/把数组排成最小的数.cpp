// 题目描述
// 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
// 例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

// 思路：
// 任意取到数组的两个数字m和n，将m和n拼接成数字mn和nm，如果mn<nm,
// 则m应该排在n的前面，我们此时定义为m小于n。相反，如果mn>nm,我们定义
// m大于n。如果mn=nm，则m=n。
// 要考虑m和n拼接后的数字可能超过int的范围。所有这同时是个大数问题，
// 可以使用字符串进行比较，同时考虑mn和nm得到的字符串长度相同，可以直接用
// string的compare方法比较。

class Solution {
public:
    static bool compare(const string &strA, const string &strB) {
        string strCombine1 = strA + strB;
        string strCombine2 = strB + strA;

        return strCombine1.compare(strCombine2) <= 0 ? true : false;
    }

    string PrintMinNumber(vector<int> numbers) {
        string result;
        vector<string> strVec;
        if (numbers.size() == 0) {
            return "";
        }

        for (int i = 0; i < numbers.size(); i++) {
            ostringstream stream;
            stream << numbers[i];
            strVec.push_back(stream.str());
        }
        sort(strVec.begin(), strVec.end(), compare);
        for (int i = 0; i < numbers.size(); i++) {
            result += strVec[i];
        }
        return result;
    }
};