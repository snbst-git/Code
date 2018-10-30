class Solution {
public:
    int Fibonacci(int n) {
        if(n==0) return 0;
        if(n==1||n==2) return 1;
        int last=1,result=1,newresult;//0 1 1 2 3 5 8
        for(int i=3;i<=n;i++){
            newresult=result+last;
            last=result;
            result=newresult;//比较简单可以不用使用动态规划，但是如果比较复杂就可以使用动态规划
        }//另外递归的实现也比较有意思
        return result;
    }
};
