class Solution {
public:
	//题目要求稳定性，所以可以采用的排序算法有插入和归并
	//可以简单的用插入实现
    void reOrderArray(vector<int> &array) {
        vector<int> even;
        int odd = 0;
        for(int i = 0;i<array.size();i++)
        {
            if(array[i]%2 == 0)
            {
                even.push_back(array[i]);
            }
            else
            {
                array[odd++] = array[i];
            }
        }
        for(int i = odd,t = 0;i<array.size();i++)
        {
            array[i] = even[t++];
        }
    }
};