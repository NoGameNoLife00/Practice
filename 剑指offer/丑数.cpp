// 题目描述
// 把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。
// 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

// 思路：
// 最简单思路是遍历依次正整数，直到找到第n个丑数。但是这种方法太慢了。
// 可以直接根据丑数的定义（丑数是另一个丑数乘以2、3或5）。所以可以创建一个数组，
// 里面存储已经排好序的丑数。每个丑数是前面的丑数乘以2、3或5得到

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0) {
            return 0;
        }
        int uglyCount = 1;
        vector<int> vecUgly;
        int indexMultiply2 = 0;
        int indexMultiply3 = 0;
        int indexMultiply5 = 0;
        vecUgly.push_back(1);
        while (uglyCount < index) {
            int minNum = min(min(vecUgly[indexMultiply2] * 2, vecUgly[indexMultiply3] * 3),
                vecUgly[indexMultiply5] * 5);
            vecUgly.push_back(minNum);
            while (vecUgly[indexMultiply2] * 2 <= vecUgly[uglyCount]) {
                indexMultiply2++;
            }
            while (vecUgly[indexMultiply3] * 3 <= vecUgly[uglyCount]) {
                indexMultiply3++;
            }
            while (vecUgly[indexMultiply5] * 5 <= vecUgly[uglyCount]) {
                indexMultiply5++;
            }
            uglyCount++;
        }
        return vecUgly[uglyCount-1];
    }


};