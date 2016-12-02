// 题目描述
// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
// 所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

// 思路：
// 从头开始扫描数组，每当遇到一个偶数的时候，取出这个偶数，
// 将这个数字后面的所有数字往前移一位,然后将取出的这个偶数放到数组末尾
// 直到当前数字的索引和移动了的偶数的个数之和等于数组大小的时候，退出循环


class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int size = array.size();
        int eventCounts = 0;
        int index = 0;
        if (size == 0)
        {
            return;
        }
        while (index < size)
        {
            if (eventCounts + index >= size)
            {
            	break;
            }
            if ((array[index] & 1) == 0)
            {
                int tmp = array[index];
                for (int j = index; j < size - 1; j++)
                {
                    array[j] = array[j + 1];
                }
                array[size - 1] = tmp;
                eventCounts++;
            }
            else
            {
                index++;
            }
        }
    }

};

// 思路2：
// 使用空间换时间方式，遍历数组，将成员分别偶数数组和奇数数组中。
// 然后再将奇数数组和偶数数组先后合并在原数组中
class Solution {
public:
    void reOrderArray(vector<int> &array) {
		vector<int> oddArray;
        vector<int> eventArray;
        for (auto it = array.begin(); it != array.end(); it++)
        {
        	if ((*it)&1)
            {
            	oddArray.push_back(*it);
            }
            else
            {
            	eventArray.push_back(*it);
            }
        }

        int index = 0;

        for (int i = 0; i < oddArray.size(); i++)
        {
            array[index++] = oddArray[i];
        }

        for (int i = 0; i < eventArray.size(); i++)
        {
        	array[index++] = eventArray[i];
        }
    }

};