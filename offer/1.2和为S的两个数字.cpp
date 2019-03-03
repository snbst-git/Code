class Solution {
public:
	//可以参考Leetcode上的twosum解法
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        int length = array.size();
        int start = 0;
        int end = length - 1;
        int mysum = array[start] + array[end];
		//题目貌似没有说清楚，如果不存在应该返回空，所以循环判断条件不能是mysum != sum
        while (start < end)
        {
            if (mysum > sum)
                end--;
            else if(mysum < sum)
                start++;
            else
            {
                res.push_back(array[start]);
                res.push_back(array[end]);
                break;
            }
            mysum = array[start] + array[end]; 
        }
        return res;
    }
};