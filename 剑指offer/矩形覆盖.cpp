// 题目描述
// 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
// 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

// 思路：
// n = 1时， 只能竖放，一种方法
// n = 2时， 可以全竖放，或者全横放，两种方法
// 当n > 2 时：用第一个小矩形放在最左边，有两种方法。
// 当竖着放的时候， 右边还剩2*(n-1)个格子。可以等价为f(n-1)的情况
// 当横着放的时候， 左下角也必须横着放一个小矩形， 此时右边还剩2*(n-2)个格子， 可以等价为f(n-2)；
// 有此得出f(n) = f(n-1)+f(n-2)。 为一个斐波那契数列

class Solution {
public:
    int rectCover(int number) {
        if (number < 3)
        {
        	return number;
        }
		int first = 1;
        int next = 2;
        int fin = 0;
        for (int i = 3; i <= number ; i++)
       	{
        	fin = first + next;
            first = next;
            next = fin;
        }
        return fin;
    }
};