class Solution {
public:
	vector<int> ugly = {1};
	int min (int a,int b,int c)
	{
		if(a <= b && a <= c) 
			return a;
		else if(b <= a && b <= c) 
			return b;
		else
			return c;
	}
    int GetUglyNumber_Solution(int index) {
        if(index <= 0)
            return 0;
    	int max = 1;
    	int count = 1;
		int two = 0,three = 0,five = 0;
		//将所有丑数储存起来，判断下一个丑数
    	while(count < index)
    	{
			while(ugly[two] * 2 <= max)
				two++;
			while(ugly[three] * 3 <= max)
				three++;	
			while(ugly[five] * 5 <= max)
				five++;
			count++;
			//取最小的一个作为下一个丑数
			max = min(ugly[two] * 2,ugly[three] * 3,ugly[five] * 5);
			ugly.push_back(max);
		}
		return max;
    }
};