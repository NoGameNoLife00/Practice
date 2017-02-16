// 题目描述
// 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
// 求该青蛙跳上一个n级的台阶总共有多少种跳法。

思路：
举例：台阶n = 1时，解法1种，n = 2时，解法2种， n = 3时，解法4种，
n = 4时，解法8种， n = 5时，解法16种....
观察得出 f(n) = 2 ^ (n-1)。 数学归纳

class Solution {
public:
    int jumpFloorII(int number) {
		int result = 1;
        for (int i = 0; i < number-1; i++)
        {
        	result *= 2;
        }
        return result;
    }
};