// 题目描述
// 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
// 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
// NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

思路：
二分查找法的思想， 定义两个“指针”， 分别指向数组的开头p和末尾q， 算出两指针直接的中间位置m， 比较中间位置m的值和末尾指针指向的q值,
根据旋转序列的特性，如果中间m的值大于或等于末尾q的值，说明最小数字在m 和 q的位置之间，所以将中间m的赋值给p，
否则就将m赋值给q， 重复上述过程，直到p和q的位置相邻时，最小位置就是q的值了。


class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 0)
        {
        	return 0;
        }
        int leftIndex = 0;
        int rightIndex = rotateArray.size() - 1;


        while (rotateArray[leftIndex] >= rotateArray[rightIndex])
        {
            if (rightIndex - leftIndex == 1)
                break;

            int midIndex = (leftIndex + rightIndex)/2;
        	if (rotateArray[midIndex] >= rotateArray[rightIndex])
            {
            	leftIndex = midIndex;
            }
            else
            {
            	rightIndex = midIndex;
            }
        }
        return rotateArray[rightIndex];
    }
};