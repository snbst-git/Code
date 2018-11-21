/**
取巧了吗？
和动态规划的是一个问题吗
*/
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size()==1) return array[0];
        int max=0,totalmax=-0x7fff;
        /**主要问题是判断中间有几个应该加起来，可能临时变小了但是后头会变大*/
        /*不想写二分法啊！*/
        for(int i=0;i<array.size();i++){//统计当前一片的最大值
            //不用太复杂
            if(max>0){//>=0继续统计
                max+=array[i];
            }
            else{//<=0 前面为负 没有贡献 丢弃
                max=array[i];
            }
            if(max>totalmax) totalmax=max;
        }
        return totalmax;
    }
};
