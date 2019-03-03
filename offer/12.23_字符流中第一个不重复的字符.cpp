/**
做过一次吧，map大法好
可以在Insert阶段就完成统计，实现方式应该是插入一个字符就调用一次
另外也可以不用map，用一个数组即可
*/

class Solution
{
public:
    string str;
  //Insert one char from stringstream
    void Insert(char ch)
    {
         str+=ch;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        map<char,int> rec;
        int i,j;
        for(i=0;i<str.size();i++){
            rec[str[i]]++;
        }
        for(i=0;i<str.size();i++){
            if(rec[str[i]]==1) return str[i];
        }
        return '#';
    }

};
