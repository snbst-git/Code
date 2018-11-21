/**
二叉搜索树得熟悉一下
今天脑壳是乱的
1.考虑一下是从前到后搜索还是从后往前搜索
这里后序那么最后一个输出的是之间的根节点
所以小 大 中的顺序，显然应该选取最后一个为中，进行简单的大小比较
2.考虑循环还是递归
这里显然用递归比较好，因为子树也需要判断
对于树可以考虑一下递归的方法
3.想清楚边界到底是哪个
比如这里的a[k]
***/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size()==0) return false;//空树？
        return func(sequence,0,sequence.size()-1);
    }

    bool func(vector<int> a,int i,int j){
        //搜索i~j序列是否为
        if(i>=j) return true;
        int k=j;
        while(k>i&&a[j]<a[k-1]) k--;//从中出发 找到大小的边界k
        //a[k]>a[k-1] k为右
        //a[k-1]为左
        int r;
        //a[i~k-1]为左
        //a[k~j-1]为右
        //a[j]为中
        for(r=i;r<k;r++){
            if(a[r]>a[j]) return false;
        }
        //右边已经确认大于a[j]了无需再判断
        //前面是以a[j]为判断依据，接下来还要继续判断
        return func(a,i,k-1)&&func(a,k,j-1);
    }
};
