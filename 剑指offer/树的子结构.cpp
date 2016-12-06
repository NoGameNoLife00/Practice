// 题目描述
// 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）


思路：
遍历树1中的所有节点， 判断以每个节点为根节点的子树是否与树2的结构一样

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
		bool result = false;
        if (pRoot2 == NULL || pRoot1 == NULL)
        {
            return false;
        }

        if (IsSubtree(pRoot1, pRoot2))
        {
        	return true;
        }
        else
        {
        	if (HasSubtree(pRoot1->left, pRoot2))
            {
            	return true;
            }

            if (HasSubtree(pRoot1->right, pRoot2))
            {
            	return true;
            }
        }
        return false;
    }

    bool IsSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot2 == NULL)
        {
        	return true;
        }

        if (pRoot1 == NULL)
        {
        	return false;
        }


    	if (pRoot1->val == pRoot2->val)
        {
        	if (IsSubtree(pRoot1->left, pRoot2->left) && IsSubtree(pRoot1->right, pRoot2->right))
            {
            	return true;
            }
        }

        return false;
    }
};