class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        int time = 1;
        int val = 0;
		//排序后遍历
        sort(numbers.begin(),numbers.end());
        for(int i = 0 ;i < len;i++)
        {
            if(i == 0)
            {
                val = numbers[i];
            }
            else
            {
                if(numbers[i] == numbers[i - 1])
                    time++;
                else
                {
                    val = numbers[i];
                    time = 1;
                }
            }
            if(time > len/2)
                return val;
        }
        return 0;
    }
};