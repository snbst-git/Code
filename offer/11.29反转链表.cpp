//方法一：分治时间复杂度O(n)
class Solution {
public:
    void Reverse(ListNode* beg,ListNode* end)
    {
        if(beg == end)
            return;
        if(beg->next == end)
        {
            end->next = beg;
            return;
        }
        ListNode* pslow = beg,*pfast = beg;
        //遍历一遍找到中点，时间复杂度O(n)
        while(pfast != end && pslow != end)
        {
            pfast = pfast->next;
            if(pfast != end)
                pfast = pfast->next;
            pslow = pslow->next;
        }
        ListNode* pslowNext = pslow->next;
        Reverse(beg,pslow);
        Reverse(pslowNext,end);   
        pslowNext->next = pslow;
    }
    //利用分治思想，总时间复杂度O(n)
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL)
            return NULL;
        ListNode* end = pHead;
        while(end ->next != NULL)
        {
            end = end->next;
        }
        Reverse(pHead,end);
        pHead->next = NULL;
        return end;
    }
};
//方法二：遍历时间复杂度O(n)
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pre = NULL;
        ListNode* next = NULL;
        while(pHead != NULL)
        {
            next = pHead->next;
            pHead->next = pre;
            pre = pHead;
            pHead = next;
        }
        return pre;
    }
};
