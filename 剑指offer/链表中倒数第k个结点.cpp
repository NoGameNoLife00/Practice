// 题目描述
// 输入一个链表，输出该链表中倒数第k个结点

// 思路：
// 遍历链表得到链表长度n， 之后再从头开始获得第n-k+1个节点就行。

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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	unsigned int size = 0;
        ListNode *pNode = pListHead;

        if (k == 0 || pListHead == NULL)
		{
			// 错误处理TODO
			return NULL;
		}
        while (pNode != NULL)
        {
            size++;
            pNode = pNode->next;
        }

        if (k > size)
        {
            // 错误处理TODO
        	return NULL;
        }

        unsigned int n = size  - k;
        pNode = pListHead;
        while (n > 0)
        {
            n--;
            pNode = pNode->next;
        }
        return pNode;
    }
};

// 思路2：
// 定义两个指针， 第一个指针从头节点开始遍历走k-1步，第二个指针保持不动。
// 直到第一个指针走到第k步开始，第二个指针也开始走，两个指针始终保持k-1的距离，
// 当第一个指针走到链表末尾时，第二个指针就在倒数第k个节点了。
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	unsigned int size = 0;
        ListNode *pBefore = pListHead;
        ListNode *pAfter = pListHead;

        if (pListHead == NULL || k == 0)
        {
            // 错误处理TODO
        	return NULL;
        }

        for (unsigned int i = 0 ; i < k - 1; i++)
        {
        	pAfter = pAfter->next;
            if (pAfter == NULL)
            {
            	// 错误处理TODO
                return NULL;
            }
        }

        while (pAfter->next != NULL)
        {
        	pBefore = pBefore->next;
            pAfter = pAfter->next;
        }

        return pBefore;
    }
};