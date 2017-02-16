// 题目描述
// 输入两个单调递增的链表，输出两个链表合成后的链表，
// 当然我们需要合成后的链表满足单调不减规则。

// 思路：
// 比较两个链表的头节点值的大小， 头节点值小的定义为主干链表， 值大的定义为分支链表
// 遍历两个链表， 比较当前分支链表的指向的值和当前主公链表的指向的下一个节点值
// 如果小于，则将当前分支节点插入主干节点。当主干或分支链表遍历到最后一个节点时，
// 将分支链表拼接到主干链表之后。

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == NULL || pHead2 == NULL)
        {
        	return  pHead1 != NULL ? pHead1 : pHead2;
        }
        ListNode *pTrunkHead;
        ListNode *pTrunkFont;
        ListNode *pTrunkBack;
        ListNode *pBranchFont;
        ListNode *pBranchBack;
        // 头节点值最小的为主干
        if (pHead1->val < pHead2->val)
        {
            pTrunkHead = pHead1;
        	pTrunkFont = pHead1;
            pTrunkBack = pHead1->next;
            pBranchFont = pHead2;
            pBranchBack = pHead2->next;
        }
        else
        {
            pTrunkHead = pHead2;
            pTrunkFont = pHead2;
            pTrunkBack = pHead2->next;
            pBranchFont = pHead1;
            pBranchBack = pHead1->next;
        }

        while (pTrunkBack != NULL && pBranchBack != NULL)
        {
        	if (pTrunkBack->val > pBranchFont->val)
            {
                // 插入节点
            	pBranchFont->next = pTrunkBack;
                pTrunkFont->next = pBranchFont;

                // 分支链表节点后移
                pBranchFont = pBranchBack;
                pBranchBack = pBranchBack->next;

                // 主干链表节点后移
                pTrunkFont = pTrunkFont->next;
            }
            else
            {
            	pTrunkFont = pTrunkFont->next;
                pTrunkBack = pTrunkBack->next;
            }
        }

        // 将当前的分支拼接到主干节点尾部
        while (pTrunkBack != NULL)
        {
        	pTrunkFont = pTrunkFont->next;
            pTrunkBack = pTrunkBack->next;
        }
        pTrunkFont->next = pBranchFont;

        return pTrunkHead;
    }
};