// 题目描述
// 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

// 思路：
// 当台阶n = 1时，有一种方法，当n = 2时， 有两种解法（11,2），
// 当n>2时，第一次跳有两种选择，跳一阶：而后面的跳法与n-1阶相同 f(n-1);
// 跳两阶：此时跳法等于剩下n-2阶的相同 f(n-2)，所以n阶跳法有f(n-1)+f(n-2)。


class Solution {
public:
    int jumpFloor(int number) {
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