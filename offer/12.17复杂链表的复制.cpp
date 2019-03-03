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
    //时间复杂度O(n)，空间复杂度O(1)
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        RandomListNode* pt = pHead;
        //new新结点，每个新结点插入在之前结点的后一个结点
        while(pt != NULL)
        {
            RandomListNode* temp = new RandomListNode(pt->label);
            temp->next = pt->next;
            pt->next = temp;
            pt = temp->next;
        }
        pt = pHead;
        //如果新结点的上一个结点的随机结点不是空，那么新结点的随机结点就是上一个结点随机结点的Next
        while(pt != NULL)
        {
            RandomListNode* temp = pt->next;
            if(pt->random != NULL)
                temp->random = pt->random->next;
            else
                temp->random = NULL;
            pt = temp->next;
        }
        RandomListNode* head = pHead->next;
        RandomListNode* t1 = head;
        RandomListNode* t2 = pHead;
        //偶数个结点就是新复制出来的结点
        while(t2 != NULL)
        {
            t2->next = t1->next;
            t2 = t2->next;
            if(t2 != NULL)
            {
                t1->next = t2->next;
                t1 = t1->next;
            }
        }
        return head;
    }
};
