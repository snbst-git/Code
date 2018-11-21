/**
1.为什么前面会多一堆0
2.有没有更好的方法，看一下冒泡的解析
3.太困了明天继续
*/
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        //可以考虑Merge
        int i=0;
        vector<int> result(array.size());
        for(i=0;i<array.size();i++){
            if(array[i]%2) result.push_back(array[i]);
        }
        for(i=0;i<array.size();i++){
            if(array[i]%2==0) result.push_back(array[i]);
        }
        for(i=0;i<array.size();i++){
            array[i]=result[i+array.size()];
        }
    }
};
