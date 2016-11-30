// 题目描述
// 输入一个链表，从尾到头打印链表每个节点的值。

// 思路：
// 在不改变原有链表结构的情况下，倒序输出链表的值，比较方便的方法是使用栈（先进后出）,
// 遍历链表中的元素依次放入栈中，之后再将栈中元素依次弹出放入vector中。

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> result;
        if (head == NULL)
        {
            return result;
        }
        stack<ListNode*> s;
        ListNode *pNode = head;
        int counts = 0;
        while (pNode != NULL)
        {
            s.push(pNode);
            pNode = pNode->next;
            counts++;
        }
        while (!s.empty())
        {
            pNode = s.top();
            result.push_back(pNode->val);
            s.pop();
        }
        return result;
    }
};