/**
11.9����
��������һ��ָ�룬ͬ�������ƶ�
������������ͳ��һ��n/����n��С�ĸ����ռ�
����ע���ж�Ҳ��Ҫ������Ӧ�޸�
---------
�ڴ����õĽⷨ
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {//������1������ôp,qͬ���ƶ�p���ƶ�0=1-1�� �����ڶ�������ôp�ƶ�1=2-1
        ListNode* p=pListHead,*q=pListHead;
        if(p==NULL||k==0) return NULL;//kΪunsigned ������<=0
        int count=0;
        //Ԥ���ƶ�
        while(p!=NULL&&count<k){//Ԥ���ƶ�����=k-1
            p=p->next;
            count++;//�Ѿ���count�����
        }
        if(count<k)return NULL;//û���ƹ�
        /**
        ��Ҫ��p->nextȥ�жϣ�ֱ����p�����ˣ�p��ǰָ��p->next��ô�Ϳ���ֱ���ƶ�k��
        */
        while(p!=NULL) p=p->next,q=q->next;
        return q;
    }
};


class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* p=pListHead;
        //ע��unsigned
        vector<ListNode*> stack;
        while(p!=NULL){
            stack.push_back(p);
            p=p->next;
        }
        if(k==0||k>stack.size()) return NULL;//throw new exception("Invalid Parameter k.");
        return stack[stack.size()-k];//eg size=5,������4��Ϊ��2���±�1 5-4
    }
};
