/**
1.注意是接着往后数，所以要继承上次的j
2.注意n<=0 m<=0为异常情况输出-1
*/
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        //每m个人一个循环，最后一个人唱歌拿走礼物
        //n里循环的第m人
        //每次n--，但是位置其实有所变化，如何记录？
        //根据一个算法计算应该取哪一个人，最后剩下一个人的时候就可以了
        if(n<=0||m<=0) return -1;
        vector<int> rcd(n);//记录原来的标号
        int i,j=0;
        for(i=0;i<n;i++) rcd[i]=i;//之后erase即可
        for(i=n;i>1;i--){//循环n-2+1=n-1次最后剩一个
            //计算i个人中排在第m个的标号 从0开始
            j=(j+m-1)%i;
            rcd.erase(rcd.begin()+j);
        }
        return rcd[0];
    }
};
