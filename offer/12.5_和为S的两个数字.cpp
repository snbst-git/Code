/**
1.和昨天的基本一样，更为简单
2.注意考虑没有符合的情况
*/
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int low=0,high=array.size()-1;
        int cur,prd=0xffffff;
        vector<int> result(2);
        while(low<high){
            cur=array[low]+array[high];
            if(cur==sum){
                if(prd>array[low]*array[high]){
                    prd=array[low]*array[high];
                    result[0]=array[low];
                    result[1]=array[high];
                }
                low++;
            }
            else if(cur<sum) low++;
            else high--;//大于 high偏大
        }
        if(prd==0xffffff) result.clear();
        return result;
    }
};
