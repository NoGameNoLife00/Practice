// 题目描述
// 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
// n<=39

// 思路：
// 斐波那契数列的大概定义就是，第0项为0， 第一项为1，之后的第n项为前两项之和。
// 可以使用递归解题，但是此题使用递归效率太低。 直接用循环迭代的方式更佳

class Solution {
public:
    int Fibonacci(int n) {
        if (n < 2)
        {
        	return n;
        }
		int first = 0;
        int next = 1;
        int fin = 0;
        for (int i = 2; i <= n ; i++)
       	{
        	fin = first + next;
            first = next;
            next = fin;
        }
        return fin;
    }
};