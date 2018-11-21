/**
11.9
不需要重新创建结点，之前是在纠结什么好像
----------
做得挺蠢的，不知道有没有更有趣的解法
算法拖太久了，今天先拉一下进度，准备做vj的题目
今晚上再来看书，总结一下前几天的内容
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
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL) return NULL;
        ListNode *p=pHead,*q,plast=NULL;
        while(p!=NULL){
            q=p->next;
            p->next=plast;
            plast=p;
            p=q;
        }
        return plast;
    }
};



class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL) return NULL;
        ListNode *p=pHead,*q=NULL,*newhead,*plast;
        while(p!=NULL){
            newhead=new ListNode(p->val);
            newhead->next=q;
            q=newhead;
            plast=p;
            p=p->next;
            delete plast;
        }
        return newhead;
    }
};
