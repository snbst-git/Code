class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        if(A.size()<=1) return A;
        vector<int> B,front(A),back(A);
        //没有i项，i从0到n-1，为下标
        int i;
        //front[0]就是本身
        for(i=1;i<A.size();i++){
            front[i]=front[i-1]*front[i];//本来front[i]是本位元素，后面变成累计乘积
            back[A.size()-1-i]=back[A.size()-i]*back[A.size()-1-i];
            //如back[n-1-1]=back[n-1]*back[n-2]
        }
        //边界back[0]=back[1]*back[0]
        //已经是大于等于2个元素了，可以分开
        B.push_back(back[1]);
        for(i=1;i<A.size()-1;i++){
            //front[i]为下标从0~i back为下标从i~n-1
            B.push_back(front[i-1]*back[i+1]);
        }
        B.push_back(front[i-1]);
        return B;
    }
};
