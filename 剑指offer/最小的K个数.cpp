// 题目描述
// 输入n个整数，找出其中最小的K个数。
// 例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4

// 思路：
// 创建一个容量为k的容器来存储最小k个数字， 遍历数组，当容器已有数字小于k，
// 则直接将元素存入容器中，如果容器已满，比较容器中最大的数字和当前数字，
// 如果当前数字更小，则替换容器中的最大数字。
// STL中的Set容器，使用红黑树实现，查找，删除，插入都只需要O(logk)的时间。
// 总的算法时间O(nlogk)

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        multiset<int, greater<int>> leastSet;
        multiset<int, greater<int>>::iterator itSet;
        vector<int> result;
        if (k <= 0 || input.size() == 0 || k > input.size())
        {
        	return result;
        }
        for (vector<int>::iterator it = input.begin(); it != input.end(); it++)
        {
            if (leastSet.size() < k)
            {
                leastSet.insert(*it);
                continue;
            }
            itSet = leastSet.begin();
            if (*it < *itSet)
            {
                leastSet.erase(itSet);
                leastSet.insert(*it);
            }
        }

        for (itSet = leastSet.begin(); itSet != leastSet.end(); itSet++)
        {
            result.push_back(*itSet);
        }
        return result;
    }
};

// 思路2:
// 快排的思想，基于数字的第k个数来调整，使比第k个数字小的所有数字都在数组左边，
// 比k个数字大的都在数组右边


class Solution {
public:
    int RandomInRange(int start, int end)
    {
        srand(time(NULL));
        return start + rand() % (end - start + 1);
    }

    int Partition(vector<int> &data, int start, int end)
    {
        if (data.size() == 0 || start < 0 || end >= data.size())
        {
            // error todo
            return -1;
        }
        int index = RandomInRange(start, end);
        swap(data[index], data[end]);
        int small = start - 1;
        for (index = start; index < end; index++)
        {
            if (data[index] < data[end])
            {
                small++;
                if (small != index)
                {
                    swap(data[index], data[small]);
                }
            }
        }
        small++;
        swap(data[small], data[end]);
        return small;
    }

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if (k <= 0 || input.size() == 0 || k > input.size())
        {
            return result;
        }
        int start = 0;
        int end = input.size() - 1;
        int index = Partition(input, start, end);
        while (index != k - 1)
        {
            if (index > k - 1)
            {
                end = index - 1;
                index = Partition(input, start, end);
            }
            else
            {
                start = index + 1;
                index = Partition(input, start, end);
            }
        }
        for (int i = 0; i < k; i++)
        {
            result.push_back(input[i]);
        }
        return result;
    }
};