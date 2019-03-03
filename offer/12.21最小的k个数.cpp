class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.empty() || k <=0 || k>input.size())
            return res;
		//维护一个大顶堆
        priority_queue <int> dui;
        int num = 0;
        for(int i = 0;i<input.size();i++)
        {
            if(num < k)
            {
                dui.push(input[i]);
                num++;
            }
            else
            {
                if(input[i] < dui.top())
                {
                    dui.pop();
                    dui.push(input[i]);
                }
            }
        }
        while(!dui.empty())
        {
            res.push_back(dui.top());
            dui.pop();
        }
        return res;
    }
};