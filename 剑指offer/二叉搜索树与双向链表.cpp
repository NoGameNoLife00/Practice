// 题目描述
// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
// 要求不能创建任何新的结点，只能调整树中结点指针的指向。

// 思路：
// 中序遍历二叉搜索树，可按照从小到大的顺序遍历二叉树节点。
// 在遍历过程中，构造双向链表即可

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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode *pLastNodeInList = NULL;
        ConvertNode(pRootOfTree, &pLastNodeInList);

        TreeNode *pHead = pLastNodeInList;
        while (pHead != NULL && pHead->left != NULL)
        {
        	pHead = pHead->left;
        }
        return pHead;
    }

    void ConvertNode(TreeNode *pNode, TreeNode **ppLastNodeInList)
    {
    	if (pNode == NULL)
        {
            return;
        }

        TreeNode *pCurrent = pNode;
        if (pCurrent->left != NULL)
        {
        	ConvertNode(pCurrent->left, ppLastNodeInList);
        }

        pCurrent->left = *ppLastNodeInList;
        if (*ppLastNodeInList != NULL)
    	{
            (*ppLastNodeInList)->right = pCurrent;
        }

        *ppLastNodeInList = pCurrent;

        if (pCurrent->right != NULL)
        {
        	ConvertNode(pCurrent->right, ppLastNodeInList);
        }
    }
};