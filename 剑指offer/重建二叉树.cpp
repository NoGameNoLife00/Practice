// 题目描述
// 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
// 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
// 则重建二叉树并返回。

// 思路：
// 前序遍历是第一个得到的总是根节点的值。
// 而中序遍历，根节点总是在序列中，左子树节点的值位于根节点值的前面，右子树节点的值在根节点的值的后面
// 例如在这个题的例子中，根据前序遍历，可以得到1为根节点的值，再根据中序遍历，得到左子树的中序遍历{4,7,2},
// 和右子树的中序遍历序列{5,3,8,6}, 然后再结合前序遍历，得到左子树的前序遍历{2,4,7}和右子树的前序遍历序列{3,5,6,8}
// 这样我们就又有了左子树以及右子树的前序和中序遍历结果。
// 重复上面的过程，不断构建左子树和右子树直到能得到的序列为空时，最终就得到了整个二叉树。
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.size() == 0 || pre.size() != vin.size())
        {
            return NULL;
        }
        int rootValue = pre[0];
        int leftNodeCounts = 0;
        TreeNode *pNode = new TreeNode(rootValue);
        vector<int> leftPre;
        vector<int> leftVin;
        vector<int> rightPre;
        vector<int> rightVin;
        bool left = true;
        // 拆分中序遍历的左右子树
        for (int i = 0; i < vin.size(); i++)
        {
            if (vin[i] == rootValue)
            {
                left = false;
                continue;
            }
            if (left)
            {
                leftVin.push_back(vin[i]);
                leftNodeCounts++;
            }
            else
            {
                rightVin.push_back(vin[i]);
            }
        }
        // 拆分后续遍历的 左右子树
        for (int i = 0; i < leftNodeCounts; i++)
        {
            leftPre.push_back(pre[1 + i]);
        }

        for (int i = 1 + leftNodeCounts; i < pre.size(); i++)
        {
            rightPre.push_back(pre[i]);
        }

        pNode->left = reConstructBinaryTree(leftPre, leftVin);
        pNode->right = reConstructBinaryTree(rightPre, rightVin);
        return pNode;
    }
};
