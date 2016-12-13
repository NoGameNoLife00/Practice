// 题目描述
// 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
// 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

// 思路：
// 遍历数组保存两个值，一个是数组中的数字，一个是次数，当遍历到下一个数字的时候，
// 如果下一个数字和我们保存的数字相同，则次数加一，否则减一。如果次数为0，我们就保持下一个数字
// 并将次数设置为1。因为我们要找的数字的出现次数比其他数字出现次数只和还要多，
// 所以要找的数字肯定是最后一次把次数设置为1时对应的数字。

class Solution {
public:
    bool CheckMoreThanHalf(const vector<int> &numbers, int num)
    {
    	int times = 0;
        for (int i = 0; i < numbers.size(); i++)
        {
        	if (numbers[i] == num)
            {
            	times++;
            }
        }
        return times*2 <= numbers.size() ? false : true;
    }

    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	if (numbers.size() == 0)
        {
            return 0;
        }

        int num = numbers[0];
        int count = 1;
        for (int i = 1; i < numbers.size(); i++)
        {
        	if (count == 0)
            {
            	count = 1;
                num = numbers[i];
            }
            else if (num == numbers[i])
            {
            	count++;
            }
            else
            {
            	count--;
            }
        }
        if (!CheckMoreThanHalf(numbers, num))
        {
        	return 0;
        }

        return num;
    }
};