/**
最近降智有点厉害……
1.纠结了好久path要不要引用
一开始应该是在同一句子中使用了
…path…||…path… 有毫无意义的返回值设定
导致蜜汁只输出一边的 先谁就谁，估计就是path出了问题，由于没有去调试，所以说不清楚
2.后面还是构建一下实例自己完成一下比较好
思路上没有问题但是不调试就看不出来到底是什么地方的问题
***/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> result;
        vector<int> path;
        if(root==NULL) return result;
        //递归调用即可
        judge(result,path,root,expectNumber);
        sort(result.begin(),result.end(),cmp);
        //std::sort(result.begin(),result.end(),cmp);
        return result;
    }
    /**void judge(vector<vector<int> > &result,vector<int> path,TreeNode* root,int exp){ 如果不引用path*/
    void judge(vector<vector<int> > &result,vector<int> &path,TreeNode* root,int exp){
        //path从上面继承生成一个临时对象，不用pop
        if(root!=NULL){
            if(root->val<=exp){//root->val<=exp
                path.push_back(root->val);
                exp-=root->val;
                if(exp==0&&root->left==NULL&&root->right==NULL){//左右为NULL各自push了一次
                   result.push_back(path);
                }
                else{
                    judge(result,path,root->left,exp);
                    judge(result,path,root->right,exp);
                }
                path.pop_back();
                /**如果上面用path，不引用那么可以省略path.pop_back();**/
            }
        }//root==NULL 若为空节点则可以
    }

    static bool cmp(vector<int> &a,vector<int> &b){
        return a.size()>b.size();
    }
};
