// 题目描述
// 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
// 返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

// 思路：
// 第一步：复制原始链表上的所有节点，并存放在哈希表中
// 第二步：根据原始链表中的连接关系，将复制后的节点连接起来

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
   		unordered_map<RandomListNode*, RandomListNode*> copyMap;
        RandomListNode *pNewNode;
        RandomListNode *pNewHead;

        if (pHead == NULL)
        {
        	return NULL;
        }

        // 复制所有节点存到Map中
        RandomListNode *pNode = pHead;
        while (pNode != NULL)
        {
            pNewNode = new RandomListNode(pNode->label);
            copyMap.insert(make_pair(pNode, pNewNode));
            pNode = pNode->next;
        }

        // 连接复制节点
        pNode = pHead;
        while (pNode != NULL)
        {
            pNewNode = copyMap.at(pNode);
            if (pNode->next != NULL)
            {
                pNewNode->next = copyMap.at(pNode->next);
            }
            if (pNode->random != NULL)
            {
                pNewNode->random = copyMap.at(pNode->random);
            }
            pNode = pNode->next;
        }
        pNewHead = copyMap.at(pHead);
        return pNewHead;
    }
};

// 思路2：
// 不使用辅助空间的方法
// 第一步：根据原始链表的每个节点N创建对应的N’，并将N’链接到N的后面
// 第二步：设置复制出来的节点的random， 比如N的random指向S，
// 		那么对应复制出来的N’是N的next执行的节点， 同样S’也是S的next指向的节点
// 第三步：将这个链表拆成两个链表，奇数位置上的节点为原始链表，偶数位置上的为复制链表



class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode *pNewNode;
        RandomListNode *pNewHead;
        RandomListNode *pNextNode;
        RandomListNode *pNode;
        if (pHead == NULL)
        {
            return NULL;
        }

        // 复制所有节点, 并将复制节点插入原节点之后
        pNode = pHead;
        while (pNode != NULL)
        {
            pNewNode = new RandomListNode(pNode->label);
            pNextNode = pNode->next;

            pNode->next = pNewNode;
            pNewNode->next = pNextNode;

            pNode = pNextNode;
        }

        // 连接复制节点的Random
        pNode = pHead;
        while (pNode != NULL)
        {
            if (pNode->random != NULL)
            {
                pNewNode = pNode->next;
                pNewNode->random = pNode->random->next;
            }
            pNode = pNode->next->next;
        }

        // 分离复制链表
        pNode = pHead;
        pNewHead = pHead->next;
        pNewNode = pNewHead;
        while (pNode != NULL)
        {
            pNode->next = pNewNode->next;
            if (pNode->next != NULL)
            {
                pNewNode->next = pNode->next->next;
            }

            pNode = pNode->next;
            pNewNode = pNewNode->next;
        }
        return pNewHead;
    }
};