/**
1.对于这种动态的问题有点恐惧
没有发现其队列的规律
2.合理利用了同一个队列
使用不同的下标来分别记录移动
3.没有考虑到2*3=3*2的重叠，进而应该同时移动2、3的下标的情况
考虑不完全，经过调试发现了该问题

*/
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        //应该没有静态的规律，是动态的
        //采取队列法
        if(index<7) return index;
        vector<int> result(index);
        result[0]=1;
        //对于没有选中的2/3/5应该保留其基数，因为还一次都没选，不能都用上一次的Num
        int a,b,c,newnum;
        a=b=c=0;
        for(int i=1;i<index;i++){
            newnum=min(result[a]*2,result[b]*3,result[c]*5);
            if (newnum == result[a] * 2) a++;
            if (newnum == result[b] * 3) b++;
            if (newnum == result[c] * 5) c++;
            /**虽然不可能有重复等于现象 235都是质数
            但是可以有 2*3=3*2所以都要++
            else if (newnum == result[b] * 3) b++;
            else c++;*/
            result[i]=newnum;
        }
        return newnum;
    }
    int min(int a,int b,int c){
        return a<c?(a<b?a:b):(b<c?b:c);
    }
};
