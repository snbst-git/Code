/**
感觉做这种题一般都不太灵光，总是要出点错误才知道有什么问题
这次遇到的有：
1.忘了i++导致死循环之类的判断问题
2.忘了考虑"12e"这样的特殊情况，还是标准用例……
3.有点做一步考虑一步的感觉，没有提前构思好
*/

class Solution {
public:
    bool isNumeric(char* string)
    {
        //不需要递归，直接从头到尾扫描即可
        int len=strlen(string),i=0,numofp=0,numofe=0;
        if(len==0) return false;
        if(string[i]=='+'||string[i]=='-') i++;
        while(i<len){
            if(string[i]=='.'){
                ///只顾着标记忘了i++了
                if(numofp==0&&numofe==0) numofp++,i++;//如果已经出现了e那么后面应该是整数不能是小数
                else return false;//两个以上的.
            }
            else if(string[i]=='e'||string[i]=='E'){
                if(numofe==0) numofe++,i++;
                else return false;
            }
            else if(string[i]=='-'||string[i]=='+'){
                if(string[i-1]=='E'||string[i-1]=='e') i++;//E-16这样的表达
                else return false;///普通的冗余-/+
            }
            else if(string[i]>='0'&&string[i]<='9') i++;//为数字
            else return false;//不合规字符如'a'
        }
        if(string[i-1]=='e'||string[i-1]=='E') return false;//空有e
        return true;
    }

};
