/**
投机取巧了
应该有不用排序的方法，之后看看
***/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        //先sort一下还是直接上，不过这样得申请一个辅助数组
        if(numbers.size()==0) return 0;
        int count=1;
        int maxcount=1,max=numbers[0];
        sort(numbers.begin(),numbers.end());
        for(int i=1;i<numbers.size();i++){
            if(numbers[i]==numbers[i-1]) count++;
            else{
                if(maxcount<count){
                    maxcount=count;
                    max=numbers[i-1];
                    count=1;
                }
            }
        }
        if(maxcount>numbers.size()/2) return max;
        else return 0;
    }
};
