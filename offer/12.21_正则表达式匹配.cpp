class Solution {
public:
    //主要出问题的例子 aaa和a*a 不知道*到底要匹配几个
    bool match(char* str, char* pattern)
    {
        if(*str==0&&*pattern==0) return true;
        if(*str!=0&&*pattern==0) return false;//还有剩的字符串未能匹配
        if(*(pattern+1)=='*'){
            //下一个为* 接下来数量就有几种可能了
            ///不能单纯的使用*patn=='.'，因为*str=0是不允许使用这个匹配的
            if(*str==*pattern||*str!=0&&*pattern=='.'){
                //不过可能就匹配这一个，pattern往后移动两个
                //可能pattern还要匹配多个str字符，所以pattern不移动 str+1
                return match(str,pattern+2)||match(str+1,pattern);
                //str正确：只匹配1个的话，str往后移动一个，ptn不动，即使不匹配之后也可以当做0个跳过，搜，所以str是正确的
                //str+1错误：a a*a 只需要不移动str把a*当做0个就可以匹配成功，但是如果移动了就变成0和a了
                //return match(str+1,pattern+2)||match(str+1,pattern);
            }
            else return match(str,pattern+2);//不相等，往后移动2 *代表0个
        }
        else{//下一个不是*
            ///不能单纯的使用*patn=='.'，因为*str=0是不允许使用这个匹配的
            if(*str==*pattern||*str!=0&&*pattern=='.') return match(str+1,pattern+1);//各自往后移动1
            else return false;
        }
    }

    /*
    bool match(char* str, char* pattern)
    {
        int i=0,j=0,lens=strlen(str),lenp=strlen(pattern);
        while(i<lens&&j<lenp){//到-1都是有效的
            if(str[i]==pattern[j]){
                i++,j++;
            }
            else if(pattern[j]=='.') i++,j++;//任意匹配一个
            else if(pattern[j]=='*'){//*的多个情况
                if(str[i]==pattern[j-1]||pattern[j-1]=='.'){
                    i++;//冗余 比如aaa 和a*c  a a匹配 接下来 a *由于a和*的上一个a相等 匹配成功
                }
                else if(str[i-1]==pattern[j-1]||pattern[j-1]=='.') j++;//相当于*代表只有一个
                else return false;
            }
            else if(pattern[j+1]=='*') j+=2;//0个匹配
            else return false;
        }
        if(i<lens) return false;
        else while(j<lenp){


            if(pattern[j]=='*') j++;//1个前面的
            else if(pattern[j+1]=='*') j+=2;
            else return false;
        }
        return true;
    }*/
};
