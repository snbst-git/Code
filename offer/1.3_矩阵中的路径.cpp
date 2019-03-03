/**
1.大概是很蠢的做法 又分了四个方向挨个讨论 想起了之前矩阵圈圈求和那次 太复杂了
2.这次有好几个需要注意的地方
    a.一维矩阵不能直接二维下标，而是应该进行简单换算
    即n*cols+m 注意是乘以列大小！不是行的大小
    b.注意矩阵规模为1的情况下，如果str.empty()那么就可以直接返回true了，因为它无法进行下一步移动
*/
class Solution {
public:
    int r,c;
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        //分别建立独立的visited副本，往不同方向走即可
        //要写子函数带visited副本
        vector<int> vis(rows*cols);
        vector<int> start;
        string strs=str;
        int i=0;
        bool res=false;
        r=rows,c=cols;
        //首先要找到起点
        while(matrix[i]!=0){
            if(matrix[i]==str[0]) start.push_back(i);
            i++;
        }
        for(i=0;i<start.size()&&res==false;i++){
            //如3行4列 行就/列  列就莫列数
            res=res||judge(matrix,strs,vis,start[i]/c,start[i]%c);
        }
        return res;
    }

    bool judge(char *mat,string str,vector<int> vis,int n,int m){
        if(!str.empty()){
            if(vis[n*c+m]==0&&mat[n*c+m]==str[0]){
                vis[n*c+m]=1;
                str.erase(0,1);
                if (str.empty()) return true;
                bool res=false;
                //四个方向
                if(n>0) res=res||judge(mat,str,vis,n-1,m);
                if(res==false&&n<r-1) res=res||judge(mat,str,vis,n+1,m);
                if(res==false&&m>0) res=res||judge(mat,str,vis,n,m-1);
                if(res==false&&m<c-1) res=res||judge(mat,str,vis,n,m+1);
                return res;
            }
            else return false;
        }
        return true;
    }

};
