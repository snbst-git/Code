/**
map吹爆
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        //地址应该是重合的 不是val重合就是了
        map<ListNode *,int>rec;
        ListNode* p=pHead;
        while(p!=NULL){
            rec[p]++;//0->1 重复则1->2
            if(rec[p]>1) return p;
            p=p->next;
        }
        return NULL;
    }
};
