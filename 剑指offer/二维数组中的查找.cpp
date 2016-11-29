// 题目描述
// 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
// 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

// 思路
// 在二维数组中的二分查找， 将二维数组看成一个矩形，从矩形的右上角开始查找


class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.size() == 0 || array[0].size() == 0)
        {
        	return false;
        }
        int w = array[0].size() - 1;
        int h = array.size() - 1;
        int x = w;
        int y = 0;

        while (x >= 0 && y <= h)
        {
        	if (target < array[y][x])
            {
            	x--;
            }
            else if (target > array[y][x])
            {
                 y++;
            }
            else
            {
            	return true;
            }
        }
        return false;
    }
};