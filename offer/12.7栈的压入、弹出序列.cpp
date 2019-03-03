class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;//栈
        int p = 0;
        for(int i = 0;i<pushV.size();i++)
        {
            s.push(pushV[i]);
            while(!s.empty() && s.top() == popV[p])
            {
                s.pop();
                p++;
            }
        }
		//如果栈里有元素则说明没有弹出成功
        if(s.empty())
            return true;
        else
            return false;
    }
};