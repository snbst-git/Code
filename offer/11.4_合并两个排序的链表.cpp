/**
11.9
代码复杂度方面的优化可以写成一个递归的
------
感觉有点慢其他还好
看看有没有更快的
*/
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
        if(pHead1==NULL) return pHead2;
        if(pHead2==NULL) return pHead1;
        ListNode *p=pHead1,*q=pHead2,*newlist;
        if(p->val<q->val){
            newlist=p;
            newlist->next=Merge(p->next,q);
        }
        else{
            newlist=q;
            newlist->next=Merge(p,q->next);
        }
        return newlist;
    }
};


class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL) return pHead2;
        if(pHead2==NULL) return pHead1;
        ListNode *p=pHead1,*q=pHead2,*newlist;
        if(p->val<q->val){
            newlist=p;
            p=p->next;
        }
        else{
            newlist=q;
            q=q->next;
        }
        while(p!=NULL&&q!=NULL){//类似于Merge
            if(p->val<q->val){
                newlist->next=p;//newlist相当于上一辈
                newlist=p;
                p=p->next;
            }
            else{
                newlist->next=q;
                newlist=q;
                q=q->next;
            }
        }
        if(p==NULL){
            newlist->next=q;
        }
        else{
            newlist->next=p;
        }
        return (pHead1->val<pHead2->val)?pHead1:pHead2;
    }
};
