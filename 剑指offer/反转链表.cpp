// 题目描述
// 输入一个链表，反转链表后，输出链表的所有元素。

思路：
反转链表节点时，需要3个节点指针。分别指向当前节点的前一个节点和后一个节点。
注意处理链表头节点指针为NULL和节点只有一个的情况。 反转之后的原来的头节点的next指针指向NULL


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
    ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL)
        {
        	return NULL;
        }

        ListNode *pFront = pHead;
        ListNode *pMiddle = pFront->next;
        ListNode *pBack = NULL;
        if (pMiddle == NULL)
        {
           // 链表只存在一个节点
           return pHead;
        }

		pFront->next = NULL;
        pBack = pMiddle->next;
        while (pMiddle != NULL)
        {
        	pMiddle->next = pFront;

            if (pBack != NULL)
            {
                pFront = pMiddle;
            	pMiddle = pBack;
                pBack = pBack->next;
            }
            else
            {
            	break;
            }

        }
        return pMiddle;

    }
};