/**
小动作好多
1.k不能超大，也不能过小
2.好几个地方的input[i]写成了result[i]
3.能否不要每次都遍历找位置
二分？
***/
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int count=0;
        vector<int> result;
        if(k>0&&k<=input.size()){//还有k超大的情况
            int i=0;
            for(;i<input.size();i++){
                //不排序，直接过一遍，有更小的就插入到前面
                int flag=result.size()<k;
                if(result.size()>=k){
                    if(input[i]<result[k-1]){
                        result.erase(result.begin()+k-1);//删除尾元素
                        flag=1;
                    }
                }
                if(flag){
                    int j=0;
                    while(j<result.size()&&input[i]>result[j]) j++;//到某个的前面
                    result.insert(result.begin()+j,input[i]);
                }
            }
        }
        return result;
    }
};
