/**
map吹爆
记得考虑第一个结点就是重复的情况
另外理解题意是要全部删除，不是只留一个
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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* p=pHead,*last;
        map<int,int> rec;
        while(p!=NULL){
            rec[p->val]++;
            p=p->next;
        }
        p=pHead;
        //有可能是首个结点
        while(p!=NULL&&rec[p->val]>1){
            //决定头结点
            p=p->next;
        }
        pHead=p,last=p;//新头
        while(p!=NULL){
            if(rec[p->val]>1){
                last->next=p->next;//跳过p
                //不更新last 可能还是重复的
                p=p->next;
            }
            else{//不是重复结点，更新
                last=p;
                p=p->next;
            }
        }
        return pHead;
    }
};
