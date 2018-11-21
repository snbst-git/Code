/**11.9
感觉做得有点点乱
应该还有可以整合的地方
**/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size()!=popV.size()) return false;
        int size=pushV.size();
        if(size<=0) return true;//应该没有特殊情况
        if(size==1){
            if(pushV.back()==popV.back())return true;
            else return false;
        }
        vector<int> temp;
        int i=0,j=0;
        while(j<size){//元素还没完
            if(pushV[j]!=popV[i]) temp.push_back(pushV[j++]);//i不动只到匹配
            else j++,i++;
        }//到j==size结束,全部push进去了
        while(i<size&&temp.size()){
            if(temp.back()==popV[i]) temp.pop_back(),i++;
            else break;
        }
        if(temp.empty()) return true;
        return false;
    }
};
