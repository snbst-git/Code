class Solution {
public:
    int rectCover(int number) {
        if(number<=0) return 0;
        if(number==1) return 1;
        int a=1,b=1,c;
        for(int i=2;i<=number;i++){
            c=a+b;
            a=b,b=c;
        }
        return c;
    }
};

/**画图可知，实际还是有r[n]=r[n-1]+r[n-2]   r[n-1]对应横放一个，r[n-2]对应竖放两个
*还是斐波那契数列了
*一开始还以为是n*n的矩形，黑人得很
*现在对于不会重复的概念相对理解深刻一些了

*该题有一定侥幸心理？可以考虑一下更为复杂的问题，比如前面的跳台阶就应该考虑考虑变态跳台阶
*/
