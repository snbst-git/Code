class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int res = 0;
        for(int i = 1 ;i <= n;i++)
        {
            int t = i;
            while(t > 0)
            {
                if(t % 10  == 1)
                    res++;
                t = t / 10;
            }
        }
        return res;
    }
};