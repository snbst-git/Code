/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        //可以考虑从后到前存入一个数组，但是同样不知道数组大小的问题
        //可以考虑先统计大小吧
        int num=0;
        struct ListNode* p=head;
        while(p!=NULL){
            num++,p=p->next;
        }
        vector<int> result(num);
        p=head;https://m.733.so/mh/26798/443602.html?page=14
        while(p!=NULL){
            result[--num]=p->val,p=p->next;
        }
        return result;
    }
};

class Solution2 {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        struct ListNode* p=head;
        std::stack<ListNode*> nodes;
        vector <int> result;
        while(p!=NULL){
            nodes.push(p);
            p=p->next;
        }
        while(!nodes.empty()){
            p=nodes.top();
            result.push_back(p->val);
            nodes.pop();
        }
        return result;
    }
};
