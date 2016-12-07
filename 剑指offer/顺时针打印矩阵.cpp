// 题目描述
// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
// 例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
// 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

// 思路：
// 模拟顺时针打印操作， 在一个循环中，依次打印向右、下、左、上打印数字
// 注意边界情况。

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        if (matrix.size() == 0)
        {
            return result;
        }
        int top = 0;
        int bottom = matrix.size();
        int left = 0;
        int right = matrix[0].size();
        int x = 0;
        int y = 0;
        while (left < right && top < bottom)
        {
            // 向右
            while (x < right && y < bottom)
            {
                result.push_back(matrix[y][x]);
                x++;
            }
            x--;
            top++;

            // 向下
            y++;
            while (y < bottom)
            {
                result.push_back(matrix[y][x]);
                y++;
            }
            y--;
            right--;

            // 向左
            x--;
            while (x >= left && y >= top)
            {
                result.push_back(matrix[y][x]);
                x--;
            }
            x++;
            bottom--;

            // 向上
            y--;
            while (y >= top &&  x < right)
            {
                result.push_back(matrix[y][x]);
                y--;
            }
            x++;
            y++;
            left++;
        }
        return result;
    }
};