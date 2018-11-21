/**
1.这个题的random随机性决定了不应该使用递归，因为可能会有环的存在
2.这个题有很多需要进行NULL判断的地方，空指针判断！
p->random
p=p->next后的p
不要轻易指向next，注意进行判断
***/
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
        if(pHead==NULL) return NULL;
        /*这样做会死循环
        newhead=new RandomListNode(pHead->label);
        newhead->next=Clone(pHead->next);
        newhead->random=Clone(pHead->random);*/
        //还是用网上的思路吧……挺巧的，就构成了前后关系
        RandomListNode *p=pHead,*q,*newhead;
        while(p){
            q=new RandomListNode(p->label);//复制A得到一个结点A'
            //插入到AB中间 得到A A' B
            q->next=p->next;
            p->next=q;
            p=q->next;//A->B
        }
        p=pHead,q=p->next;
        while(p){
            if(p->random) q->random=p->random->next;//A--C 那么A'--C'
            /**错误点1 没有判断p->random==NULL***/
            //否则保持为NULL
            p=q->next;//A->B
            if(p) q=p->next;//A'->B'
            /**错误点2 没有判断p==NULL***/
        }
        p=pHead,q=p->next;
        newhead=q;
        while(p){
            //从A A' B中剥离A' 并串联A' B'
            p->next=q->next;//恢复本来的next
            p=p->next;//移动到下一个结点
            if(p) q->next=p->next;
            /**错误点3 没有判断p==NULL***/
            q=q->next;//移动到下一个复制结点
        }
        return newhead;
    }
};
