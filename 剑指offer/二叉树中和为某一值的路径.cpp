// 题目描述
// 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
// 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

// 思路：
// 前序遍历树中节点，将当前遍历的路径保存起来， 同时把当前路径节点值的和也存起来，
// 当遍历的节点为叶子节点，切当前路径值的和等于输入的期望值时，将当前路径添加到结果中去。
// 遍历完当前节点和它的子节点之后，将当前节点从当前路径中移除，
// 同时当前节点的值的和也需要减去当前节点值。

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
    void FindPath(vector<vector<int>> &paths, vector<int> &currentPath,
                  TreeNode* node,int &currentSum,int expectNumber) {
        currentSum += node->val;
        currentPath.push_back(node->val);

        if (node->left == NULL && node->right == NULL &&
            currentSum == expectNumber)
        {
        	paths.push_back(currentPath);
        }

        if (node->left != NULL)
        {
        	FindPath(paths, currentPath, node->left, currentSum, expectNumber);
        }

        if (node->right != NULL)
        {
        	FindPath(paths, currentPath, node->right, currentSum, expectNumber);
        }
        currentPath.pop_back();
       	currentSum -= node->val;
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector<vector<int>> paths;
        vector<int> currentPath;
        int currentSum = 0;
        if(root == NULL)
        {
        	return paths;
        }
        FindPath(paths, currentPath, root, currentSum, expectNumber);
        return paths;
    }
};