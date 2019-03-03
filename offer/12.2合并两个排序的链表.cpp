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
        if(pHead1 == NULL)
            return pHead2;
        else if(pHead2 == NULL)
            return pHead1;
        ListNode* res;
        ListNode* temp;
		//初始化处理
        if(pHead2->val < pHead1->val)
        {
            res = pHead2;
            pHead2 = pHead2->next;
        }
        else
        {
            res = pHead1;
            pHead1 = pHead1->next;
        }
        temp = res;
		//循环判断
        while(pHead1 != NULL && pHead2 != NULL)
        {
            if(pHead2->val < pHead1->val)
            {
                temp->next = pHead2;
                pHead2 = pHead2->next;
            }
            else
            {
                temp->next = pHead1;
                pHead1 = pHead1->next;
            } 
            temp = temp->next;
        }
		//循环结束后判断
        if(pHead1 == NULL)
        {
            temp->next = pHead2;
        }
        else
        {
            temp->next = pHead1;
        }
        return res;
    }
};