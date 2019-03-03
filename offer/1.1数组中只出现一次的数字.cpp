class Solution {
public:
	//判断data的bit位是不是1
    bool judge(int bit,int data)
    {
        int i = 1<<(bit-1);
        if((i & data) == i)
            return true;
        else
            return false;
    }
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        vector<int> arr1,arr2;//将数组分成两个，每个数组里含有一个出现一次的数字
        int res = 0;
        for(auto &a : data)
            res ^= a;
        int bit = 1;
        while((res & 1) != 1)
        {
            res = res >> 1;
            bit++;
        }
        for(auto a : data)
            if(judge(bit,a))
                arr1.push_back(a);
            else
                arr2.push_back(a);
        res = 0;
        for(auto &a : arr1)
            res ^= a;
        *num1 = res;
        res = 0;
        for(auto a : arr2)
            res ^= a;
        *num2 = res;
    }
};