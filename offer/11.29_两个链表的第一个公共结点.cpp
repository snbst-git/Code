/**
1.一开始都按照现在这个正确的思路开始写分析了
什么固定的差值啊
后面想了想怎么可能这么简单，肯定是要按照val排序的
然后开始构建map<int,int>  map[val]=order这样的……
2.然后发现其实就是简单的结点指针相同
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        //不是val相等，是指针值相等，所以是一个相等后面所有都相等
        if(pHead1==NULL||pHead2==NULL) return NULL;
        int cnt1=0,cnt2=0,i,j;
        ListNode *p=pHead1,*q=pHead2;
        while(p!=NULL){
            p=p->next;
            cnt1++;
        }
        while(q!=NULL){
            q=q->next;
            cnt2++;
        }
        p=pHead1,q=pHead2;
        if(cnt1>cnt2){
            while(cnt1>cnt2) cnt1--,p=p->next;
        }
        else {
            while(cnt2>cnt1) cnt2--,q=q->next;
        }
        while(p!=NULL&&q!=NULL){
            if(p==q) return p;
            p=p->next,q=q->next;
        }
        return p;
    }
};
