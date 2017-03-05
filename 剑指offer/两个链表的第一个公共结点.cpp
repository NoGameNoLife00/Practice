// 题目描述
// 输入两个链表，找出它们的第一个公共结点。

// 思路：
// 比较两个链表的长度，如果存在长的链表，就将长链表指针移动长度差个位置，短的链表指针指向表头。
// 然后遍历两个指针后面的节点，找到相同的节点指针

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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL || pHead2 == NULL) {
            return NULL;
        }
        ListNode *p, *q;
        int step = 0;
        int len1 = getListLength(pHead1);
        int len2 = getListLength(pHead2);
        p = pHead1;
        q = pHead2;
        if (len1 < len2) {
           	step = len2 - len1;
			p = pHead2;
            q = pHead1;
        } else if (len2 < len1) {
            step = len1 - len2;
            p = pHead1;
            q = pHead2;
        }

        while (step > 0) {
            p = p->next;
            step--;
        }

        while (p != NULL) {
            if (p == q) {
                return p;
            }
            p = p->next;
            q = q->next;
        }
        return NULL;
    }

    int getListLength(ListNode *pHead) {
        int len = 0;
        ListNode *node = pHead;
        while (node != NULL) {
            node = node->next;
        	len++;
        }
        return len;
    }
};