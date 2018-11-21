/**
11.9更新
可以用另一个指针，同步往后移动
所以无需首先统计一次n/申请n大小的辅助空间
但是注意判断也需要进行相应修改
---------
期待更好的解法
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {//倒数第1个，那么p,q同步移动p先移动0=1-1次 倒数第二个，那么p移动1=2-1
        ListNode* p=pListHead,*q=pListHead;
        if(p==NULL||k==0) return NULL;//k为unsigned 不可能<=0
        int count=0;
        //预先移动
        while(p!=NULL&&count<k){//预先移动次数=k-1
            p=p->next;
            count++;//已经有count个结点
        }
        if(count<k)return NULL;//没有移够
        /**
        不要用p->next去判断，直接用p就是了，p提前指向p->next那么就可以直接移动k次
        */
        while(p!=NULL) p=p->next,q=q->next;
        return q;
    }
};


class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* p=pListHead;
        //注意unsigned
        vector<ListNode*> stack;
        while(p!=NULL){
            stack.push_back(p);
            p=p->next;
        }
        if(k==0||k>stack.size()) return NULL;//throw new exception("Invalid Parameter k.");
        return stack[stack.size()-k];//eg size=5,倒数第4就为第2，下标1 5-4
    }
};
