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
		//判断链表是否是空链表和k的值！！
        if(pListHead == NULL || k == 0)
            return NULL;
        stack<ListNode*> s;
        ListNode* phead = pListHead;
        int count = 0;
        while(phead != NULL)
        {
            s.push(phead);
            phead = phead->next;
            count++;
        }
		//判断k是否越界！！
        if(count < k)
            return NULL;
        for(unsigned int i = 1;i < k;i++)
        {
            s.pop();
        }
        return s.top();
    }
};