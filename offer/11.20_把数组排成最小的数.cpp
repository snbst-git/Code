/**
1.尽力了真的没想到还有这么骚的做法
2.熟悉stirng a<string b的比较模式，转换成ASCII码比较
对于长度不一样相当于补零来比较了
*/
#include <stdlib.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        //评判标准是什么？
        //相同长度就比较首位，不同长度
        //321323
        //贪心即可？选首字符最小的
        vector<string> numberstring;
        for(int i=0;i<numbers.size();i++){
            numberstring.push_back(std::to_string(numbers[i]));
        }
        sort(numberstring.begin(),numberstring.end(),cmp);
        string result;
        for(int i=0;i<numbers.size();i++){
           result+=numberstring[i];
        }
        return result;
    }
   static bool cmp(string &a,string &b){
       return a+b<b+a;//……神仙做题
       /*
       int i;
       for(i=0;i<a.size()&&i<b.size();i++){
           if(a[i]<b[i]) return 1;
           else if(a[i]>b[i]) return 0;
       }
       //前面部分都相同时，接下来看一下这边的剩余部分是大是小
       if(i<a.size()){//说明b到尾巴了
           return a[i]<a[0];
       }
       else return b[i]>b[0];//b[i]<b[0]那么就应该返回0*/
    }
};
