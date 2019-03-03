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
        ListNode *temp1 = pHead1,*temp2 = pHead2;
        int len1 = 0,len2 = 0;
        while(temp1)
        {
            len1++;
            temp1 = temp1->next;
        }
        while(temp2)
        {
            len2++;
            temp2 = temp2->next;
        }
		//找出哪个链表长，让长的链表的头结点向前移动|len1-len2|
        if(len1 > len2)
        {
            int dis = len1-len2;
            while(dis--)
            {
                pHead1 = pHead1->next;
            }
        }
        else
        {
            int dis = len2-len1;
            while(dis--)
            {
                pHead2 = pHead2->next;
            }
        }
        while(1)
        {
            if(pHead1 == pHead2)
                return pHead1;
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
    }
};