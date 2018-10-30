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
	//用一个栈储存遍历得到的数据，时空复杂度都是O(N)
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        stack<int> temp;
        ListNode* p = head;
        while(p)
        {
            temp.push(p->val);
            p = p->next;
        }
        while(!temp.empty())
        {
             res.push_back(temp.top());
             temp.pop();
        }
        return res;
    }
};