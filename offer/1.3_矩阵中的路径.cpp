/**
1.����Ǻܴ������� �ַ����ĸ����򰤸����� ������֮ǰ����ȦȦ����Ǵ� ̫������
2.����кü�����Ҫע��ĵط�
    a.һά������ֱ�Ӷ�ά�±꣬����Ӧ�ý��м򵥻���
    ��n*cols+m ע���ǳ����д�С�������еĴ�С
    b.ע������ģΪ1������£����str.empty()��ô�Ϳ���ֱ�ӷ���true�ˣ���Ϊ���޷�������һ���ƶ�
*/
class Solution {
public:
    int r,c;
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        //�ֱ���������visited����������ͬ�����߼���
        //Ҫд�Ӻ�����visited����
        vector<int> vis(rows*cols);
        vector<int> start;
        string strs=str;
        int i=0;
        bool res=false;
        r=rows,c=cols;
        //����Ҫ�ҵ����
        while(matrix[i]!=0){
            if(matrix[i]==str[0]) start.push_back(i);
            i++;
        }
        for(i=0;i<start.size()&&res==false;i++){
            //��3��4�� �о�/��  �о�Ī����
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
                //�ĸ�����
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
