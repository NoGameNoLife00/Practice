// 题目描述
// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

// 思路：
// 后续遍历得到的最后一个成员为根节点，再根据二叉搜索树中，
// 可知后序遍历序列可以分为两部分，第一部分属于左子树，值都比根节点值小，
// 第二部分属于右子树，值都比根节点值大。

class Solution {
    bool judgeBST(vector<int> &sequence, int begin, int end) {
        int root;
        int index = end;
        bool isLeftTree = true;
        bool isRightTree = true;
        if (begin >= end)
        {
        	return true;
        }
        root = sequence[end];
        for (int i = begin; i < end; i++)
        {
            if (sequence[i] > root)
            {
                index = i;
                break;
            }
        }

        // 右子树序列如果不是都大于根节点，则当前序列不为二叉搜索树序列
        for (int i = index; i < end; i++)
        {
            if (sequence[i] < root)
            {
                return false;
            }
        }
        isLeftTree = judgeBST(sequence, begin, index-1);
        isRightTree = judgeBST(sequence, index, end-1);

        return (isLeftTree && isRightTree);


    }

public:
       bool VerifySquenceOfBST(vector<int> sequence) {

        if (sequence.size() == 0)
        {
            return false;
        }

        return judgeBST(sequence, 0, sequence.size()-1);
    }
};