// 题目描述
// 从上往下打印出二叉树的每个节点，同层节点从左至右打印。

// 思路：
// 树的层序遍历， 使用广度优先遍历算法。利用队列的先进先出特性。
// 每次打印一个节点时，如果该阶段有字节点，则将子节点放入队列末尾，
// 然后取出队列头部。重复上面的操作直到队列为空结束。

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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> result;
        queue<TreeNode*> q;
        if (root == NULL)
        {
        	return result;
        }
        q.push(root);
        while (q.size() > 0)
        {
            TreeNode *node = q.front();
            result.push_back(node->val);
            q.pop();
            if (node->left != NULL)
            {
                q.push(node->left);
			}
            if (node->right != NULL)
            {
            	q.push(node->right);
            }
        }
        return result;
    }
};