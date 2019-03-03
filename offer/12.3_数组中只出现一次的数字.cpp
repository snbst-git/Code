/**
水水水
看有没有巧解
*/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        //错误的情况？
        map<int,int> rec;
        int i;
        for(i=0;i<data.size();i++){
            rec[data[i]]++;
        }
        int cnt=0;
        for(i=0;i<data.size();i++){
            if(rec[data[i]]==1){
                if(cnt==0) *num1=data[i]，cnt++;
                else{
                    *num2=data[i];
                    break;
                }
            }
        }
    }
};
