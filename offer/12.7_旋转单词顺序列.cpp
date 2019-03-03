/**
不熟悉string的使用方式
1.这里使用了find(' ',pos),表示从pos包括其本身开始搜索第一个
注意包括pos本身，所以如果是要找下一个应该是
pos=find(' ',pos+1)
2.过滤空格，所以last+1
3.string::npos 没有找到的结果，好像直接可以-1
测试代码如下：
	string test="abcde";
	cout << (string::npos==-1)<< endl;
	cout<<(string::npos>=0)<<endl;
	cout<<(string::npos<0)<<endl;
	cout<<(string::npos>test.size())<<endl;
输出1101
正常情况下是当做一个无符号大数来判定的（全1）
如果是和有符号数-1比较，那么-1会转化成无符号数进行比较，所以两者相等（补码一致）
*/
class Solution {
public:
    string ReverseSentence(string str) {
        //除了第一个和最后一个，其他以空格为分割
        if(str.empty()) return str;
        int last=0,pos=0;
        pos=str.find(' ',pos);
        if(pos==string::npos) return str;//包括为空
        vector<string> rcd;
        while (pos != string::npos) {
            rcd.push_back(str.substr(last, pos - last));
            last = pos+1;
            pos = str.find(' ', pos+1);
        }
	    rcd.push_back(str.substr(last));
        string result;
        for(int i=rcd.size()-1;i>0;i--){
            result=result+rcd[i]+" ";
        }
        result+=rcd[0];
        return result;
    }
};
