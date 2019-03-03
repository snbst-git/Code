class Solution {
public:
    int h[256] = {0};	//hash table
    int FirstNotRepeatingChar(string str) {
        if(str.empty())
            return -1;
        int min = 0;
        for(int i = 0;i < str.size(); i++)
        {
            int t = str[i];
            h[t]++;
			//find it‘s vlaue ?= 1
            while(h[str[min]] > 1 && min < str.size())
                min++;            
        }
        if(min == str.size())
            return -1;
        else
            return min;
    }
};