/**
和昨天差不多，简单一点
有一个思维：
就是已经visted的就不需要再去测试了，因为肯定那个点的周边也相应测试过了
所以直接跳过就好了
而不需要考虑说我这边走的路径不一样到这个点是不是也要考虑
另外不要老是急着提交啊，变量都没改完就提交
*/
class Solution {
public:
    int hang,lie,lim;
    int movingCount(int threshold, int rows, int cols)
    {
        vector<int> vis(rows*cols);
        hang=rows,lie=cols;
        lim=threshold;
        judge(vis,0,0);
        int result=0;
        for(int i=0;i<vis.size();i++){
            if(vis[i]>0) result++;
        }
        return result;
    }

    int tonum(int a){
        int b=0;
        while(a>0){
            b+=(a%10);
            a/=10;
        }
        return b;
    }

    void judge(vector<int> &vis,int n,int m){
        if(vis[n*lie+m]==0&&(tonum(n)+tonum(m)<=lim)){
            vis[n*lie+m]=1;
            //四个方向
            if(n>0) judge(vis,n-1,m);
            if(n<hang-1) judge(vis,n+1,m);
            if(m>0) judge(vis,n,m-1);
            if(m<lie-1) judge(vis,n,m+1);
        }
    }

};
