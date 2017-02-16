// 题目描述
// 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

思路：
当n为正数的时候，将n的二进制第一位与1进行与运算(&)， 结果为1，则个数+1，然后将n右移一位，再与1进行与运行，不停重复直到n等于0；
当n为负数的时候，n右移操作会出现死循环。所以需要先将n按位取反运算（~）, 之后再进行n为正数相同的运算过程， 最后结果取32减去一出现的个数，得到最终答案
class Solution {
public:
    int  NumberOf1(int n) {
        int number = 0;
        bool isPositive = true;
        if (n < 0)
        {
            n = ~n;
            isPositive = false;
        }
        while (n != 0)
        {
            if (n & 1)
            {
                number++;
            }
            n >>= 1;
        }
        return isPositive ? number : (32 - number);
    }
};

思路2：
把一个整数减去1， 再与原整数进行与运算，会把该整数最右边一个1变成n中有多少个1，
就可以进行多少次这样的操作。比如：1100, 1100-1 = 1011, 1011 & 1100 = 1000 这样就把最右边的1变成了0
class Solution {
public:
    int  NumberOf1(int n) {
        int number = 0;
        while (n)
        {
        	number++;
            n = (n-1) & n;
        }
        return number;
    }
};