class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int max = -2^31;
        int val = 0;//累计和
        for(int i = 0;i<array.size();i++)
        {
			//当array[i]为负数并且大于之前的累计和时，把之前的累计和丢弃
			//当array[i]为正数并且之前累计和为负数时，把之前的累计和丢弃
            if(array[i] < 0 && val < array[i] || 0 < array[i] && val < 0)
                val = array[i];
            else
                val += array[i];
            if(val > max)
                max = val;
        }
        return max;
    }
};