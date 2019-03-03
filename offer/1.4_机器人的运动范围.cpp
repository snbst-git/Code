/**
�������࣬��һ��
��һ��˼ά��
�����Ѿ�visted�ľͲ���Ҫ��ȥ�����ˣ���Ϊ�϶��Ǹ�����ܱ�Ҳ��Ӧ���Թ���
����ֱ�������ͺ���
������Ҫ����˵������ߵ�·����һ����������ǲ���ҲҪ����
���ⲻҪ���Ǽ����ύ����������û������ύ
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
            //�ĸ�����
            if(n>0) judge(vis,n-1,m);
            if(n<hang-1) judge(vis,n+1,m);
            if(m>0) judge(vis,n,m-1);
            if(m<lie-1) judge(vis,n,m+1);
        }
    }

};
