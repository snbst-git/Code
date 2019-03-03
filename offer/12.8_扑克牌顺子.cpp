/**
考虑能否不排序就计算
1.有对子不可以使用
2.可能不止跨越一个，可能要跨越两个，注意count-=的幅度
*/
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size()==0) return false;
        sort(numbers.begin(),numbers.end());
        int count=0;
        for(int i=0;i<numbers.size();i++){
            if(numbers[i]==0) count++;
            else{
                if(i>0&&numbers[i-1]!=0){//为0相当于为首个，不存在顺不顺的考虑
                    if(numbers[i]==numbers[i-1]) return false;
                    if(numbers[i]!=numbers[i-1]+1)  count-=(numbers[i]-numbers[i-1]-1);
                }
            }
        }
        if(count>=0) return true;
        return false;
    }
};
