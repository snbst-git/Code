/**
问题简单，但是要考虑的事情比较多
1.首先是基础的substr的参数怎么选
2.接下来是n的特殊情况，过小<=0 过大>size()
3.还有str为空字符串的问题，这个一定不要忘了！
参数可能为空这个是首先要考虑的事情，还是看见提示说有除以0的运算才想起
*/
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.size()>0){
            if(n>str.size()) n%=str.size();
            if(n>0){//6 2
                string result=str.substr(n);//0，4
                result+=str.substr(0,n);
                return result;
            }
        }
        return str;
    }
};
